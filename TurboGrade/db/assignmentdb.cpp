#include "assignmentdb.h"

/**
 * @brief Destructor
 */

AssignmentDB::~AssignmentDB() {

}

/**
 * @brief AssignmentDB::add Insert a row to the database
 * @param name the name of the assignment (ex. Drawing Shapes)
 * @param objective the objective of the assignment (ex. Introducing students to Processing)
 * @param full_grade true if we start grading with a full grade, false if we start at 0
 * @return true if the query succeded
 */
int AssignmentDB::add(const QString name, const QString objective, bool full_grade) {

    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("INSERT INTO assignment (id, name, objective, full_grade) "
                  "VALUES (NULL, ?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(objective);
    query.addBindValue(full_grade);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'assignment' table" << endl << "SQL ERROR: " << query.lastError();
        query.finish();
        return -1;
    }
    int last_insert_id = query.lastInsertId().toInt();
    query.finish();
    db.commit();

    return last_insert_id;
}

/**
 * @brief AssignmentDB::remove remove the assignment from the assignment table
 * @param assignment_id the assignment's id
 */
void AssignmentDB::remove(int assignment_id){
    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("DELETE FROM assignment "
                    "WHERE id = ?;");
    query.addBindValue(assignment_id);

    if (!query.exec()) {
        qDebug() << "Failed to delete from 'assignment' table" << endl << "SQL ERROR: " << query.lastError();
        db.commit();
        return;
    }

    query.finish();

    db.commit();
}

/**
 * @brief AssignmentDB::update updates the row given by assignment_id
 * @param name the new name
 * @param objective the new object
 * @param full_grade the new starting grade variable (True if starting max score)
 * @param assignment_id the assignment id in the table
 */
int AssignmentDB::update(const QString name, const QString objective, bool full_grade, int assignment_id){
    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("UPDATE assignment "
                  "SET name = :name, objective = :objective, full_grade = :full_grade "
                  "WHERE id = :id;");

    query.bindValue(":name", name);
    query.bindValue(":objective", objective);
    query.bindValue(":full_grade", full_grade);
    query.bindValue(":id", assignment_id);

    if (!query.exec()) {
        qDebug() << "Failed to update assignment "
                 << query.lastQuery() << endl
                 << "SQL ERROR: " << query.lastError();
        return -1;
    }

    query.finish();
    db.commit();

    int last_id = query.lastInsertId().toInt();
    return last_id;
}


/**
 * @brief AssignmentDB::link Links an assignment to a section
 * @param section_id the id of the section where the assignment will be linked
 * @param assignment_id the id of the assignment to be linked
 * @return true if the query succeded
 */
bool AssignmentDB::link(int assignment_id,
                        int section_id) {

    db.transaction();
    QSqlQuery query(db);


    query.prepare("INSERT INTO assignment_section (id, assignment, section) "
                  "VALUES (NULL, ?, ?)");
    query.addBindValue(assignment_id);
    query.addBindValue(section_id);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'assignment_section' table" << endl << "SQL ERROR: " << query.lastError();
        query.finish();
        db.commit();
        return false;
    }

    query.finish();
    db.commit();
    return true;
}

/**
 * @brief CommentDB::erase erases comment from comment db
 * @param comment_id the id of the comment
 */
void AssignmentDB::remove_link(int assignment_id, int section_id){
    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("DELETE FROM assignment_section "
                    "WHERE assignment = ? AND section = ?;");
    query.addBindValue(assignment_id);
    query.addBindValue(section_id);

    if (!query.exec()) {
        qDebug() << "Failed to delete from 'comment' table" << endl << "SQL ERROR: " << query.lastError();
        db.commit();
        return;
    }

    query.finish();

    db.commit();
}


/**
 * @brief AssignmentDB::select Returns id of the row
 * that matches given name
 * @param name the name of the assignment (ex. Drawing Shapes)
 * @return the resulting ID
 */
int AssignmentDB::select(const QString name) {

    db.transaction();
    QSqlQuery query(db);


    query.prepare("SELECT * FROM assignment WHERE name = ?");
    query.addBindValue(name);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'assignment'" << endl << "SQL ERROR: " << query.lastError();
        query.finish();
        db.commit();
        return -1;
    }

    // Return the row ID
    int id_field = query.record().indexOf("id");
    if (query.next()) {
        return query.value(id_field).toInt();
    }

    // No rows found matching the query
    query.finish();
    db.commit();
    return -1;
}


/**
 * @brief AssignmentDB::load_all loads all database records
 * to the controller
 */
void AssignmentDB::load_all() {

    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("SELECT * FROM assignment");

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'assignment' (load_all)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
        query.finish();
        db.commit();
        return ;
    }

    int id_field = query.record().indexOf("id");
    int name_field = query.record().indexOf("name");
    int objective_field = query.record().indexOf("objective");
    int full_grade_field = query.record().indexOf("full_grade");

    while(query.next()) {

        _controller->add_assignment(query.value(name_field).toString(),
                                   query.value(objective_field).toString(),
                                    query.value(full_grade_field).toBool(),
                                    query.value(id_field).toInt());

    }

    query.finish();
    db.commit();
    return;
}


/**
 * @brief AssignmentDB::load_all loads all database records
 * to the controller
 * @param section the section
 */
void AssignmentDB::load_all(Section *section) {


    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("SELECT * FROM assignment_section WHERE section = ?");

    query.addBindValue(section->_id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'assignment_section' (load_all)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
        query.finish();
        db.commit();
        return ;
    }

    int assignment_id_field = query.record().indexOf("assignment");

    while(query.next()) {

        section->add_assignment(_controller->get_assignment(query.value(assignment_id_field).toInt()),
                                true);

    }

    query.finish();
    db.commit();
    return;
}

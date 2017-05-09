#include "rubricdb.h"

/**
 * @brief RubricDB::add Insert a row to the database
 * @param name description of the criterion
 * @param assignment_id the assignment this rubric belongs to
 * @param parent_id if this is a sub-criterion then this is the parent
 * @param out_of maximum grade assigned to the criterion (0 for extra-credit)
 * @return true if the query succeded
 */
int RubricDB::add_criterion(const QString name, int assignment_id, int parent_id, int out_of) {

    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("INSERT INTO rubric (id, name, assignment, parent, grade_out_of) "
                  "VALUES (NULL, ?, ?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(assignment_id);
    query.addBindValue(parent_id);
    query.addBindValue(out_of);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'rubric' table" << endl << "SQL ERROR: " << query.lastError();
        db.commit();
        return false;
    }

    int last_insert_id = query.lastInsertId().toInt();
    query.finish();
    db.commit();

    return last_insert_id;
}

/**
 * @brief RubricDB::update update the row in the table given by the criterion_id
 * @param name the new name
 * @param out_of the new max score
 * @param criterion_id the criterion to update
 */
int RubricDB::update(const QString name, int out_of, int criterion_id){
    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("UPDATE rubric "
                  "SET name = :name, grade_out_of = :out_of "
                  "WHERE id = :criterion_id");

    query.bindValue(":name", name);
    query.bindValue(":out_of", out_of);
    query.bindValue(":criterion_id", criterion_id);


    if (!query.exec()) {
        qDebug() << "Failed to update rubric "
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
 * @brief RubricDB::select Returns id of the row
 * that matches given information
 * @param assignment_id the assignment this rubric belongs to
 * @param name description of the criterion
 * @return the resulting ID
 */
int RubricDB::select(int assignment_id, const QString name) {

    QSqlQuery query(db);

    db.transaction();

    query.prepare("SELECT * FROM rubric WHERE assignment = ? AND name = ?");
    query.addBindValue(assignment_id);
    query.addBindValue(name);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'rubric'" << endl << "SQL ERROR: " << query.lastError();
        return -1;
    }

    // Return the row ID
    int id_field = query.record().indexOf("id");
    if (query.next()) {
        return query.value(id_field).toInt();
    }

    db.commit();
    // No rows found matching the query
    return -1;
}


/**
 * @brief RubricDB::load_parent_criteria loads all top level
 * criteria records related to the specified rubric
 */
void RubricDB::load_parent_criteria(Rubric *rubric) {

    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("SELECT "
                  "rubric.name AS criterion_name, "
                  "rubric.id AS criterion_id, "
                  "rubric.parent AS parent_id, "
                  "rubric.grade_out_of AS out_of "
                  "FROM rubric "
                  "WHERE rubric.assignment = ? "
                  "AND rubric.parent = -1");

    query.addBindValue(rubric->_assignment->_id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'rubric' (load_all)" << query.executedQuery() << endl << "SQL ERROR (" << rubric->_assignment->_id << " : " << query.lastError();
        return ;
    }

    int criterion_id_field = query.record().indexOf("criterion_id");
    int criterion_name_field = query.record().indexOf("criterion_name");
    int out_of_field = query.record().indexOf("out_of");

    while(query.next()) {
        rubric->add_criterion(query.value(criterion_name_field).toString(), NULL, query.value(out_of_field).toInt(), query.value(criterion_id_field).toInt());
    }

    query.finish();
    db.commit();
}



/**
 * @brief RubricDB::load_sub_criteria loads all second level
 * criteria records related to a parent criterion
 */
void RubricDB::load_sub_criteria(Criterion *criterion) {

    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("SELECT "
                  "rubric.name AS criterion_name, "
                  "rubric.id AS criterion_id, "
                  "rubric.grade_out_of AS out_of "
                  "FROM rubric "
                  "WHERE rubric.parent = ?");

    query.addBindValue(criterion->_id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'rubric' (load_all)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
        return ;
    }

    int criterion_id_field = query.record().indexOf("criterion_id");
    int criterion_name_field = query.record().indexOf("criterion_name");
    int out_of_field = query.record().indexOf("out_of");

    while(query.next()) {
        criterion->_rubric->add_criterion(query.value(criterion_name_field).toString(), criterion, query.value(out_of_field).toInt(), query.value(criterion_id_field).toInt());
    }

    query.finish();
    db.commit();
}

/**
 * @brief RubricDB::remove erases criterion from rubric db, does not remove
 * sub criteria for criterion
 * @param criterion_id the criterion to remove
 */
void RubricDB::remove(int criterion_id){
    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("DELETE FROM rubric "
                    "WHERE id = ?;");
    query.addBindValue(criterion_id);

    if (!query.exec()) {
        qDebug() << "Failed to delete from 'comment' table" << endl << "SQL ERROR: " << query.lastError();
        db.commit();
        return;
    }

    query.finish();

    db.commit();
}



/**
 * @brief Destructor
 */

RubricDB::~RubricDB() {

}

#include "assignmentdb.h"

/**
 * @brief Default constructor
 */
AssignmentDB::AssignmentDB()
{

}

/**
 * @brief Destructor
 */

AssignmentDB::~AssignmentDB() {

}

/**
 * @brief AssignmentDB::add Insert a row to the database
 * @param name the name of the assignment (ex. Drawing Shapes)
 * @param objective the objective of the assignment (ex. Introducing students to Processing)
 * @return true if the query succeded
 */
bool AssignmentDB::add(const QString name, const QString objective) {

    QSqlQuery query(db);

    query.prepare("INSERT INTO assignment (id, name, objective) "
                  "VALUES (NULL, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(objective);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'assignment' table" << endl << "SQL ERROR: " << query.lastError();
        return false;
    }

    return true;
}


/**
 * @brief AssignmentDB::link Links an assignment to a section
 * @param section_id the id of the section where the assignment will be linked
 * @param assignment_id the id of the assignment to be linked
 * @param folder the path to the folder where submissions are stored
 * @return true if the query succeded
 */
bool AssignmentDB::link(int assignment_id,
                        int section_id,
                        const QString folder) {

    QSqlQuery query(db);

    query.prepare("INSERT INTO assignment_section (id, assignment, section, folder) "
                  "VALUES (NULL, ?, ?, ?)");
    query.addBindValue(assignment_id);
    query.addBindValue(section_id);
    query.addBindValue(folder);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'assignment_section' table" << endl << "SQL ERROR: " << query.lastError();
        return false;
    }

    return true;
}


/**
 * @brief AssignmentDB::select Returns id of the row
 * that matches given name
 * @param name the name of the assignment (ex. Drawing Shapes)
 * @return the resulting ID
 */
int AssignmentDB::select(const QString name) {

    QSqlQuery query(db);

    query.prepare("SELECT * FROM assignment WHERE name = ?");
    query.addBindValue(name);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'assignment'" << endl << "SQL ERROR: " << query.lastError();
        return -1;
    }

    // Return the row ID
    int id_field = query.record().indexOf("id");
    if (query.next()) {
        return query.value(id_field).toInt();
    }

    // No rows found matching the query
    return -1;
}


/**
 * @brief AssignmentDB::load_all loads all database records
 * to the controller
 */
void AssignmentDB::load_all() {
    QSqlQuery query(db);

    query.prepare("SELECT * FROM assignment");

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'assignment' (load_all)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
        return ;
    }

    int id_field = query.record().indexOf("id");
    int name_field = query.record().indexOf("name");
    int objective_field = query.record().indexOf("objective");

    while(query.next()) {

        _controller->add_assignment(query.value(name_field).toString(),
                                              query.value(objective_field).toString(),
                                              true);

        QSqlQuery link_query(db);

        link_query.prepare("SELECT assignment_section.folder AS folder, assignment.name AS assignment_name, section.name AS section_name, course.name AS course_name "
                      "FROM assignment_section, assignment, section, course "
                      "WHERE assignment_section.assignment = assignment.id "
                      "AND assignment.id = ? "
                      "AND assignment_section.section = section.id "
                      "AND section.course_id = course.id");
        link_query.addBindValue(query.value(id_field).toString());

        // Execute the query
        if (!link_query.exec()) {
            qDebug() << "Failed to select from table 'assignment_section' (load_all)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
            return ;
        }

        int assignment_name_field = link_query.record().indexOf("assignment_name");
        int section_name_field = link_query.record().indexOf("section_name");
        int course_name_field = link_query.record().indexOf("course_name");
        int folder_field = link_query.record().indexOf("folder");

        while(link_query.next()) {
            _controller->link_assignment(link_query.value(course_name_field).toString(),
                                           link_query.value(section_name_field).toString(),
                                           link_query.value(assignment_name_field).toString(),
                                           link_query.value(folder_field).toString(),
                                           true);
        }
    }
}



/**
 * @brief AssignmentDB::load_section_assignments loads a specific section's assignments
 * @param course_name the course the section belongs to
 * @param section_name the section whose assignments will be loaded
 */
void AssignmentDB::load_section_assignments(QString course_name, QString section_name) {

    _controller->clear_section_assignments(course_name, section_name);

    QSqlQuery query(db);

    query.prepare("SELECT * FROM assignment "
                  "WHERE "
                  "assignment_section.section = "
                  "("
                      "SELECT section.id from section WHERE "
                      "section.name = ? "
                      "AND section.course_id = "
                          "("
                                "SELECT course.id FROM course WHERE course.name = ?"
                          ")"
                  ") "
                  "AND assignment.id = assignment_section.assignment");

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'assignment' (load_all)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
        return ;
    }

    int id_field = query.record().indexOf("id");
    int name_field = query.record().indexOf("name");
    int objective_field = query.record().indexOf("objective");

    while(query.next()) {

        _controller->add_assignment(query.value(name_field).toString(),
                                              query.value(objective_field).toString(),
                                              true);

        QSqlQuery link_query(db);

        link_query.prepare("SELECT assignment_section.folder AS folder, assignment.name AS assignment_name, section.name AS section_name, course.name AS course_name "
                      "FROM assignment_section, assignment, section, course "
                      "WHERE assignment_section.assignment = assignment.id "
                      "AND assignment.id = ? "
                      "AND assignment_section.section = section.id"
                      "AND section.course_id = course.id");
        link_query.addBindValue(query.value(id_field).toInt());

        // Execute the query
        if (!link_query.exec()) {
            qDebug() << "Failed to select from table 'assignment_section' (load_all)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
            return ;
        }

        int assignment_name_field = link_query.record().indexOf("assignment_name");
        int section_name_field = link_query.record().indexOf("section_name");
        int course_name_field = link_query.record().indexOf("course_name");
        int folder_field = link_query.record().indexOf("folder");

        while(link_query.next()) {
            _controller->link_assignment(link_query.value(course_name_field).toString(),
                                           link_query.value(section_name_field).toString(),
                                           link_query.value(assignment_name_field).toString(),
                                           link_query.value(folder_field).toString(),
                                           true);
        }
    }
}

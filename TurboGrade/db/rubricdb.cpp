#include "rubricdb.h"

/**
 * @brief Default constructor
 */
RubricDB::RubricDB()
{

}

/**
 * @brief Destructor
 */

RubricDB::~RubricDB() {

}

/**
 * @brief RubricDB::add Insert a row to the database
 * @param name description of the criterion
 * @param assignment_id the assignment this rubric belongs to
 * @param parent_id if this is a sub-criterion then this is the parent
 * @param out_of maximum grade assigned to the criterion (0 for extra-credit)
 * @return true if the query succeded
 */
bool RubricDB::add_criterion(const QString name, int assignment_id, int parent_id, int out_of) {

    QSqlQuery query(db);

    query.prepare("INSERT INTO rubric (id, name, assignment, parent, grade_out_of) "
                  "VALUES (NULL, ?, ?, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(assignment_id);
    query.addBindValue(parent_id);
    query.addBindValue(out_of);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'rubric' table" << endl << "SQL ERROR: " << query.lastError();
        return false;
    }

    return true;
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

    query.prepare("SELECT * FROM rubric WHERE assignment = ? AND name = ?");
    query.addBindValue(assignment_id);
    query.addBindValue(name);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'rubric'" << endl << "SQL ERROR: " << query.lastError();
        return NULL;
    }

    // Return the row ID
    int id_field = query.record().indexOf("id");
    if (query.next()) {
        return query.value(id_field).toInt();
    }

    // No rows found matching the query
    return NULL;
}


/**
 * @brief RubricDB::load_all loads all database records
 * to the controller
 */
void RubricDB::load_all() {

    QSqlQuery query(db);

    query.prepare("SELECT "
                  "rubric.name AS criterion_name, "
                  "rubric.parent AS parent_id, "
                  "assignment.name AS assignment_name, "
                  "rubric.grade_out_of AS out_of "
                  "FROM rubric, assignment "
                  "WHERE assignment.id = rubric.assignment");

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'rubric' (load_all)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
        return ;
    }

    int assignment_name_field = query.record().indexOf("assignment_name");
    int criterion_name_field = query.record().indexOf("criterion_name");
    int out_of_field = query.record().indexOf("out_of");
    int parent_id_field = query.record().indexOf("parent_id");


    while(query.next()) {

        QString assignment_name = query.value(assignment_name_field).toString();
        QString criterion_name = query.value(criterion_name_field).toString();
        int out_of = query.value(out_of_field).toInt();
        int parent_id = query.value(parent_id_field).toInt();

        QSqlQuery parent_query(db);

        parent_query.prepare("SELECT "
                      "rubric.name AS parent_name "
                      "FROM rubric "
                      "WHERE rubric.id = ?");

        parent_query.addBindValue(parent_id);

        // Execute the query
        if (!parent_query.exec()) {
            qDebug() << "Failed to select from table 'rubric' (parent)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
            return ;
        }

        int parent_name_field = parent_query.record().indexOf("parent_name");

        QString parent_name = parent_query.next() ? parent_query.value(parent_name_field).toString() : NULL;

        _controller->add_criterion(assignment_name,
                                             criterion_name,
                                             parent_name,
                                             out_of,
                                             true);
    }

}



/**
 * @brief RubricDB::load_assignment_criteria loads a specific assignment's rubric
 * @param assignment_id the assignment's identifier in the database
 */
void RubricDB::load_assignment_criteria(int assignment_id) {

    QSqlQuery query(db);

    query.prepare("SELECT "
                  "rubric.name AS criterion_name, "
                  "rubric.parent AS parent_id, "
                  "assignment.name AS assignment_name, "
                  "rubric.grade_out_of AS out_of "
                  "FROM rubric, assignment "
                  "WHERE assignment.id = rubric.assignment "
                  "AND rubric.assignment = ?");

    query.addBindValue(assignment_id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'rubric' (load_all)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
        return ;
    }

    int assignment_name_field = query.record().indexOf("assignment_name");
    int criterion_name_field = query.record().indexOf("criterion_name");
    int out_of_field = query.record().indexOf("out_of");
    int parent_id_field = query.record().indexOf("parent_id");

    while(query.next()) {

        QString assignment_name = query.value(assignment_name_field).toString();
        QString criterion_name = query.value(criterion_name_field).toString();
        int out_of = query.value(out_of_field).toInt();
        int parent_id = query.value(parent_id_field).toInt();

        QSqlQuery parent_query(db);

        parent_query.prepare("SELECT "
                      "rubric.name AS parent_name "
                      "FROM rubric "
                      "WHERE rubric.id = ?");

        parent_query.addBindValue(parent_id);

        // Execute the query
        if (!parent_query.exec()) {
            qDebug() << "Failed to select from table 'rubric' (parent)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
            return ;
        }

        int parent_name_field = parent_query.record().indexOf("parent_name");

        parent_query.first();

        QString parent_name = parent_query.value(parent_name_field).toString();

        _controller->add_criterion(assignment_name,
                                             criterion_name,
                                             parent_name,
                                             out_of,
                                             true);
    }

}

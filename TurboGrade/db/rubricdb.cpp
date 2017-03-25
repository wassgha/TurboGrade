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
int RubricDB::add_criterion(const QString name, int assignment_id, int parent_id, int out_of) {

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

    return query.lastInsertId().toInt();
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
 * @brief RubricDB::load_parent_criteria loads all top level
 * criteria records related to the specified rubric
 */
void RubricDB::load_parent_criteria(Rubric *rubric) {

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
        rubric->add_criterion(query.value(criterion_id_field).toInt(), query.value(criterion_name_field).toString(), NULL, query.value(out_of_field).toInt());
    }
}



/**
 * @brief RubricDB::load_sub_criteria loads all second level
 * criteria records related to a parent criterion
 */
void RubricDB::load_sub_criteria(Criterion *criterion) {

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
        criterion->_rubric->add_criterion(query.value(criterion_id_field).toInt(), query.value(criterion_name_field).toString(), criterion, query.value(out_of_field).toInt());
    }
}

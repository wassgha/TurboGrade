#include "submissiondb.h"

/**
 * @brief Default constructor
 */
SubmissionDB::SubmissionDB()
{

}

/**
 * @brief Destructor
 */

SubmissionDB::~SubmissionDB() {

}

/**
 * @brief SubmissionDB::add Insert a row to the database
 * @param student_id the student's unique identifier
 * @param assignment_id the assignment this submission belongs to
 * @return true if the query succeded
 */
int SubmissionDB::add(int student_id, int assignment_id) {

    SHOW_WHERE;

    QSqlQuery query(db);

    query.prepare("INSERT INTO submission (id, student, assignment) "
                  "VALUES (NULL, ?, ?)");
    query.addBindValue(student_id);
    query.addBindValue(assignment_id);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'submission' table" << endl << "SQL ERROR: " << query.lastError();
        return false;
    }

    int last_insert_id = query.lastInsertId().toInt();
    query.finish();

    return last_insert_id;
}

/**
 * @brief SubmissionDB::select Returns id of the row
 * that matches given information
 * @param student_id the student's unique identifier
 * @param assignment_id the assignment this submission belongs to
 * @return the resulting ID
 */
int SubmissionDB::select(int student_id, int assignment_id) {

    SHOW_WHERE;

    QSqlQuery query(db);

    query.prepare("SELECT * FROM submission WHERE student = ? AND assignment = ?");
    query.addBindValue(student_id);
    query.addBindValue(assignment_id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'submission'" << endl << "SQL ERROR: " << query.lastError();
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
 * @brief SubmissionDB::load_all loads all submissions
 * for a specific student
 */
void SubmissionDB::load_all(Student *student) {

    SHOW_WHERE;

    QSqlQuery query(db);

    query.prepare("SELECT "
                  "submission.id AS submission_id,"
                  "assignment.name AS assignment_name "
                  "FROM submission, assignment "
                  "WHERE assignment.id = submission.assignment "
                  "AND submission.student = ?");

    query.addBindValue(student->_id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'submission' (load_all)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
        return ;
    }

    int assignment_name_field = query.record().indexOf("assignment_name");
    int submission_id_field = query.record().indexOf("submission_id");

    while(query.next()) {
        student->add_submission(query.value(submission_id_field).toInt(),
                                _controller->get_assignment(query.value(assignment_name_field).toString()));
    }

    query.finish();

}

#include "submissiondb.h"

/**
 * @brief SubmissionDB::add Insert a row to the database
 * @param student_id the student's unique identifier
 * @param assignment_id the assignment this submission belongs to
 * @param general_comment the general comment about this submission
 * @param status whether the submission has been graded or not
 * @return the id if the query succeeded
 */
int SubmissionDB::add(int student_id, int assignment_id, QString general_comment, int status) {

    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("INSERT INTO submission (id, student, assignment, general_comment, status) "
                  "VALUES (NULL, ?, ?, ?, ?)");
    query.addBindValue(student_id);
    query.addBindValue(assignment_id);
    query.addBindValue(general_comment);
    query.addBindValue(status);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'submission' table" << endl << "SQL ERROR: " << query.lastError();
        return false;
    }

    int last_insert_id = query.lastInsertId().toInt();
    query.finish();
    db.commit();

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

    db.transaction();
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

    db.commit();
    // No rows found matching the query
    return -1;
}


/**
 * @brief SubmissionDB::load_all loads all submissions
 * for a specific student
 */
void SubmissionDB::load_all(Student *student) {

    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("SELECT "
                  "submission.status AS submission_status,"
                  "submission.id AS submission_id,"
                  "submission.general_comment AS general_comment"
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
    int submission_status_field = query.record().indexOf("submission_status");
    int general_comment_field = query.record().indexOf("general_comment");

    while(query.next()) {
        student->add_submission(_controller->get_assignment(query.value(assignment_name_field).toString()),
                                query.value(general_comment_field).toString(),
                                query.value(submission_status_field).toInt(),
                                query.value(submission_id_field).toInt());
    }

    query.finish();
    db.commit();

}


/**
 * @brief SubmissionDB::update_status updates the grading status
 * of a specific submission
 * @param submission_id the submission id
 * @param status the value for the status (in progress, finalized, etc.)
 */
void SubmissionDB::update_status(int submission_id, int status){

    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("UPDATE submission SET status = :status WHERE id = :submission_id");

    query.bindValue(":status", status);
    query.bindValue(":submission_id", submission_id);

    if (!query.exec()) {
        qDebug() << "Failed to update submission status"
                 << query.lastQuery() << endl
                 << "SQL ERROR: " << query.lastError();
    }

    query.finish();
    db.commit();
}


/**
 * @brief SubmissionDB::update_general_comment updates the comment associated
 * with the submission
 * of a specific submission
 * @param submission_id the submission id
 * @param general_comment the text for the general comment
 */
void SubmissionDB::update_general_comment(int submission_id, QString general_comment){

    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("UPDATE submission SET general_comment = :general_comment WHERE id = :submission_id");

    query.bindValue(":general_comment", general_comment);
    query.bindValue(":submission_id", submission_id);

    if (!query.exec()) {
        qDebug() << "Failed to update submission general comment"
                 << query.lastQuery() << endl
                 << "SQL ERROR: " << query.lastError();
    }

    query.finish();
    db.commit();
}

/**
 * @brief SubmissionDB::remove erases submission from submission db
 * @param submission_id the id of the submission
 */
void SubmissionDB::remove(int submission_id){
    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("DELETE FROM submission "
                    "WHERE id = ?;");
    query.addBindValue(submission_id);

    if (!query.exec()) {
        qDebug() << "Failed to delete from 'submission' table" << endl << "SQL ERROR: " << query.lastError();
        db.commit();
        return;
    }

    query.finish();

    db.commit();
}


/**
 * @brief Destructor
 */

SubmissionDB::~SubmissionDB() {

}

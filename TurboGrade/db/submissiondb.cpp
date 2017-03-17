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
bool SubmissionDB::add(int student_id, int assignment_id) {

    QSqlQuery query(db);

    query.prepare("INSERT INTO submission (id, student, assignment) "
                  "VALUES (NULL, ?, ?)");
    query.addBindValue(student_id);
    query.addBindValue(assignment_id);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'submission' table" << endl << "SQL ERROR: " << query.lastError();
        return false;
    }

    return true;
}


/**
 * @brief SubmissionDB::add_file Insert a row to the database
 * @param student_id the student's unique identifier
 * @param assignment_id the assignment this submission belongs to
 * @return true if the query succeded
 */
bool SubmissionDB::add_file(int submission_id, QString filename) {

    QSqlQuery query(db);

    query.prepare("INSERT INTO file (id, submission, filename) "
                  "VALUES (NULL, ?, ?)");
    query.addBindValue(submission_id);
    query.addBindValue(filename);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'file' table" << endl << "SQL ERROR: " << query.lastError();
        return false;
    }

    return true;
}

/**
 * @brief SubmissionDB::select Returns id of the row
 * that matches given information
 * @param student_id the student's unique identifier
 * @param assignment_id the assignment this submission belongs to
 * @return the resulting ID
 */
int SubmissionDB::select(int student_id, int assignment_id) {

    QSqlQuery query(db);

    query.prepare("SELECT * FROM submission WHERE student = ? AND assignment = ?");
    query.addBindValue(student_id);
    query.addBindValue(assignment_id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'submission'" << endl << "SQL ERROR: " << query.lastError();
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
 * @brief SubmissionDB::load_all loads all database records
 * to the controller
 */
void SubmissionDB::load_all() {
    QSqlQuery query(db);

    query.prepare("SELECT "
                  "submission.id,"
                  "course.name AS course_name, "
                  "section.name AS section_name, "
                  "student.name AS student_name, "
                  "student.username AS student_username, "
                  "assignment.name AS assignment_name "
                  "FROM submission, course, section, student, assignment, assignment_section "
                  "WHERE assignment.id = assignment_section.assignment "
                  "AND assignment_section.assignment = submission.assignment "
                  "AND student.id = submission.student "
                  "AND section.id = assignment_section.section "
                  "AND course.id = section.course_id ");

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'submission' (load_all)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
        return ;
    }

    int assignment_name_field = query.record().indexOf("assignment_name");
    int section_name_field = query.record().indexOf("section_name");
    int course_name_field = query.record().indexOf("course_name");
    int student_name_field = query.record().indexOf("student_name");
    int student_username_field = query.record().indexOf("student_username");

    while(query.next()) {

        _assignmentController->add_submission(query.value(course_name_field).toString(),
                                              query.value(section_name_field).toString(),
                                              query.value(student_name_field).toString(),
                                              query.value(student_username_field).toString(),
                                              query.value(assignment_name_field).toString(),
                                              true);

    }
}



/**
 * @brief SubmissionDB::load_student_submissions loads a specific student's submissions
 * @param student_id the student's identifier in the database
 */
void SubmissionDB::load_student_submissions(int student_id) {

    QSqlQuery query(db);

    query.prepare("SELECT "
                  "submission.id,"
                  "course.name AS course_name, "
                  "section.name AS section_name, "
                  "student.name AS student_name, "
                  "student.username AS student_username, "
                  "assignment.name AS assignment_name "
                  "FROM submission, course, section, student, assignment, assignment_section "
                  "WHERE assignment.id = assignment_section.assignment "
                  "AND assignment_section.assignment = submission.assignment "
                  "AND student.id = submission.student "
                  "AND section.id = assignment_section.section "
                  "AND course.id = section.course_id "
                  "AND submission.student = ?");

    query.addBindValue(student_id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'submission' (load_all)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
        return ;
    }

    int assignment_name_field = query.record().indexOf("assignment_name");
    int section_name_field = query.record().indexOf("section_name");
    int course_name_field = query.record().indexOf("course_name");
    int student_name_field = query.record().indexOf("student_name");
    int student_username_field = query.record().indexOf("student_username");

    while(query.next()) {

        _assignmentController->add_submission(query.value(course_name_field).toString(),
                                              query.value(section_name_field).toString(),
                                              query.value(student_name_field).toString(),
                                              query.value(student_username_field).toString(),
                                              query.value(assignment_name_field).toString(),
                                              true);

    }
}

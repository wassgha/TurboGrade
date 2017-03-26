#include "commentdb.h"

/**
 * @brief Default constructor
 */
CommentDB::CommentDB()
{

}

/**
 * @brief Destructor
 */

CommentDB::~CommentDB() {

}

/**
 * @brief CommentDB::add Insert a row to the database
 * @param student_id the student's unique identifier
 * @param assignment_id the assignment this submission belongs to
 * @return true if the query succeded
 */
int CommentDB::add(int submission_id, QString filename,
                   int criterion_id, QString comment_text,
                   int grade, int start_pos,
                   int end_pos) {

    QSqlQuery query(db);

    query.prepare("INSERT INTO comment (id, submission, filename, "
                  "rubric, comment_text, "
                  "grade, start_pos, end_pos) "
                  "VALUES (NULL, ?, ?, ?, ?, ?, ?, ?)");
    query.addBindValue(submission_id);
    query.addBindValue(filename);
    query.addBindValue(criterion_id);
    query.addBindValue(comment_text);
    query.addBindValue(grade);
    query.addBindValue(start_pos);
    query.addBindValue(end_pos);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'comment' table" << endl << "SQL ERROR: " << query.lastError();
        return false;
    }

    return query.lastInsertId().toInt();
}

/**
 * @brief CommentDB::load_all loads all comments on
 * a specific submission
 * @param submission the submission object
 */
void CommentDB::load_all(Submission *submission) {
    QSqlQuery query(db);

    query.prepare("SELECT * "
                  "FROM comment "
                  "WHERE comment.submission = ? ");

    query.addBindValue(submission->_id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'comment' (load_all)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
        return ;
    }

    int id_field = query.record().indexOf("id");
    int filename_field = query.record().indexOf("filename");
    int criterion_field = query.record().indexOf("rubric");
    int text_field = query.record().indexOf("comment_text");
    int grade_field = query.record().indexOf("grade");
    int start_pos_field = query.record().indexOf("start_pos");
    int end_pos_field = query.record().indexOf("end_pos");

    while(query.next()) {
        submission->add_comment(query.value(id_field).toInt(),
                                query.value(filename_field).toString(),
                                submission->_assignment->_rubric->get_criterion(query.value(criterion_field).toInt()),
                                query.value(text_field).toString(),
                                query.value(grade_field).toInt(),
                                query.value(start_pos_field).toInt(),
                                query.value(end_pos_field).toInt());
    }
}

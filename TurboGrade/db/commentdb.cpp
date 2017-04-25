#include "commentdb.h"

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

    SHOW_WHERE;

    db.transaction();
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
        db.commit();
        return -1;
    }

    int last_insert_id = query.lastInsertId().toInt();
    query.finish();

    db.commit();
    return last_insert_id;
}

/**
 * @brief CommentDB::load_all loads all comments on
 * a specific submission
 * @param submission the submission object
 */
void CommentDB::load_all(Submission *submission) {

    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("SELECT * "
                  "FROM comment "
                  "WHERE comment.submission = ? ");

    query.addBindValue(submission->_id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'comment' (load_all)" << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
        db.commit();
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
        submission->add_comment(query.value(filename_field).toString(),
                                submission->_assignment->_rubric->get_criterion(query.value(criterion_field).toInt()),
                                query.value(text_field).toString(),
                                query.value(grade_field).toInt(),
                                query.value(start_pos_field).toInt(),
                                query.value(end_pos_field).toInt(),
                                query.value(id_field).toInt());
    }
    query.finish();
    db.commit();
}

/**
 * @brief CommentDB::erase erases comment from comment db
 * @param comment_id the id of the comment
 */
void CommentDB::remove(int comment_id){
    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("DELETE FROM comment "
                    "WHERE id = ?;");
    query.addBindValue(comment_id);

    if (!query.exec()) {
        qDebug() << "Failed to delete from 'comment' table" << endl << "SQL ERROR: " << query.lastError();
        db.commit();
        return;
    }

    query.finish();

    db.commit();
}

/**
 * @brief CommentDB::update updates the comment given by the comment_id
 * @param filename the new filename
 * @param criterion_id the new criterion id
 * @param comment_text the new text
 * @param grade the new grade
 * @param start_pos the new starting position
 * @param end_pos the new end position
 * @param comment_id the comment id to update
 */
void CommentDB::update(QString filename, int criterion_id, QString comment_text, int grade, int start_pos, int end_pos, int comment_id){

}

/**
 * @brief CommentDB::load_all loads all comments on
 * a specific submission
 */
QSqlTableModel* CommentDB::load_model() {

    SHOW_WHERE;

    db.transaction();

    QSqlTableModel *model = new QSqlTableModel(0, db);
    model->setTable("comment");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("submission"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("filename"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("rubric"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("comment_text"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("grade"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("start_pos"));
    model->setHeaderData(7, Qt::Horizontal, QObject::tr("end_pos"));


    db.commit();
    return model;
}


/**
 * @brief Destructor
 */

CommentDB::~CommentDB() {

}

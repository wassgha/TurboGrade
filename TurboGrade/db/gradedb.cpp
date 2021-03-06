#include "gradedb.h"

/**
 * @brief GradeDB::add Adds a mapping from rubric_id, submission_id to a grade
 * value
 * @param rubric_id the rubric (criterion) id
 * @param submission_id the submission id
 * @param grade the value for the grade
 * @return the grade's key
 */
int GradeDB::add(int rubric_id, int submission_id, int grade){

    SHOW_WHERE;

    db.transaction();

    QSqlQuery query(db);


    query.prepare("INSERT OR IGNORE INTO grade (id, rubric, submission, score) "
                  "VALUES (NULL, :rubric_id, :submission_id, :grade)");

    query.bindValue(":rubric_id", rubric_id);
    query.bindValue(":submission_id", submission_id);
    query.bindValue(":grade", grade);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'grade' table"
                 << query.lastQuery() << endl
                 << "SQL ERROR: " << query.lastError()
                 << "(" << rubric_id << ", " << submission_id << "," << grade << ")";
        return -1;
    }

    int last_id = query.lastInsertId().toInt();

    query.finish();
    db.commit();

    return last_id;
}


/**
 * @brief GradeDB::update rewrites the grade for a submission and a criterion
 * @param rubric_id the rubric (criterion) id
 * @param submission_id the submission id
 * @param grade the value for the grade
 * @return the grade's key
 */
int GradeDB::update(int rubric_id, int submission_id, int grade){

    SHOW_WHERE;

    qDebug()<<"Called update(rubric id = " << QString::number(rubric_id) << ", submission_id = " << QString::number(submission_id) << ", grade = " << grade << ")";

    db.transaction();
    QSqlQuery query(db);


    query.prepare("UPDATE grade SET score = :grade WHERE rubric = :rubric_id AND submission = :submission_id");

    query.bindValue(":rubric_id", rubric_id);
    query.bindValue(":submission_id", submission_id);
    query.bindValue(":grade", grade);
    qDebug() << "UPDATE grade SET score = "<< QString::number(grade) <<" WHERE rubric = "<<QString::number(rubric_id)<<" AND submission = "<<QString::number(submission_id)<<endl;

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'grade' table"
                 << query.lastQuery() << endl
                 << "SQL ERROR: " << query.lastError()
                 << "(" << rubric_id << ", " << submission_id << "," << grade << ")";
        return -1;
    }

    int last_id = query.lastInsertId().toInt();

    query.finish();
    db.commit();

    add(rubric_id, submission_id, grade);

    return last_id;
}

/**
 * @brief GradeDB::select retrieves the grade id denoted by the rubric id,
 * submission id pair
 * @param rubric_id the rubric id
 * @param submission_id the submission id
 * @return the key of the grade, -1 if non-existant
 */
int GradeDB::select(int rubric_id, int submission_id){

    SHOW_WHERE;

    QSqlQuery query(db);

    db.transaction();

    query.prepare("SELECT * FROM grade WHERE rubric = ? AND submission = ?");
    query.addBindValue(rubric_id);
    query.addBindValue(submission_id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'grade'" << endl << "SQL ERROR: " << query.lastError();
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
 * @brief GradeDB::load_all given a submission and a set of criterion, load all
 * of the criterion, grade mappings to the controller.
 * @param submission the submission
 * @param criteria the set of criterion
 */
void GradeDB::load_all(Submission *submission, std::vector<Criterion*>* criteria){

    SHOW_WHERE;

    for(Criterion *criterion : *criteria){
        load_criterion(submission, criterion);
        if (criterion->has_children()) {
            for (Criterion *child : criterion->children()) {
                load_criterion(submission, child);
            }
        }
    }
}

void GradeDB::load_criterion(Submission *submission, Criterion* criterion) {

    SHOW_WHERE;

    int submission_id = submission->_id;

    QSqlQuery query(db);

    db.transaction();

    int rubric_id = criterion->_id;
    query.prepare("SELECT * FROM grade WHERE submission = ? AND rubric = ?");
    query.addBindValue(submission_id);
    query.addBindValue(rubric_id);
    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'grades' (load_all)" << endl << query.executedQuery() << endl << "SQL ERROR: " << query.lastError();
        return;
    }

    int grade_field = query.record().indexOf("score");

    int grade = -1;

    if (query.first()) {
        grade = query.value(grade_field).toInt();
    }

    query.finish();

    db.commit();


    submission->update_grade(criterion,grade, true);


}

/**
 * @brief GradeDB::remove remove the grade from the db based on the submission id
 * @param submission_id the submission to remove the grade for
 */
void GradeDB::remove(int submission_id){
    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("DELETE FROM grade "
                    "WHERE submission = ?;");
    query.addBindValue(submission_id);

    if (!query.exec()) {
        qDebug() << "Failed to delete from 'grade' table" << endl << "SQL ERROR: " << query.lastError();
        db.commit();
        return;
    }

    query.finish();

    db.commit();
}

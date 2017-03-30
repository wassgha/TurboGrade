#include "gradedb.h"

GradeDB::GradeDB()
{

}

int GradeDB::add(int rubric_id, int submission_id, int grade){
    QSqlQuery query(db);

    query.prepare("INSERT INTO grades (id, rubric, submission, grade) "
                  "VALUES (NULL, ?, ?, ?)");

    query.addBindValue(rubric_id);
    query.addBindValue(submission_id);
    query.addBindValue(grade);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'grades' table" << endl << "SQL ERROR: " << query.lastError();
        return -1;
    }

    return query.lastInsertId().toInt();
}

int GradeDB::select(int rubric_id, int submission_id){
    QSqlQuery query(db);

    query.prepare("SELECT * FROM grades WHERE rubric = ? AND submission_id = ?");
    query.addBindValue(rubric_id);
    query.addBindValue(submission_id);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'grades'" << endl << "SQL ERROR: " << query.lastError();
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

void GradeDB::load_all(Submission *submission, std::vector<Criterion *> *criteria){
    int submission_id = submission->_id;
    for(Criterion *criterion : *criteria){
        QSqlQuery query(db);
        int rubric_id = criterion->_id;
        query.prepare("SELECT * FROM grades WHERE submission = ? AND rubric = ?");
        query.addBindValue(submission_id);
        query.addBindValue(rubric_id);
        // Execute the query
        if (!query.exec()) {
            qDebug() << "Failed to select from table 'grades'" << endl << "SQL ERROR: " << query.lastError();
            return;
        }

        int grade_field = query.record().indexOf("grade");
        while(query.next()) {
            _controller->add_grade(criterion,query.value(grade_field).toInt());
        }
    }
}

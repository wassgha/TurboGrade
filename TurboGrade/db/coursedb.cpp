#include "coursedb.h"

/**
 * @brief CourseDB::add Insert a row to the database
 * @param name the name of the course (ex. CS150)
 * @param semester the semester the course is taught in
 * @return true if the query succeded
 */
int CourseDB::add(const QString name, const QString semester) {

    QSqlQuery query(db);

    db.transaction();

    query.prepare("INSERT INTO course (id, name, semester) "
                  "VALUES (NULL, ?, ?)");
    query.addBindValue(name);
    query.addBindValue(semester);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'course' table" << endl << "SQL ERROR: " << query.lastError();
        return -1;
    }

    int last_insert_id = query.lastInsertId().toInt();
    query.finish();
    db.commit();

    return last_insert_id;
}


/**
 * @brief CourseDB::select Returns id of the row
 * that matches given name
 * @param name the name of the course (ex. CS150)
 * @param semester the semester the course is taught in
 * @return the resulting ID
 */
int CourseDB::select(const QString name, const QString semester) {

    SHOW_WHERE;

    QSqlQuery query(db);

    db.transaction();

    query.prepare("SELECT * FROM course WHERE name = ? AND semester = ?");
    query.addBindValue(name);
    query.addBindValue(semester);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'course'" << endl << "SQL ERROR: " << query.lastError();
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
 * @brief CourseDB::load_all loads all database records
 * to the controller
 */
void CourseDB::load_all() {

    SHOW_WHERE;

    db.transaction();
    QSqlQuery query(db);


    query.prepare("SELECT * FROM course");

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'course'" << endl << "SQL ERROR: " << query.lastError();
        return;
    }

    int id_field = query.record().indexOf("id");
    int name_field = query.record().indexOf("name");
    int semester_field = query.record().indexOf("semester");
    while(query.next()) {
        _controller->add_course(query.value(name_field).toString(), query.value(semester_field).toString(), query.value(id_field).toInt());
    }

    query.finish();
    db.commit();
}


/**
 * @brief Destructor
 */

CourseDB::~CourseDB() {

}

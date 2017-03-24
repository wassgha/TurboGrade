#include "coursedb.h"

/**
 * @brief Default constructor
 */
CourseDB::CourseDB()
{

}

/**
 * @brief Destructor
 */

CourseDB::~CourseDB() {

}

/**
 * @brief CourseDB::add Insert a row to the database
 * @param name the name of the course (ex. CS150)
 * @return true if the query succeded
 */
bool CourseDB::add(const QString name) {

    QSqlQuery query(db);

    query.prepare("INSERT INTO course (id, name) "
                  "VALUES (NULL, ?)");
    query.addBindValue(name);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'course' table" << endl << "SQL ERROR: " << query.lastError();
        return false;
    }

    return true;
}


/**
 * @brief CourseDB::select Returns id of the row
 * that matches given name
 * @param name the name of the course (ex. CS150)
 * @return the resulting ID
 */
int CourseDB::select(const QString name) {

    QSqlQuery query(db);

    query.prepare("SELECT * FROM course WHERE name = ?");
    query.addBindValue(name);

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

    // No rows found matching the query
    return -1;
}

/**
 * @brief CourseDB::load_all loads all database records
 * to the controller
 */
void CourseDB::load_all() {

    QSqlQuery query(db);

    query.prepare("SELECT * FROM course");

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'course'" << endl << "SQL ERROR: " << query.lastError();
        return;
    }

    int name_field = query.record().indexOf("name");
    while(query.next()) {
        _controller->add_course(query.value(name_field).toString(), true);
    }
}

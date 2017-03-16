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
 * @brief CourseDB::selects all fields from the database
 * @return the resulting rows
 */
QSqlQuery CourseDB::select_all() {

    QSqlQuery query(db);

    query.prepare("SELECT * FROM course");

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'course'" << endl << "SQL ERROR: " << query.lastError();
        return QSqlQuery();
    }

    return query;
}


/**
 * @brief CourseDB::load_all loads all database records
 * to the controller
 */
void CourseDB::load_all() {
    QSqlQuery result = select_all();
    int name_field = result.record().indexOf("name");
    while(result.next()) {
        _courseController->add_course(result.value(name_field).toString(), true);
    }
}

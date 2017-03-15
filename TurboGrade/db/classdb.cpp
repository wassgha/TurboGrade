#include "classdb.h"

/**
 * @brief Default constructor
 */
ClassDB::ClassDB()
{

}

/**
 * @brief Destructor
 */

ClassDB::~ClassDB() {

}

/**
 * @brief ClassDB::add Insert a row to the database
 * @param name the name of the class (ex. CS150)
 * @return true if the query succeded
 */
bool ClassDB::add(const QString name) {

    QSqlQuery query;

    query.prepare("INSERT INTO class (id, name) "
                  "VALUES (NULL, ?)");
    query.addBindValue(name);

    if (!query.exec()) {
        qDebug() << "Failed to insert to 'class' table" << endl << "SQL ERROR: " << query.lastError();
        return false;
    }

    return true;
}


/**
 * @brief ClassDB::select Returns id of the row
 * that matches given name
 * @param name the name of the class (ex. CS150)
 * @return the resulting rows
 */
int ClassDB::select(const QString name) {

    QSqlQuery query;

    query.prepare("SELECT * FROM class WHERE name = ?");
    query.addBindValue(name);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to select from table 'class'" << endl << "SQL ERROR: " << query.lastError();
        return NULL;
    }

    // Return the row ID
    if (query.next()) {
        int id_field = query.record().indexOf("id");
        return query.value(id_field).toInt();
    }

    // No rows found matching the query
    return NULL;
}

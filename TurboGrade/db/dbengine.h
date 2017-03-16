#ifndef DBENGINE_H
#define DBENGINE_H

/**
 * @brief Class DBEngine manages the database
 * connections (interfaces SQLite), creates the
 * necessary tables for the application and serves
 * as a parent to all table classes
 */

#include <iostream>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>

class DBEngine
{
public:
    // Constructor
    DBEngine(QString connectionName = "EngineDB");
    // Destructor
    ~DBEngine();
protected:
    // Executes SQL query
    void sql_query(const QString &query_text);
    QSqlDatabase db;
    QString _connectionName;
};

#endif // DBENGINE_H

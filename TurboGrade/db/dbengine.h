#ifndef DBENGINE_H
#define DBENGINE_H


#include <iostream>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QtSql>

class DBEngine
{
public:
    DBEngine();
    ~DBEngine();
protected:
    // Executes SQL query
    void sql_query(const QString &query_text);
    QSqlDatabase db;
};

#endif // DBENGINE_H

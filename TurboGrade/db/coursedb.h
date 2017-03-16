#ifndef COURSEDB_H
#define COURSEDB_H

/**
 * @brief CourseDB is the interface for the
 * course database table. It is used to add
 * and retrieve rows from the table.
 */

#include "dbengine.h"
#include "../engine/coursecontroller.h"

class CourseController;

class CourseDB : public DBEngine
{
public:
    // Constructor
    CourseDB();
    // Parametrized constructor
    CourseDB(CourseController *courseController):
        DBEngine("CourseDB"),
        _courseController(courseController){};
    // Destructor
    ~CourseDB();
    // Adds a row to the table
    bool add(const QString name);
    // Gets row id matching name
    int select(const QString name);
    // Selects all records
    QSqlQuery select_all();
    // Load to controller
    void load_all();
    // Course Controller
    CourseController* _courseController;
};

#endif // COURSEDB_H

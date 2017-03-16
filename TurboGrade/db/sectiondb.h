#ifndef SECTIONDB_H
#define SECTIONDB_H

/**
 * @brief SectionDB is the interface for the
 * section database table. It is used to add
 * and retrieve rows from the table.
 */

#include "dbengine.h"
#include "../engine/coursecontroller.h"

class CourseController;

class SectionDB : public DBEngine
{
public:
    // Constructor
    SectionDB();
    // Parametrized constructor
    SectionDB(CourseController *courseController):
        DBEngine("SectionDB"),
        _courseController(courseController){};
    // Destructor
    ~SectionDB();
    // Adds a row to the table
    bool add(int course_id, const QString name);
    // Gets row id matching name
    int select(const QString course_name, const QString name);
    // Selects all records
    QSqlQuery select_all();
    // Load to controller
    void load_all();
    // Course Controller
    CourseController* _courseController;
};

#endif // SECTIONDB_H

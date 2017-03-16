#ifndef STUDENTDB_H
#define STUDENTDB_H

/**
 * @brief StudentDB is the interface for the
 * student database table. It is used to add
 * and retrieve rows from the table.
 */

#include "dbengine.h"
#include "../engine/coursecontroller.h"

class CourseController;

class StudentDB : public DBEngine
{
public:
    // Constructor
    StudentDB();
    // Parametrized constructor
    StudentDB(CourseController *courseController):
        DBEngine("StudentDB"),
        _courseController(courseController){}
    // Destructor
    ~StudentDB();


    // Adds a row to the table
    bool add(int section_id, const QString name);
    // Gets row id matching student identifier
    int select(const QString name);
    // Load all students to controller
    void load_all();
    // Load students for a specific section to controller
    void load_section_students(QString course_name, QString section_name);

    // Course Controller
    CourseController* _courseController;
};

#endif // STUDENTDB_H

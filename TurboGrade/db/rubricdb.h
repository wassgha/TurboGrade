#ifndef RUBRICDB_H
#define RUBRICDB_H

/**
 * @brief RubricDB is the interface for the
 * rubric database table. It is used to add
 * and retrieve rows from the table.
 */

#include "dbengine.h"
#include "../engine/assignmentcontroller.h"
#include "../engine/coursecontroller.h"

class AssignmentController;

class RubricDB : public DBEngine
{
public:
    // Constructor
    RubricDB();
    // Parametrized constructor
    RubricDB(AssignmentController *assignmentController, CourseController *courseController):
        DBEngine("RubricDB"),
        _assignmentController(assignmentController),
        _courseController(courseController){}
    // Destructor
    ~RubricDB();


    // Adds a row to the table
    bool add_criterion(const QString name, int assignment_id, int parent_id, int out_of);
    // Gets row id matching rubric criterion
    int select(int assignment_id, const QString name);
    // Loads rubrics and links them to the controller
    void load_all();
    // Loads rubric for a specific assignment
    void load_assignment_criteria(int assignment_id);


    // Assignment Controller
    AssignmentController* _assignmentController;
    // Course Controller
    CourseController* _courseController;
};

#endif // RUBRICDB_H

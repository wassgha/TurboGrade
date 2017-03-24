#ifndef ASSIGNMENTDB_H
#define ASSIGNMENTDB_H

/**
 * @brief AssignmentDB is the interface for the
 * assignments database table. It is used to add
 * and retrieve rows from the table.
 */

#include "dbengine.h"
#include "../engine/controller.h"

class Controller;

class AssignmentDB : public DBEngine
{
public:
    // Constructor
    AssignmentDB();
    // Parametrized constructor
    AssignmentDB(Controller *controller):
        DBEngine("AssignmentDB"),
        _controller(controller){}
    // Destructor
    ~AssignmentDB();


    // Adds a row to the table
    bool add(const QString name, const QString objective);
    // Link assignment to section
    bool link(int assignment_id, int section_id, const QString folder);
    // Gets row id matching name
    int select(const QString name);
    // Loads assignments and links them to sections in the controller
    void load_all();
    // Loads assignments for a specific section and links them
    void load_section_assignments(QString course_name, QString section_name);


    // Controller
    Controller* _controller;
};

#endif // ASSIGNMENTDB_H

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
    AssignmentDB(Controller *controller, QString dbname):
        DBEngine("AssignmentDB", dbname),
        _controller(controller){}
    // Destructor
    ~AssignmentDB();


    // Adds a row to the table
    int add(const QString name, const QString objective, bool full_grade);
    // Remove a row from the table
    void remove(int assignment_id);
    // Update a row from the table
    int update(const QString name, const QString objective, bool full_grade, int assignment_id);
    // Link assignment to section
    bool link(int assignment_id, int section_id);
    // Remove link from assignment to section
    void remove_link(int assignment_id, int section_id);
    // Gets row id matching name
    int select(const QString name);
    // Load to controller
    void load_all();
    // Load assignment-section links for a specific section
    void load_all(Section *section);


    // Controller
    Controller* _controller;
};

#endif // ASSIGNMENTDB_H

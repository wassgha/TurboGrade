#ifndef SECTIONDB_H
#define SECTIONDB_H

/**
 * @brief SectionDB is the interface for the
 * section database table. It is used to add
 * and retrieve rows from the table.
 */

#include "dbengine.h"
#include "../engine/controller.h"

class Controller;

class SectionDB : public DBEngine
{
public:
    // Constructor
    SectionDB(Controller *controller, QString dbname):
        DBEngine("SectionDB", dbname),
        _controller(controller){}
    // Destructor
    ~SectionDB();


    // Adds a row to the table
    int add(int course_id, const QString name);
    // Removes a row from the table
    void remove(int section_id);
    // Gets row id matching name
    int select(const QString course_name, const QString name);
    // Load all sections to controller
    void load_all(Course* course);

    //Controller
    Controller *_controller;
};

#endif // SECTIONDB_H

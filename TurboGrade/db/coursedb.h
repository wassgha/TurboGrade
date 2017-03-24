#ifndef COURSEDB_H
#define COURSEDB_H

/**
 * @brief CourseDB is the interface for the
 * course database table. It is used to add
 * and retrieve rows from the table.
 */

#include "dbengine.h"
#include "../engine/controller.h"

class Controller;

class CourseDB : public DBEngine
{
public:
    // Constructor
    CourseDB();
    // Parametrized constructor
    CourseDB(Controller *controller):
        DBEngine("CourseDB"),
        _controller(controller){}
    // Destructor
    ~CourseDB();


    // Adds a row to the table
    bool add(const QString name);
    // Gets row id matching name
    int select(const QString name);
    // Load to controller
    void load_all();


    // Controller
    Controller* _controller;
};

#endif // COURSEDB_H

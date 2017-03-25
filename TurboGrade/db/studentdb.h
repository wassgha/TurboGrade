#ifndef STUDENTDB_H
#define STUDENTDB_H

/**
 * @brief StudentDB is the interface for the
 * student database table. It is used to add
 * and retrieve rows from the table.
 */

#include "dbengine.h"
#include "../engine/controller.h"
#include "../engine/section.h"

class Controller;
class Section;

class StudentDB : public DBEngine
{
public:
    // Constructor
    StudentDB();
    // Parametrized constructor
    StudentDB(Controller *controller):
        DBEngine("StudentDB"),
        _controller(controller){}
    // Destructor
    ~StudentDB();


    // Adds a row to the table
    int add(int section_id, const QString name, const QString username);
    // Gets row id matching student
    int select(const QString course_name, const QString section_name, const QString name, const QString username);
    // Load students for a specific section to controller
    void load_all(Section* section);
    // Controller
    Controller* _controller;
};

#endif // STUDENTDB_H

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
    // Parametrized constructor
    StudentDB(Controller *controller, QString dbname):
        DBEngine("StudentDB", dbname),
        _controller(controller){}
    // Destructor
    ~StudentDB();


    // Adds a row to the table
    int add(int section_id, const QString name);
    // Gets row id matching student
    int select(const QString course_name, const QString section_name, const QString name);
    // Update row in the table
    void update(const QString name, int student_id);
    // Load students for a specific section to controller
    void load_all(Section* section);
    // Remove a row from the table
    void remove(int student_id);
    // Controller
    Controller* _controller;
};

#endif // STUDENTDB_H

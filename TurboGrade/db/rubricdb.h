#ifndef RUBRICDB_H
#define RUBRICDB_H

/**
 * @brief RubricDB is the interface for the
 * rubric database table. It is used to add
 * and retrieve rows from the table.
 */

#include "dbengine.h"
#include "../engine/controller.h"

class Controller;

class RubricDB : public DBEngine
{
public:

    // Parametrized constructor
    RubricDB(Controller *controller, QString dbname):
        DBEngine("RubricDB", dbname),
        _controller(controller){}
    // Destructor
    ~RubricDB();


    // Adds a row to the table
    int add_criterion(const QString name, int assignment_id, int parent_id, int out_of);
    // Gets row id matching rubric criterion
    int select(int assignment_id, const QString name);
    // Loads criteria to a rubric
    void load_parent_criteria(Rubric *rubric);
    // Loads children criteria for a specific criterion
    void load_sub_criteria(Criterion *criterion);


    // Controller
    Controller* _controller;
};

#endif // RUBRICDB_H

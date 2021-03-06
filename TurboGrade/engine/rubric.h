#ifndef RUBRIC_H
#define RUBRIC_H

/**
 * @brief The Rubric class defines the
 * hierarchy of criteria that belong to a
 * certain assignment
 */

#include <iostream>
#include <vector>
#include <QString>
#include <QObject>

#include "../tools/macro.h"
#include "../tools/objectidentifier.h"

#include "controller.h"
#include "assignment.h"
#include "criterion.h"

class Controller;
class Assignment;
class Criterion;

class Rubric : public ObjectIdentifier, public QObject
{
public:
    Rubric() = delete; //don't allow default constructor
    // Parametrized constructor
    Rubric(Assignment* assignment, Controller * controller);
    // Destructor
    ~Rubric();
    // Add a criterion to the rubric
    Criterion* add_criterion(const QString name, Criterion* parent, int out_of, int id = -1);
    // Get a criterion by name
    Criterion* get_criterion(const QString name);
    // Get a criterion by table id
    Criterion* get_criterion(const int id);
    // Delete a criterion from a rubric
    void remove_criterion(Criterion* criterion);
    // Get the total grade for this rubric
    int total_grade();
    std::vector<Criterion*>* getCriterions();

    // Assignment
    Assignment* _assignment;
    // Rubric criteria
    std::vector<Criterion*> *_criteria;
    // Controller
    Controller *_controller;
};

#endif // RUBRIC_H

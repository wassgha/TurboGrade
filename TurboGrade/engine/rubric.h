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

#include "../tools/macro.h"
#include "../tools/objectidentifier.h"

#include "controller.h"
#include "assignment.h"
#include "criterion.h"

class Controller;
class Assignment;
class Criterion;

class Rubric : public ObjectIdentifier
{
public:
    // Constructor
    Rubric();
    // Parametrized constructor
    Rubric(Assignment* assignment, Controller * controller);
    // Destructor
    ~Rubric();
    // Add a criterion to the rubric
    Criterion* add_criterion(int id, const QString name, Criterion* parent, int out_of);
    // Get a criterion by name
    Criterion* get_criterion(const QString name);

    // Assignment
    Assignment* _assignment;
    // Rubric criteria
    std::vector<Criterion*> *_criteria;
    // Controller
    Controller *_controller;
};

#endif // RUBRIC_H

#ifndef RUBRIC_H
#define RUBRIC_H

#include <iostream>
#include <vector>
#include <QString>

#include "assignment.h"
#include "criterion.h"

class Assignment;
class Criterion;

class Rubric
{
public:
    // Constructor
    Rubric();
    // Parametrized constructor
    Rubric(Assignment* assignment);
    // Destructor
    ~Rubric();
    // Add a criterion to the rubric
    void add_criterion(const QString name, Criterion* parent, int out_of);
    // Get a criterion by name
    Criterion* get_criterion(const QString name);

    // Course
    Assignment* _assignment;
    // Rubric criteria
    std::vector<Criterion*> _criteria;
};

#endif // RUBRIC_H

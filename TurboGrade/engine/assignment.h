#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

#include <iostream>
#include <vector>
#include <QString>
#include "assignment.h"
#include "rubric.h"

class Rubric;

class Assignment
{
public:
    // Constructor
    Assignment();
    // Parametrized constructor
    Assignment(const QString name, const QString objective);
    // Destructor
    ~Assignment();

    QString _name;
    QString _objective;
    Rubric* _rubric;
};

#endif // ASSIGNMENT_H

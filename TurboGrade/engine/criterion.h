#ifndef CRITERION_H
#define CRITERION_H

#include <iostream>
#include <vector>
#include <QString>

#include "rubric.h"

class Rubric;

class Criterion
{
public:
    // Constructor
    Criterion();
    // Parametrized constructor
    Criterion(const QString name, Criterion* parent, int out_of, Rubric* rubric);
    // Destructor
    ~Criterion();

    // Student's section
    Rubric* _rubric = nullptr;
    // Criterion's parent (nullpointer if this is a parent)
    Criterion* _parent = nullptr;
    // Student name
    QString _name;
    // Maximum grade for this criterion (0 if extra-credit)
    int _out_of;
};

#endif // CRITERION_H

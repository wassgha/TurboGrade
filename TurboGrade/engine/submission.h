#ifndef SUBMISSION_H
#define SUBMISSION_H

#include <iostream>
#include <vector>
#include <QString>
#include "assignment.h"

class Submission
{
public:
    // Constructor
    Submission();
    // Parametrized constructor
    Submission(Assignment* assignment);
    // Destructor
    ~Submission();

    // Submission assignment
    Assignment* _assignment = nullptr;
};

#endif // SUBMISSION_H

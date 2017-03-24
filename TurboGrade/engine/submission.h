#ifndef SUBMISSION_H
#define SUBMISSION_H

/**
 * @brief The Submission class holds information
 * about a single submission (by whom and for which
 * assignment).
 */


#include <iostream>
#include <vector>
#include <QString>
#include "assignment.h"
#include "student.h"

class Student;

class Submission
{
public:
    // Constructor
    Submission();
    // Parametrized constructor
    Submission(Assignment* assignment, Student* student);
    // Destructor
    ~Submission();

    // Submission belongs to student
    Student* _student;
    // Submission assignment
    Assignment* _assignment = nullptr;
};

#endif // SUBMISSION_H

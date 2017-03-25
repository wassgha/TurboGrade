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

#include "../tools/macro.h"
#include "../tools/objectidentifier.h"

#include "controller.h"
#include "assignment.h"
#include "student.h"

class Controller;
class Student;
class Assignment;

class Submission : public ObjectIdentifier
{
public:
    // Constructor
    Submission();
    // Parametrized constructor
    Submission(int id, Assignment* assignment, Student* student, Controller * controller);
    // Destructor
    ~Submission();

    // Submission id
    int _id;
    // Submission belongs to student
    Student* _student;
    // Submission assignment
    Assignment* _assignment = nullptr;
    // Controller
    Controller *_controller;
};

#endif // SUBMISSION_H

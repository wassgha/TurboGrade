#ifndef STUDENT_H
#define STUDENT_H

/**
 * @brief The Student class holds information
 * about a single student (name, ID, submissions).
 */

#include <iostream>
#include <vector>
#include <QString>

#include "../tools/macro.h"
#include "../tools/objectidentifier.h"

#include "controller.h"
#include "assignment.h"
#include "submission.h"
#include "section.h"

class Controller;
class Section;
class Submission;

class Student : public ObjectIdentifier
{
public:
    // Constructor
    Student();
    // Parametrized constructor
    Student(int id, QString name, QString username, Section* section, Controller * controller);
    // Destructor
    ~Student();
    // Add a student submission
    void add_submission(int id, Assignment* assignment);
    // Find a submission
    Submission* get_submission(Assignment* assignment);

    // Student id
    int _id;
    // Student's section
    Section* _section;
    // Student name
    QString _name;
    // Student username
    QString _username;
    // Student submissions
    std::vector<Submission*> *_submissions;
    // Controller
    Controller *_controller;
};

#endif // STUDENT_H

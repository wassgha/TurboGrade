#ifndef STUDENT_H
#define STUDENT_H

/**
 * @brief The Student class holds information
 * about a single student (name, ID, submissions).
 */

#include <iostream>
#include <vector>
#include <QString>
#include <QObject>

#include "../tools/macro.h"
#include "../tools/objectidentifier.h"

#include "controller.h"
#include "assignment.h"
#include "submission.h"
#include "section.h"

class Controller;
class Section;
class Submission;

class Student : public ObjectIdentifier, public QObject
{
public:
    Student() = delete; //don't allow default constructor
    // Parametrized constructor
    Student(QString name, Section* section, Controller * controller, int id = -1);
    // Destructor
    ~Student();
    // Add a student submission
    Submission* add_submission(Assignment* assignment, int status = 0, int id = -1);
    // Find a submission
    Submission* get_submission(Assignment* assignment);
    std::vector<Submission*>* get_submissions();

    // Student id
    int _id;
    // Student's section
    Section* _section;
    // Student name
    QString _name;
    // Student submissions
    std::vector<Submission*> *_submissions;
    // Color (for UI)
    QString _color;
    // Controller
    Controller *_controller;
};

#endif // STUDENT_H

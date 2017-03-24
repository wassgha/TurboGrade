#ifndef STUDENT_H
#define STUDENT_H

/**
 * @brief The Student class holds information
 * about a single student (name, ID, submissions).
 */

#include <iostream>
#include <vector>
#include <QString>
#include "assignment.h"
#include "submission.h"
#include "section.h"

class Section;
class Submission;

class Student
{
public:
    // Constructor
    Student();
    // Parametrized constructor
    Student(QString name, QString username, Section* section);
    // Destructor
    ~Student();
    // Add a student submission
    void add_submission(Assignment* assignment);
    // Find a submission
    Submission* get_submission(Assignment* assignment);

    // Student's section
    Section* _section;
    // Student name
    QString _name;
    // Student username
    QString _username;
    // Student submissions
    std::vector<Submission*> _submissions;
};

#endif // STUDENT_H

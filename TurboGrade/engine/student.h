#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <QString>
#include "assignment.h"
#include "submission.h"

class Student
{
public:
    // Constructor
    Student();
    // Parametrized constructor
    Student(QString name, QString username);
    // Destructor
    ~Student();
    // Add a student submission
    void add_submission(Assignment* assignment);
    // Find a submission
    Submission* get_submission(Assignment* assignment);

    // Student name
    QString _name;
    // Student username
    QString _username;
    // Student submissions
    std::vector<Submission*> _submissions;
};

#endif // STUDENT_H

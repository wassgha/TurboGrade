#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <vector>
#include <QString>

class Student
{
public:
    // Constructor
    Student();
    // Parametrized constructor
    Student(QString name);
    // Destructor
    ~Student();

    // Student name
    QString _name;
};

#endif // STUDENT_H

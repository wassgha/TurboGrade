#ifndef SECTION_H
#define SECTION_H

#include <iostream>
#include <vector>
#include <QString>
#include "student.h"

class Section
{
public:
    // Constructor
    Section();
    // Parametrized constructor
    Section(QString name);
    // Destructor
    ~Section();
    // Add a student to the section
    void add_student(const QString name);
    // Find a student in the section
    Student* get_student(const QString name);

    // Section name
    QString _name;
    // Section students
    std::vector<Student*> _students;
};

#endif // SECTION_H

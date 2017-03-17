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
    void add_student(const QString name, const QString username);
    // Add an assignment to the section
    void add_assignment(Assignment* assignment, QString folder);
    // Find a student in the section
    Student* get_student(const QString username);
    // Find an assignment in the section
    std::pair<Assignment*, QString> get_assignment(const QString name);

    // Section name
    QString _name;
    // Section students
    std::vector<Student*> _students;
    // Section assignments (assignment and folder)
    std::vector<std::pair<Assignment*, QString>> _assignments;
};

#endif // SECTION_H

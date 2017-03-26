#ifndef SECTION_H
#define SECTION_H

/**
 * @brief The Section class holds information
 * about a single section of a course (name of
 * section and students registered).
 */


#include <iostream>
#include <vector>
#include <QString>

#include "../tools/macro.h"
#include "../tools/objectidentifier.h"

#include "controller.h"
#include "course.h"
#include "assignment.h"
#include "student.h"

class Controller;
class Course;
class Student;
class Assignment;

class Section : public ObjectIdentifier
{
public:
    Section() = delete; //don't allow default constructor
    // Parametrized constructor
    Section(int id, QString name, Course* course, Controller * controller);
    // Destructor
    ~Section();
    // Add a student to the section
    Student* add_student(int id, const QString name, const QString username);
    // Add an assignment to the section
    std::pair<Assignment*, QString> add_assignment(Assignment* assignment, QString folder, bool load = false);
    // Find a student in the section
    Student* get_student(const QString username);
    // Find an assignment in the section
    std::pair<Assignment*, QString> get_assignment(const QString name);

    // Section id
    int _id;
    // Course
    Course* _course;
    // Section name
    QString _name;
    // Section students
    std::vector<Student*> *_students;
    // Section assignments (assignment and folder)
    std::vector<std::pair<Assignment*, QString>> *_assignments;
    // Controller
    Controller *_controller;
};

#endif // SECTION_H

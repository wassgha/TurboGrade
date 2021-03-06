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
#include <QObject>

#include "../tools/macro.h"
#include "../tools/objectidentifier.h"

#include "controller.h"
#include "course.h"
#include "assignment.h"
#include "student.h"
#include "submission.h"

class Controller;
class Course;
class Student;
class Assignment;
class Submission;

class Section : public ObjectIdentifier, public QObject
{
public:
    Section() = delete; //don't allow default constructor
    // Parametrized constructor
    Section(QString name, Course* course, Controller * controller, int id = -1);
    // Update Section
    void update(QString name);
    // Destructor
    ~Section();
    // Add a student to the section
    Student* add_student(const QString name, int id = -1);
    // Remove a student from the section
    void remove_student(Student *student, bool erase = true);
    // Add an assignment to the section
    Assignment* add_assignment(Assignment* assignment, bool load = false);
    // Remove an assignment from the section
    void remove_assignment(Assignment* assignment, bool erase = true);
    // Find a student in the section
    Student* get_student(const QString name);
    // Find an assignment in the section
    Assignment* get_assignment(const QString name);
    // Returns all assignments
    std::vector<Assignment*>* get_assignments();
    std::vector<Student*>* get_students();
    // Returns number of submissions for an assignment
    int num_submissions_total(Assignment* assignment);
    // Returns number of finalized (graded) submissions for an assignment
    int num_submissions_graded(Assignment* assignment);
    // Returns number of submission yet to grade for an assignment
    int num_submissions_ungraded(Assignment* assignment);
    // Get a random submission to grade
    Submission* get_random_ungraded(Assignment* assignment);

    // Section id
    int _id;
    // Course
    Course* _course;
    // Section name
    QString _name;
    // Section students
    std::vector<Student*> *_students;
    // Section assignments (assignment and folder)
    std::vector<Assignment*> *_assignments;
    // Color (for UI)
    QString _color;
    // Controller
    Controller *_controller;
};

#endif // SECTION_H

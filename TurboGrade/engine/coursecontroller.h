#ifndef CLASSCONTROLLER_H
#define CLASSCONTROLLER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "course.h"
#include "section.h"
#include "student.h"
#include "assignment.h"
#include "../db/coursedb.h"
#include "../db/sectiondb.h"
#include "../db/studentdb.h"

class CourseDB;
class SectionDB;
class StudentDB;

class CourseController
{
public:
    // Constructor
    CourseController();
    // Destructor
    ~CourseController();

    // Add a course to the software
    void add_course(const QString name,
                    bool load = false);
    // Adds a section to a course
    void add_section(const QString course_name,
                     const QString name,
                     bool load = false);
    // Adds a student to a section
    void add_student(const QString course_name,
                     const QString section_name,
                     const QString name,
                     const QString username,
                     bool load = false);
    // Adds an assignment to a section
    void link_assignment(const QString course_name,
                         const QString section_name,
                         Assignment    *assignment,
                         const QString folder);


    // Searches for a course by name and returns it
    Course* get_course(const QString name);

    // Clears all locally cached course data (sections)
    void clear_course(const QString course_name);

    // Clears all locally cached section data (students)
    void clear_section_students(const QString course_name,
                                const QString section_name);

    // Clears all locally cached section data (assignments)
    void clear_section_assignments(const QString course_name,
                                   const QString section_name);

    // Clears all locally cached student data (submissions)
    void clear_student_submissions(const QString course_name,
                                   const QString section_name,
                                   const QString username);

    // Prints all courses and sections
    void show_courses();


    /*
     * Database containers
     */

    // Course database table
    CourseDB *_courseDB;
    // Section database table
    SectionDB *_sectionDB;
    // Student database table
    StudentDB *_studentDB;

private:
    /*
     * Local containers
     */

    // All courses in the engine
    std::vector<Course*> _courses;
};

#endif // CLASSCONTROLLER_H

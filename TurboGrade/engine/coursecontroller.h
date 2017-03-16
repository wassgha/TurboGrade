#ifndef CLASSCONTROLLER_H
#define CLASSCONTROLLER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "course.h"
#include "../db/coursedb.h"
#include "../db/sectiondb.h"

class CourseDB;
class SectionDB;

class CourseController
{
public:
    // Constructor
    CourseController();
    // Destructor
    ~CourseController();
    // Add a course to the software
    void add_course(const QString name, bool load = false);
    // Searches for a course by name and returns it
    Course* get_course(const QString name);
    // Adds a section to a course
    void add_section(const QString course_name, const QString name, bool load = false);
    // Prints all courses and sections
    void show_courses();


private:
    /*
     * Local containers
     */

    // All courses in the engine
    std::vector<Course*> _courses;

    /*
     * Database containers
     */

    // Course database table
    CourseDB *_courseDB;
    // Section database table
    SectionDB *_sectionDB;
};

#endif // CLASSCONTROLLER_H

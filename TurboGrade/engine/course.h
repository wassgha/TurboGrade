#ifndef COURSE_H
#define COURSE_H

/**
 * @brief The Course class contains information
 * about a course (name and sections) and is used
 * to manage the course
 */


#include <iostream>
#include <vector>
#include <QString>
#include "section.h"

class Section;

class Course
{
public:
    // Constructor
    Course();
    // Parametrized constructor
    Course(QString name);
    // Destructor
    ~Course();
    // Add a section to the course
    void add_section(const QString name);
    // Find a section in the course
    Section* get_section(const QString name);

    // Class name
    QString _name;
    // Class sections
    std::vector<Section*> _sections;
};

#endif // COURSE_H

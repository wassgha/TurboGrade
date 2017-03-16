#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <vector>
#include <QString>
#include "section.h"

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

    // Class name
    QString _name;
    // Class sections
    std::vector<Section*> _sections;
};

#endif // COURSE_H

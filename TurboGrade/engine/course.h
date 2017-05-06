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
#include <QObject>

#include "../tools/macro.h"
#include "../tools/objectidentifier.h"

#include "controller.h"
#include "section.h"

class Controller;
class Section;
class CourseDB;

class Course : public ObjectIdentifier, public QObject
{
public:

    Course() = delete; //don't allow default constructor
    // Parametrized constructor
    Course(QString name, QString semester, Controller * controller, int id = -1);
    // Update Course
    void update(QString name, QString semester);
    // Destructor
    ~Course();
    // Add a section to the course
    Section* add_section(const QString name, int id = -1);
    // Remove a section from the course
    void remove_section(Section *section);
    // Find a section in the course
    Section* get_section(const QString name);
    // Gets all sections in the course
    std::vector<Section*>* get_sections();

    // Class id
    int _id;
    // Class name
    QString _name;
    // Class semester
    QString _semester;
    // Class sections
    std::vector<Section*> *_sections;
    // Controller
    Controller *_controller;
    // Color (for UI)
    QString _color;
};

#endif // COURSE_H

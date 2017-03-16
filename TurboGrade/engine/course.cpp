#include "course.h"

Course::Course()
{
    std::cerr<<"Please provide course name.";
    exit(0);
}

Course::Course(QString name)
{
    _name = name;
}

Course::~Course()
{
    _sections.clear();
}

/**
 * @brief Course::add_section adds a section to this course
 * @param name name of the section
 */
void Course::add_section(const QString name) {

    Section *new_section = new Section(name);

    _sections.push_back(new_section);
}

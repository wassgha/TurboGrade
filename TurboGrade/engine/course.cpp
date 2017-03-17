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
    for(Section* section:_sections)
        delete section;
}

/**
 * @brief Course::add_section adds a section to this course
 * @param name name of the section
 */
void Course::add_section(const QString name) {

    Section *new_section = new Section(name);

    _sections.push_back(new_section);
}

/**
 * @brief Course::get_section finds a section by its name
 * @param name the name of the section to search for
 * @return the section found
 */
Section* Course::get_section(const QString name) {
    for(Section* section:_sections)
        if (section->_name == name)
            return section;
    return nullptr;
}

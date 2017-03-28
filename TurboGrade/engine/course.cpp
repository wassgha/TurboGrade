#include "course.h"

Course::Course(int id, QString name, Controller* controller)
{
    SHOW_WHERE;

    _controller = controller;

    if (id == -1)
        _id = _controller->_courseDB->add(name);
    else
        _id = id;

    _name = name;
    _sections = new std::vector<Section*>();
    _color = _controller->rand_color();

    _controller->_sectionDB->load_all(this);
}

Course::~Course()
{
    for(Section* section:*_sections)
        delete section;
    delete _sections;
}

/**
 * @brief Course::add_section adds a section to this course
 * @param name name of the section
 */
Section* Course::add_section(int id, const QString name) {

    Section *new_section = new Section(id, name, this, _controller);

    _sections->push_back(new_section);

    return new_section;
}

/**
 * @brief Course::get_section finds a section by its name
 * @param name the name of the section to search for
 * @return the section found
 */
Section* Course::get_section(const QString name) {
    for(Section* section:*_sections)
        if (section->_name == name)
            return section;
    return nullptr;
}

/**
 * @brief Course::get_section finds a section by its name
 * @param name the name of the section to search for
 * @return the section found
 */
std::vector<Section*>* Course::get_sections() {

    return _sections;

}

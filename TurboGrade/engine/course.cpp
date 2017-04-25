#include "course.h"

/**
 * @brief Course::Course Constructor, creates a course
 * @param name          name of the course
 * @param semester      semester the course was taught in
 * @param controller    current controller object
 * @param id            -1 if new, table id if it exists
 */
Course::Course(QString name, QString semester, Controller* controller, int id)
{
    SHOW_WHERE;

    _controller = controller;

    // If id is -1 then we're creating locally and we should add to the database
    if (id == -1)
        _id = _controller->_courseDB->add(name, semester);
    else
        _id = id;

    _name = name;
    _semester = semester;
    _sections = new std::vector<Section*>();
    _color = _controller->rand_color();

    // Add semester to the semester model if it doesn't exist
    if (!_controller->_all_semesters.contains(_semester))
        _controller->_all_semesters<<_semester;

    // Load all sections for this course
    _controller->_sectionDB->load_all(this);
}

void Course::update(QString name, QString semester){

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
Section* Course::add_section(const QString name, int id) {

    Section *new_section = new Section(name, this, _controller, id);

    _sections->push_back(new_section);

    return new_section;
}

/**
 * @brief Course::remove_section removes a section from the course.
 * Also removes assignments and students in the section
 * @param section the section to remove
 */
void Course::remove_section(Section *section){
    if(section == nullptr){
        return;
    }
    // erase from DB
    _controller->_sectionDB->remove(section->_id);
    // erase section from sections vector
    _sections->erase(std::remove(_sections->begin(), _sections->end(), section),
                    _sections->end());
    for(Student *student: *section->_students){
        section->remove_student(student);
    }
    for(Assignment *assignment : *section->_assignments){
        section->remove_assignment(assignment);
    }
    delete section;
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

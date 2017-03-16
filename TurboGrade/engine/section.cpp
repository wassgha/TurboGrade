#include "section.h"

Section::Section()
{
    std::cerr<<"Please provide section name.";
    exit(0);
}

Section::Section(QString name)
{
    _name = name;
}

Section::~Section()
{
    _students.clear();
}


/**
 * @brief Section::add_student adds a student to this section
 * @param name name of the student
 */
void Section::add_student(const QString name) {

    Student *new_student = new Student(name);

    _students.push_back(new_student);
}

/**
 * @brief Section::get_student finds a section by its name
 * @param name the name of the student to search for
 * @return the student found
 */
Student* Section::get_student(const QString name) {
    for(Student* student:_students)
        if (student->_name == name)
            return student;
    return nullptr;
}

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
    for(Student* student:_students)
        delete student;
}


/**
 * @brief Section::add_student adds a student to this section
 * @param name name of the student
 * @param username identifier of the student
 */
void Section::add_student(const QString name, const QString username) {

    Student *new_student = new Student(name, username);

    _students.push_back(new_student);
}

/**
 * @brief Section::get_student finds a student by their username
 * @param username the student identifier
 * @return the student found
 */
Student* Section::get_student(const QString username) {
    for(Student* student:_students)
        if (student->_username == username)
            return student;
    return nullptr;
}

/**
 * @brief Section::add_assignment adds an assignment to this section
 * @param assignment a pointer to the assignment
 * @param folder the folder where submissions can be found
 */
void Section::add_assignment(Assignment* assignment, QString folder) {

    _assignments.push_back(std::make_pair(assignment, folder));

}

/**
 * @brief Section::get_assignment finds an assignment by its name
 * @param name the name of the assignment to search for
 * @return a pair containing the assignment and the folder the submissions are in
 */
std::pair<Assignment*, QString> Section::get_assignment(const QString name) {
    for(std::pair<Assignment*, QString> assignment:_assignments)
        if (assignment.first->_name == name)
            return assignment;
    std::cerr<<"Assignment not found";
    exit(0);
}

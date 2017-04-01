#include "section.h"

Section::Section(int id, QString name, Course* course, Controller* controller)
{

    SHOW_WHERE;

    _controller = controller;

    if (id == -1)
        _id = _controller->_sectionDB->add(course->_id, name);
    else
        _id = id;

    _name = name;
    _course = course;

    // Section students
    _students = new std::vector<Student*>();
    // Section assignments (assignment and folder)
    _assignments = new std::vector<std::pair<Assignment*, QString>>();

    _color = _controller->rand_color();


    _controller->_assignmentDB->load_all(this);
    _controller->_studentDB->load_all(this);
}

Section::~Section()
{
    for(Student* student:*_students)
        delete student;
    delete _students;

    delete _assignments;
}


/**
 * @brief Section::add_student adds a student to this section
 * @param name name of the student
 * @param username identifier of the student
 */
Student* Section::add_student(int id, const QString name, const QString username) {

    Student *new_student = new Student(id, name, username, this, _controller);

    _students->push_back(new_student);

    return new_student;
}

/**
 * @brief Section::get_student finds a student by their username
 * @param username the student identifier
 * @return the student found
 */
Student* Section::get_student(const QString username) {
    for(Student* student:*_students)
        if (student->_username == username)
            return student;
    return nullptr;
}

/**
 * @brief Section::add_assignment adds an assignment to this section
 * @param assignment a pointer to the assignment
 * @param folder the folder where submissions can be found
 */
std::pair<Assignment*, QString> Section::add_assignment(Assignment* assignment, QString folder, bool load) {

    std::pair<Assignment*, QString> new_assignment = std::make_pair(assignment, folder);

    _assignments->push_back(new_assignment);

    if (!load)
        _controller->_assignmentDB->link(assignment->_id, _id, folder);

    return new_assignment;
}

/**
 * @brief Section::get_assignment finds an assignment by its name
 * @param name the name of the assignment to search for
 * @return a pair containing the assignment and the folder the submissions are in
 */
std::pair<Assignment*, QString> Section::get_assignment(const QString name) {
    for(std::pair<Assignment*, QString> assignment:*_assignments)
        if (assignment.first->_name == name)
            return assignment;
    std::cerr<<"Assignment not found";
    exit(0);
}

#include "section.h"

Section::Section(QString name, Course* course, Controller* controller, int id)
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
    _assignments = new std::vector<Assignment*>();

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
Student* Section::add_student(const QString name, int id) {

    Student *new_student = new Student(name, this, _controller, id);

    _students->push_back(new_student);

    return new_student;
}

/**
 * @brief Section::get_student finds a student by their name
 * @param name the student identifier
 * @return the student found
 */
Student* Section::get_student(const QString name) {
    for(Student* student:*_students)
        if (student->_name == name)
            return student;
    return nullptr;
}

/**
 * @brief Section::add_assignment adds an assignment to this section
 * @param assignment a pointer to the assignment
 * @param folder the folder where submissions can be found
 */
Assignment* Section::add_assignment(Assignment* assignment, bool load) {


    _assignments->push_back(assignment);

    if (!load)
        _controller->_assignmentDB->link(assignment->_id, _id);

    return assignment;
}

/**
 * @brief Section::get_assignment finds an assignment by its name
 * @param name the name of the assignment to search for
 * @return a pair containing the assignment and the folder the submissions are in
 */
Assignment* Section::get_assignment(const QString name) {
    for(Assignment* assignment:*_assignments)
        if (assignment->_name == name)
            return assignment;
    std::cerr<<"Assignment not found";
    exit(0);
}

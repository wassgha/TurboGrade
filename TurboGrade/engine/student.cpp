#include "student.h"

Student::Student(QString name, Section* section, Controller * controller, int id)
{

    SHOW_WHERE;

    _controller = controller;

    if (id == -1)
        _id = _controller->_studentDB->add(section->_id, name);
    else
        _id = id;

    _name = name;
    _section = section;

    // Student submissions
    _submissions = new std::vector<Submission*>();

    _color = _controller->rand_color();

    _controller->_submissionDB->load_all(this);
}

Student::~Student()
{
    for(Submission* submission:*_submissions)
        delete submission;
    delete _submissions;
}


/**
 * @brief Student::add_submission adds a submission made by this student
 * @param assignment a pointer to the assignment the submission belongs to
 */
Submission* Student::add_submission(Assignment* assignment, int id) {

    Submission *new_submission = new Submission(assignment, this, _controller, id);

    _submissions->push_back(new_submission);

    return new_submission;
}

/**
 * @brief Student::get_submission finds a student by their username
 * @param assignment a pointer to the assignment the submission belong to
 * @return the submission found
 */
Submission* Student::get_submission(Assignment* assignment) {
    for(Submission* submission:*_submissions)
        if (submission->_assignment == assignment)
            return submission;
    return nullptr;
}

std::vector<Submission*>* Student::get_submissions() {

    return _submissions;

}

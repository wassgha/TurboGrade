#include "student.h"

/**
 * @brief Student::Student Constructor, creates a new student locally
 * @param name          name of the student
 * @param section       pointer to the section the student belongs to
 * @param controller    current controller object
 * @param id            -1 if this is to be added to the database or its id if it exists
 */
Student::Student(QString name, Section* section, Controller * controller, int id)
{

    SHOW_WHERE;

    _controller = controller;

    // If id is -1 then we're creating locally and we should add to the database
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

/**
 * @brief Student::~Student Destructor
 */
Student::~Student()
{
    for(Submission* submission:*_submissions)
        delete submission;
    delete _submissions;
}


/**
 * @brief Student::add_submission adds a submission made by this student
 * @param assignment a pointer to the assignment the submission belongs to
 * @param status whether the submission was graded or not
 */
Submission* Student::add_submission(Assignment* assignment, int status, int id) {

    Submission *new_submission = new Submission(assignment, this, _controller, status, id);

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

/**
 * @brief Student::remove_submission erases the submission from the database and
 * from the local C++ memory. Also will remove all comments made on the submission.
 * @param submission
 */
void Student::remove_submission(Submission *submission){
    if(submission == nullptr){
        return;
    }
    // erase from DB
    _controller->_submissionDB->remove(submission->_id);
    _controller->_gradeDB->remove(submission->_id);

    // erase all of submissions comments
    for(Comment *comment : *submission->_comments){
        submission->remove_comment(comment);
    }

    // erase submission from submissions vector
    _submissions->erase(std::remove(_submissions->begin(), _submissions->end(), submission),
                    _submissions->end());

    delete submission;
}

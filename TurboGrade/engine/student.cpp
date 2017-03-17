#include "student.h"

Student::Student()
{
    std::cerr<<"Please provide student name.";
    exit(0);
}

Student::Student(QString name, QString username)
{
    _name = name;
    _username = username;
}

Student::~Student()
{
    for(Submission* submission:_submissions)
        delete submission;
}


/**
 * @brief Student::add_submission adds a submission made by this student
 * @param assignment a pointer to the assignment the submission belongs to
 */
void Student::add_submission(Assignment* assignment) {

    Submission *new_submission = new Submission(assignment);

    _submissions.push_back(new_submission);
}

/**
 * @brief Student::get_submission finds a student by their username
 * @param assignment a pointer to the assignment the submission belong to
 * @return the submission found
 */
Submission* Student::get_submission(Assignment* assignment) {
    for(Submission* submission:_submissions)
        if (submission->_assignment == assignment)
            return submission;
    return nullptr;
}

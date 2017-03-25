#include "submission.h"

Submission::Submission()
{
    std::cerr<<"Please provide the assignment this submission belongs to.";
    exit(0);
}

Submission::Submission(int id, Assignment *assignment, Student* student, Controller * controller)
{

    SHOW_WHERE;

    _controller = controller;

    if (id == -1)
        _id = _controller->_submissionDB->add(student->_id, assignment->_id);
    else
        _id = id;

    _assignment = assignment;
    _student = student;
}

Submission::~Submission()
{
}

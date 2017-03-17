#include "submission.h"

Submission::Submission()
{
    std::cerr<<"Please provide the assignment this submission belongs to.";
    exit(0);
}

Submission::Submission(Assignment *assignment, Student* student)
{
    _assignment = assignment;
    _student = student;
}

Submission::~Submission()
{
}

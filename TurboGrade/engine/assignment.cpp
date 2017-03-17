#include "assignment.h"

Assignment::Assignment()
{
    std::cerr<<"Please provide information about this assignment.";
    exit(0);
}

Assignment::Assignment(const QString name, const QString objective)
{
    _name = name;
    _objective = objective;
    _rubric = new Rubric(this);
}

Assignment::~Assignment()
{
    delete _rubric;
}

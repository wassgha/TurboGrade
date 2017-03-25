#include "assignment.h"

Assignment::Assignment()
{
    std::cerr<<"Please provide information about this assignment.";
    exit(0);
}

Assignment::Assignment(int id, const QString name, const QString objective, Controller *controller)
{

    SHOW_WHERE;

    _controller = controller;

    if (id == -1)
        _id = _controller->_assignmentDB->add(name, objective);
    else
        _id = id;

    _name = name;
    _objective = objective;
    _rubric = new Rubric(this, controller);
}

Assignment::~Assignment()
{
    delete _rubric;
}

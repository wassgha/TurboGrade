#include "assignment.h"

Assignment::Assignment(const QString name, const QString objective, Controller *controller, int id)
{

    SHOW_WHERE;

    _controller = controller;

    if (id == -1)
        _id = _controller->_assignmentDB->add(name, objective);
    else
        _id = id;

    _name = name;
    _objective = objective;

    _color = _controller->rand_color();
    _rubric = new Rubric(this, controller);
}

Assignment::~Assignment()
{
    delete _rubric;
}

#include "assignment.h"

Assignment::Assignment(const QString name, const QString objective, Controller *controller, bool full_grade, int id)
{

    SHOW_WHERE;

    _controller = controller;

    if (id == -1)
        _id = _controller->_assignmentDB->add(name, objective, full_grade);
    else
        _id = id;

    _name = name;
    _objective = objective;

    _full_grade = full_grade;

    _color = _controller->rand_color();
    _rubric = new Rubric(this, controller);
}

Assignment::~Assignment()
{
    delete _rubric;
}

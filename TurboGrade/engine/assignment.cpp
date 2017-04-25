#include "assignment.h"

/**
 * @brief Assignment::Assignment Constructor, creates an assignment
 * given its name, objective and parameters
 * @param name          name of the assignment
 * @param objective     objective of the assignment (short text)
 * @param controller    current controller object
 * @param full_grade    whether we start grading with full grades or at 0
 * @param id            -1 if new or the id in the database if it exists
 */
Assignment::Assignment(const QString name, const QString objective, Controller *controller, bool full_grade, int id)
{

    SHOW_WHERE;

    _controller = controller;

    // If id is -1 then we're creating locally and we should add to the database
    if (id == -1)
        _id = _controller->_assignmentDB->add(name, objective, full_grade);
    else
        _id = id;

    // Assign parameters
    _name = name;
    _objective = objective;
    _full_grade = full_grade;
    _color = _controller->rand_color();

    // Create the rubric
    _rubric = new Rubric(this, controller);
}

/**
 * @brief Assignment::update updates the assignment in memory and in DB
 * @param name the new assignment name
 * @param objective the new objective
 * @param full_grade the option to grade starting at max (true) or 0 (false)
 */
void Assignment::update(const QString name, const QString objective, bool full_grade){

}

/**
 * @brief Assignment::~Assignment Destructor
 */
Assignment::~Assignment()
{
    delete _rubric;
}

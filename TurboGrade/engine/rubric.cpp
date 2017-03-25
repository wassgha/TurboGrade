#include "rubric.h"

Rubric::Rubric()
{
    std::cerr<<"Please provide rubric information.";
    exit(0);
}

Rubric::Rubric(Assignment* assignment, Controller * controller)
{
    SHOW_WHERE;

    _controller = controller;

    _assignment = assignment;

    _criteria = new std::vector<Criterion*>();

    _controller->_rubricDB->load_parent_criteria(this);
}

Rubric::~Rubric()
{
    for(Criterion* criterion:*_criteria)
        delete criterion;
    delete _criteria;
}


/**
 * @brief Rubric::add_criterion adds a criterion to this rubric
 * @param name name of the criterion
 * @param parent parent of the criterion if it exists (other wise criterion is general)
 * @param out_of the maximum score for this criterion
 */
Criterion* Rubric::add_criterion(int id, const QString name, Criterion* parent, int out_of) {

    Criterion *new_criterion = new Criterion(id, name, parent, out_of, this, _controller);

    if (parent != nullptr)
        parent->add_child(new_criterion);
    else
        _criteria->push_back(new_criterion);

    return new_criterion;
}

/**
 * @brief Rubric::get_criterion finds a criterion by its name
 * @param name the name of the criterion
 * @return the criterion found
 */
Criterion* Rubric::get_criterion(const QString name) {
    for(Criterion* criterion:*_criteria) {
        if (criterion->find_criterion(name) != nullptr)
            return criterion->find_criterion(name);
    }
    return nullptr;
}

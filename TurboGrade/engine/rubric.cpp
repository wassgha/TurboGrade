#include "rubric.h"

Rubric::Rubric()
{
    std::cerr<<"Please provide rubric information.";
    exit(0);
}

Rubric::Rubric(Assignment* assignment)
{
    _assignment = assignment;
}

Rubric::~Rubric()
{
    for(Criterion* criterion:_criteria)
        delete criterion;
}


/**
 * @brief Rubric::add_criterion adds a criterion to this rubric
 * @param name name of the criterion
 * @param parent parent of the criterion if it exists (other wise criterion is general)
 * @param out_of the maximum score for this criterion
 */
void Rubric::add_criterion(const QString name, Criterion* parent, int out_of) {

    Criterion *new_criterion = new Criterion(name, parent, out_of, this);

    if (parent != nullptr)
        parent->add_child(new_criterion);
    else
        _criteria.push_back(new_criterion);
}

/**
 * @brief Rubric::get_criterion finds a criterion by its name
 * @param name the name of the criterion
 * @return the criterion found
 */
Criterion* Rubric::get_criterion(const QString name) {
    for(Criterion* criterion:_criteria) {
        if (criterion->find_criterion(name) != nullptr)
            return criterion->find_criterion(name);
    }
    return nullptr;
}

#include "rubric.h"

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
Criterion* Rubric::add_criterion(const QString name, Criterion* parent, int out_of, int id) {

    Criterion *new_criterion = nullptr;

    if (parent != nullptr) {
        new_criterion = parent->add_child(name, parent, out_of, id);
    } else {
        new_criterion = new Criterion(name, parent, out_of, this, _controller, id);
        _criteria->push_back(new_criterion);
    }

    return new_criterion;
}

/**
 * @brief Rubric::get_criterion finds a criterion by its name
 * @param name the name of the criterion
 * @return the criterion found
 */
Criterion* Rubric::get_criterion(const QString name) {
    for(Criterion* criterion:*_criteria) {
        Criterion* found_criterion = criterion->find_criterion(name);
        if (found_criterion != nullptr)
            return found_criterion;
    }
    return nullptr;
}

/**
 * @brief Rubric::get_criterion finds a criterion by its name
 * @param id the table id of the criterion
 * @return the criterion found
 */
Criterion* Rubric::get_criterion(const int id) {
    for(Criterion* criterion:*_criteria) {
        Criterion* found_criterion = criterion->find_criterion(id);
        if (found_criterion != nullptr)
            return found_criterion;
    }
    return nullptr;
}

/**
 * @brief Rubric::total_grade gets the total grade for this rubric
 * @return the total grade (sum of grades of individual criteria
 */
int Rubric::total_grade() {
    int grade = 0;
    for(Criterion* criterion:*_criteria) {
        grade += criterion->total_grade();
    }
    return grade;
}

#include "criterion.h"

Criterion::Criterion(int id, const QString name, Criterion* parent, int out_of, Rubric* rubric, Controller * controller)
{
    SHOW_WHERE;

    _controller = controller;

    if (id == -1)
        _id = _controller->_rubricDB->add_criterion(name,
                                                    rubric->_assignment->_id,
                                                    (parent ? parent->_id : -1),
                                                    out_of);
    else
        _id = id;

    _name = name;
    _parent = parent;
    _out_of = out_of;
    _rubric = rubric;

    _sub_criteria = new std::vector<Criterion*>();

    _controller->_rubricDB->load_sub_criteria(this);
}


Criterion::~Criterion()
{
    for(Criterion* criterion:*_sub_criteria)
        delete criterion;

    delete _sub_criteria;
}

/**
 * @brief Criterion::add_child adds a child criterion to the hierarchy
 * @param child a pointer to the child criterion
 */

void Criterion::add_child(Criterion *child)
{
    _sub_criteria->push_back(child);
}

/**
 * @brief Criterion::find_criterion finds a criterion in the sub-tree
 * rooted at the current criterion
 *
 * @param name name of the criterion we are searching for
 * @return a pointer to the criterion found
 */

Criterion* Criterion::find_criterion(const QString name)
{
    if (_name == name)
        return this;

    for(Criterion* criterion:*_sub_criteria) {
        Criterion *found_criterion = criterion->find_criterion(name);
        if (found_criterion != nullptr)
            return found_criterion;
    }

    return nullptr;
}

/**
 * @brief Criterion::find_criterion finds a criterion in the sub-tree
 * rooted at the current criterion
 *
 * @param id table id of the criterion we are searching for
 * @return a pointer to the criterion found
 */

Criterion* Criterion::find_criterion(const int id)
{
    if (_id == id)
        return this;

    for(Criterion* criterion:*_sub_criteria) {
        Criterion *found_criterion = criterion->find_criterion(id);
        if (found_criterion != nullptr)
            return found_criterion;
    }

    return nullptr;
}

/**
 * @brief Criterion::show_children shows the criteria tree
 */

void Criterion::show_children()
{
    for(Criterion *criterion : *_sub_criteria) {
        std::cout<<"        ->"<<(criterion->_name).toUtf8().data()<< " (? / " << criterion->_out_of << ")" << std::endl;
        criterion->show_children();
    }
}

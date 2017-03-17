#include "criterion.h"

Criterion::Criterion()
{
    std::cerr<<"Please provide criterion information.";
    exit(0);
}

Criterion::Criterion(const QString name, Criterion* parent, int out_of, Rubric* rubric)
{
    _name = name;
    _parent = parent;
    _out_of = out_of;
    _rubric = rubric;
}


Criterion::~Criterion()
{

}

/**
 * @brief Criterion::add_child adds a child criterion to the hierarchy
 * @param child a pointer to the child criterion
 */

void Criterion::add_child(Criterion *child)
{
    _sub_criteria.push_back(child);
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

    for(Criterion* criterion:_sub_criteria) {
        if (criterion->find_criterion(name) != nullptr)
            return criterion->find_criterion(name);
    }

    return nullptr;
}

/**
 * @brief Criterion::show_children shows the criteria tree
 */

void Criterion::show_children()
{
    for(Criterion *criterion : _sub_criteria) {
        std::cout<<"        ->"<<(criterion->_name).toUtf8().data()<< " (? / " << criterion->_out_of << ")" << std::endl;
        criterion->show_children();
    }
}

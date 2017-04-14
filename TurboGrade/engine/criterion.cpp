#include "criterion.h"

Criterion::Criterion(const QString name, Criterion* parent, int out_of, Rubric* rubric, Controller * controller, int id)
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

Criterion* Criterion::add_child(const QString name, Criterion* parent, int out_of, int id)
{
    if (_parent == nullptr) {
        Criterion* new_criterion = new Criterion(name, parent, out_of, _rubric, _controller, id);
        _sub_criteria->push_back(new_criterion);
        return new_criterion;
    } else {
        qDebug()<<"Can't add child criterion to a criterion that has a parent.";
        return nullptr;
    }
}

/**
 * @brief Criterion::has_children
 * @return whether this criterion has children or not
 */
bool Criterion::has_children() {
    return !_sub_criteria->empty();
}

/**
 * @brief Criterion::children
 * @return this criterion's children criteria
 */
std::vector<Criterion*> Criterion::children() {
    return *_sub_criteria;
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

/**
 * @brief Criterion::total_grade gets the total grade for this criterion
 * @return the total grade (sum of grades of individual criteria
 */
int Criterion::total_grade() {
    if (has_children()) {
        int grade = 0;
        for(Criterion* criterion:*_sub_criteria) {
            grade += criterion->total_grade();
        }
        return grade;
    } else {
        return _out_of;
    }
}

/**
 * @brief Criterion::in_order_names returns the string of all sub_criterion
 * names and this name
 * @return the string of all sub_criteria in_order_names and this name
 */
std::string Criterion::in_order_names() {
    std::string s = "";
    for(Criterion *crit : children()){
        s.append(crit->in_order_names());
        s.append(", ");
    }
    s.append(_name.toStdString());
    return s;
}

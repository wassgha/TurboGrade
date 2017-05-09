#include "criterion.h"

/**
 * @brief Criterion::Criterion Constructor creates a rubric item
 * @param name          description of the rubric item (ex. "Design")
 * @param parent        pointer to the parent (if sub-criterion), else nullptr
 * @param out_of        maximum grade attributed to the criterion
 * @param rubric        pointer to the rubric this criterion belongs to
 * @param controller    current controller
 * @param id            -1 if new, id if it exists in the database
 */
Criterion::Criterion(const QString name, Criterion* parent, int out_of, Rubric* rubric, Controller * controller, int id)
{
    SHOW_WHERE;

    _controller = controller;

    // If id is -1 then we're creating locally and we should add to the database
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

/**
 * @brief Criterion::update updates the Criterion in memory and the DB
 * @param name the name of the criterion
 * @param out_of the max grade
 */
void Criterion::update(const QString name, int out_of){
    if(out_of != _out_of){
        for(Course *course : *_controller->get_courses()){
            for(Section *section : *course->_sections){
                for(Student *student : *section->_students){
                    Submission *submission = student->get_submission(_rubric->_assignment);
                    // update the grade by subtracting old total and adding new
                    if(_rubric->_assignment->_full_grade){
                        submission->update_grade(this, submission->get_grade(this) - _out_of + out_of);
                    }
                }
            }
        }
    }

    _name = name;
    _out_of = out_of;

    _controller->_rubricDB->update(name, out_of, _id);
}

/**
 * @brief Criterion::~Criterion Destructor
 */

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

Criterion* Criterion::add_child(const QString name, int out_of, int id)
{
    if (_parent == nullptr) {
        Criterion* new_criterion = new Criterion(name, this, out_of, _rubric, _controller, id);
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
QString Criterion::in_order_names() {
    QString s = "";
    for(Criterion *crit : children()){
        s += crit->in_order_names();
        s += ", ";
    }
    if (_parent != nullptr)
        s += _parent->_name + " - ";
    s += _name + " (" + QString::number(_out_of) + ")";
    return s;
}

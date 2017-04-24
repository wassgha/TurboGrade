#include "rubric.h"

/**
 * @brief Rubric::Rubric Constructor
 * @param assignment    pointer to the constructor
 * @param controller    current controller object
 */
Rubric::Rubric(Assignment* assignment, Controller * controller)
{
    SHOW_WHERE;

    _controller = controller;

    _assignment = assignment;

    _criteria = new std::vector<Criterion*>();

    // load the criteria locally
    _controller->_rubricDB->load_parent_criteria(this);
}

/**
 * @brief Rubric::~Rubric Destructor
 */
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
        new_criterion = parent->add_child(name, out_of, id);
    } else {
        new_criterion = new Criterion(name, parent, out_of, this, _controller, id);
        _criteria->push_back(new_criterion);
    }

    return new_criterion;
}


/**
 * @brief Rubric::remove_criterion deletes a criterion from this rubric
 * @param criterion pointer to the criterion object to delete
 */
void Rubric::remove_criterion(Criterion* criterion) {

    // TO DO : REMOVE EVERYTHING THAT INVOLVES THE CRITERION
    // LIKE COMMENTS AND GRADES
    // TO DO : REMOVE CRITERION FROM DATABASE
    if (criterion != nullptr) {

        //REMOVE FROM RUBRIC CRITERIA VECTOR
        auto it = std::find(_criteria->begin(), _criteria->end(), criterion);
        if(it != _criteria->end())
            _criteria->erase(it);
        for (Criterion* parent : *_criteria) {
            it = std::find(parent->_sub_criteria->begin(), parent->_sub_criteria->end(), criterion);
            if(it != parent->_sub_criteria->end())
                parent->_sub_criteria->erase(it);
        }

        //REMOVE CRITERION FROM DB
        _controller->_rubricDB->remove(criterion->_id);
        for(Criterion *subCriterion : *criterion->_sub_criteria){
            _controller->_rubricDB->remove(subCriterion->_id);
        }

        //REMOVE COMMENTS RELATED TO CRITERION
        for(Course *course: *_controller->get_courses()){
            for(Section *section: *course->_sections){
                for(Student *student : *section->_students){
                    Submission *submission = student->get_submission(_assignment);
                    if(submission){
                        //remove comments related to sub criteria
                        for(Criterion *subCriterion : *criterion->_sub_criteria){
                            for(Comment *comment : submission->get_comments(subCriterion)){
                                submission->remove_comment(comment);
                            }
                        }
                        //remove comments for this criterion
                        for(Comment *comment : submission->get_comments(criterion)){
                            submission->remove_comment(comment);
                        }
                    }
                }
            }
        }


//        _controller->_rubricDB->remove_criterion(criterion->_id);
        delete criterion;
    }
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

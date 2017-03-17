#include "assignmentcontroller.h"

/**
 * @brief AssignmentController::AssignmentController default
 * constructor
 */
AssignmentController::AssignmentController(CourseController* courseController)
{
    _courseController   = courseController;
    _assignmentDB       = new AssignmentDB(this, _courseController);
//    _submissionDB       = new SubmissionDB(this);


    _assignmentDB->load_all();
//    _submissionDB->load_all();
}

/**
 * @brief AssignmentController::~AssignmentController destructor,
 * frees memory properly
 */
AssignmentController::~AssignmentController(){

//    delete _submissionDB;
    delete _assignmentDB;

    for(Assignment* assignment:_assignments)
        delete assignment;
}

/**
 * @brief Assignment::add_assignment adds an assignment to the engine
 * @param name name of the assignment
 * @param objective objective of the assignment
 * @param load whether to add to the database or only locally
 */
void AssignmentController::add_assignment(const QString name,
                                          const QString objective,
                                          bool load) {

    Assignment *new_assignment = new Assignment(name, objective);

    _assignments.push_back(new_assignment);

    if (!load)
        _assignmentDB->add(name, objective);
}

/**
 * @brief CourseController::add_section adds a section to a course
 * @param course_name name of the course
 * @param name name of the section
 * @param load whether to add to the database or only locally
 */
void AssignmentController::link_assignment(const  QString course_name,
                                           const QString section_name,
                                           const QString assignment_name,
                                           const QString folder,
                                           bool load)
{
    Assignment *assignment = get_assignment(assignment_name);
    if (assignment != nullptr)
        _courseController->link_assignment(course_name, section_name, assignment, folder);
    else
        return;

    if (!load)
        _assignmentDB->link(_assignmentDB->select(assignment_name), _courseController->_sectionDB->select(course_name, section_name), folder);
}

/**
 * @brief AssignmentController::get_assignment finds an assignment by its name
 * @param name the name of the assignment to search for
 * @return a pointer to the assignment found
 */
Assignment* AssignmentController::get_assignment(const QString name) {
    for(Assignment* assignment:_assignments)
        if (assignment->_name == name)
            return assignment;
    return nullptr;
}


/**
 * @brief AssignmentController::clear_course clears cached data from course
 * @param course_name name of the course
 */
void AssignmentController::clear_assignments() {

    for(Assignment* assignment:_assignments)
        delete assignment;

    _assignments.clear();

}

#include "assignmentcontroller.h"

/**
 * @brief AssignmentController::AssignmentController default
 * constructor
 */
AssignmentController::AssignmentController(CourseController* courseController)
{
    _courseController   = courseController;
    _assignmentDB       = new AssignmentDB(this, _courseController);
    _submissionDB       = new SubmissionDB(this, _courseController);


    _assignmentDB->load_all();
    _submissionDB->load_all();
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
 * @brief Assignment::add_submission adds a submission to a student
 * @param course_name name of the course
 * @param section_name name of the section
 * @param student_name name of the student
 * @param assignment_name name of the assignment
 * @param load whether to add to the database or only locally
 */
void AssignmentController::add_submission(const QString course_name,
                                          const QString section_name,
                                          const QString student_name,
                                          const QString student_username,
                                          const QString assignment_name,
                                          bool load) {

    Course *cur_course = _courseController->get_course(course_name);
    Section *cur_section = nullptr;
    if (cur_course != nullptr)
        cur_section = cur_course->get_section(section_name);
    else
        return;

    Student *cur_student = nullptr;

    if (cur_section != nullptr)
        cur_student = cur_section->get_student(student_username);
    else
        return;


    if (cur_student != nullptr)
        cur_student->_submissions.push_back(new Submission(get_assignment(assignment_name), cur_student));
    else
        return;

    if (!load)
        _submissionDB->add(_courseController->_studentDB->select(course_name, section_name, student_name, student_username),
                           _assignmentDB->select(assignment_name));
}


/**
 * @brief Assignment::add_submission adds a submission to a student
 * @param student the student who submitted
 * @param assignment the assignment the submission belongs to
 * @param load whether to add to the database or only locally
 */
void AssignmentController::add_submission(Student* student,
                                          Assignment* assignment,
                                          bool load) {

    Submission *new_submission = new Submission(assignment, student);
    student->_submissions.push_back(new_submission);

    QString assignment_name = assignment->_name;
    QString student_name = student->_name;
    QString student_username = student->_username;
    QString section_name = student->_section->_name;
    QString course_name = student->_section->_course->_name;

    if (!load)
        _submissionDB->add(_courseController->_studentDB->select(course_name, section_name, student_name, student_username),
                           _assignmentDB->select(assignment_name));
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
 * @brief CourseController::add_section adds a section to a course
 * @param course_name name of the course
 * @param name name of the section
 * @param load whether to add to the database or only locally
 */
void AssignmentController::link_assignment(Section* section,
                                           Assignment* assignment,
                                           const QString folder,
                                           bool load)
{
    if (assignment != nullptr)
        _courseController->link_assignment(section->_course->_name, section->_name, assignment, folder);
    else
        return;

    if (!load)
        _assignmentDB->link(_assignmentDB->select(assignment->_name),
                            _courseController->_sectionDB->select(section->_course->_name, section->_name),
                            folder);
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

#include "controller.h"

Controller::Controller()
{
    _courseDB           = new CourseDB(this);
    _sectionDB          = new SectionDB(this);
    _studentDB          = new StudentDB(this);
    _assignmentDB       = new AssignmentDB(this);
    _submissionDB       = new SubmissionDB(this);
    _rubricDB           = new RubricDB(this);


    std::cout<<"Loading courses.."<<std::endl;
    _courseDB->load_all();
    std::cout<<"Loading sections.."<<std::endl;
    _sectionDB->load_all();
    std::cout<<"Loading students.."<<std::endl;
    _studentDB->load_all();
    std::cout<<"Loading assignments.."<<std::endl;
    _assignmentDB->load_all();
    std::cout<<"Loading rubrics.."<<std::endl;
    _rubricDB->load_all();
    std::cout<<"Loading submissions.."<<std::endl;
    _submissionDB->load_all();

}


Controller::~Controller()
{
    delete _submissionDB;
    delete _assignmentDB;
    delete _rubricDB;
    delete _courseDB;
    delete _sectionDB;
    delete _studentDB;

    for(Course* course:_courses)
        delete course;

    for(Assignment* assignment:_assignments)
        delete assignment;

}

/**************************************
 *          Course Operations         *
 **************************************/



/**
 * @brief Controller::add_course adds a course to the engine
 * @param name name of the course
 * @param load whether to add to the database or only locally
 */
void Controller::add_course(const QString name,
                                  bool load) {

    Course *new_course = new Course(name);

    _courses.push_back(new_course);

    if (!load)
        _courseDB->add(name);
}


/**
 * @brief Controller::add_section adds a section to a course
 * @param course_name name of the course
 * @param name name of the section
 * @param load whether to add to the database or only locally
 */
void Controller::add_section(const QString course_name,
                                   const QString name,
                                   bool load) {

    Course *cur_course = get_course(course_name);

    if (cur_course != nullptr)
        cur_course->add_section(name);
    else
        return;

    if (!load)
        _sectionDB->add(_courseDB->select(cur_course->_name), name);
}

/**
 * @brief Controller::add_student adds a student to a section
 * @param course_name name of the course
 * @param section_name name of the section
 * @param name name of the student
 * @param username student identifier
 * @param load whether to add to the database or only locally
 */
void Controller::add_student(const  QString course_name,
                                   const QString section_name,
                                   const QString name,
                                   const QString username,
                                   bool load)
{
    Course *cur_course = get_course(course_name);
    Section *cur_section = nullptr;
    if (cur_course != nullptr)
        cur_section = cur_course->get_section(section_name);
    else
        return;

    if (cur_section != nullptr)
        cur_section->add_student(name, username);
    else
        return;

    if (!load)
        _studentDB->add(_sectionDB->select(cur_course->_name, cur_section->_name), name, username);

}

/**
 * @brief Controller::get_course finds a course by its name
 * @param name the name of the course to search for
 * @return the course found
 */
Course* Controller::get_course(const QString name) {
    for(Course* course:_courses)
        if (course->_name == name)
            return course;
    return nullptr;
}


/**
 * @brief Controller::clear_course clears cached data from course
 * @param course_name name of the course
 */
void Controller::clear_course(const QString course_name) {

    Course *cur_course = get_course(course_name);
    for(Section* section:cur_course->_sections)
        delete section;
    cur_course->_sections.clear();

}


/**
 * @brief Controller::clear_section_students clears cached data from section
 * (removes students)
 * @param course_name name of the course
 * @param section_name name of the section
 */
void Controller::clear_section_students(const QString course_name, const QString section_name) {

    Course *cur_course = get_course(course_name);
    Section *cur_section = cur_course->get_section(section_name);
    for(Student* student:cur_section->_students)
        delete student;
    cur_section->_students.clear();

}

/**
 * @brief Controller::clear_section_assignments clears cached data from section
 * (removes assignments)
 * @param course_name name of the course
 * @param section_name name of the section
 */
void Controller::clear_section_assignments(const QString course_name, const QString section_name) {

    Course *cur_course = get_course(course_name);
    Section *cur_section = cur_course->get_section(section_name);

    cur_section->_assignments.clear();

}


/**
 * @brief Controller::clear_student_submissions clears cached data from student (removes submissions)
 * @param course_name name of the course
 * @param section_name name of the section
 * @param username student unique identifier
 */
void Controller::clear_student_submissions(const QString course_name, const QString section_name, const QString username) {

    Course *cur_course = get_course(course_name);

    Section *cur_section = nullptr;

    if (cur_course != nullptr)
        cur_section = cur_course->get_section(section_name);
    else
        return;

    Student *cur_student = nullptr;

    if (cur_section != nullptr)
        cur_student = cur_section->get_student(username);
    else
        return;

    if (cur_student != nullptr)
        cur_student->_submissions.clear();

}

/**
 * @brief Controller::show_courses Displays courses (used for
 * debugging purposes)
 */
void Controller::show_courses() {
    for(Course *course : _courses) {
        std::cout<<(course->_name).toUtf8().data()<<std::endl;
            for(Section *section : course->_sections) {
                std::cout<<"    ->"<<(section->_name).toUtf8().data()<<std::endl;
                for(Student *student : section->_students) {
                    std::cout<<"        ->"<< (student->_name).toUtf8().data() <<" (" << (student->_username).toUtf8().data() << ")"<<std::endl;
                    for(Submission *submission : student->_submissions) {
                        std::cout<<"            -> Submission for "<< (submission->_assignment->_name).toUtf8().data() <<std::endl;
                    }
                }
                for(std::pair<Assignment*, QString> assignment : section->_assignments)
                    std::cout<<"        *"<< (assignment.first->_name).toUtf8().data() <<std::endl;
            }
    }
}

/**************************************
 *        Assignment Operations       *
 **************************************/


/**
 * @brief Controller::add_assignment adds an assignment to the engine
 * @param name name of the assignment
 * @param objective objective of the assignment
 * @param load whether to add to the database or only locally
 */
void Controller::add_assignment(const QString name,
                                          const QString objective,
                                          bool load) {

    Assignment *new_assignment = new Assignment(name, objective);

    _assignments.push_back(new_assignment);

    if (!load)
        _assignmentDB->add(name, objective);
}


/**
 * @brief Controller::add_criterion adds a criterion to the rubric of an assignment
 * @param assignment_name name of the assignment
 * @param name name of the criterion
 * @param parent_name name of the criterion's parent
 * @param out_of maximum grade attributed to the criterion
 * @param load whether to add to the database or only locally
 */
void Controller::add_criterion(const QString assignment_name,
                                         const QString name,
                                         const QString parent_name,
                                         int out_of,
                                         bool load)
{
    Assignment *assignment = get_assignment(assignment_name);
    Criterion *parent = nullptr;
    if (assignment != nullptr)
        parent = assignment->_rubric->get_criterion(parent_name);
    else
        return;

    assignment->_rubric->add_criterion(name, parent, out_of);

    if (!load) {
        if (parent != nullptr)
            _rubricDB->add_criterion(name, _assignmentDB->select(assignment_name), _rubricDB->select(_assignmentDB->select(assignment_name), parent->_name), out_of);
        else
            _rubricDB->add_criterion(name, _assignmentDB->select(assignment_name), NULL, out_of);
    }

}

/**
 * @brief Controller::add_submission adds a submission to a student
 * @param course_name name of the course
 * @param section_name name of the section
 * @param student_name name of the student
 * @param assignment_name name of the assignment
 * @param load whether to add to the database or only locally
 */
void Controller::add_submission(const QString course_name,
                                          const QString section_name,
                                          const QString student_name,
                                          const QString student_username,
                                          const QString assignment_name,
                                          bool load) {

    Course *cur_course = get_course(course_name);
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
        _submissionDB->add(_studentDB->select(course_name, section_name, student_name, student_username),
                           _assignmentDB->select(assignment_name));
}


/**
 * @brief Controller::add_submission adds a submission to a student
 * @param student the student who submitted
 * @param assignment the assignment the submission belongs to
 * @param load whether to add to the database or only locally
 */
void Controller::add_submission(Student* student,
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
        _submissionDB->add(_studentDB->select(course_name, section_name, student_name, student_username),
                           _assignmentDB->select(assignment_name));
}


/**
 * @brief Controller::link_assignment adds an assignment to a section
 * @param course_name name of the course
 * @param section_name name of the section
 * @param assignment_name name of the assignment
 * @param folder path to the folder that contains the submissions
 * @param load whether to add to the database or only locally
 */
void Controller::link_assignment(const  QString course_name,
                                   const QString section_name,
                                   const QString assignment_name,
                                   const QString folder,
                                   bool load)
{

    Assignment *assignment = get_assignment(assignment_name);

    if (assignment == nullptr)
        return;

    Course *cur_course = get_course(course_name);
    Section *cur_section = nullptr;
    if (cur_course != nullptr)
        cur_section = cur_course->get_section(section_name);
    else
        return;

    if (cur_section != nullptr)
        cur_section->add_assignment(assignment, folder);
    else
        return;

    if (!load)
        _assignmentDB->link(_assignmentDB->select(assignment_name), _sectionDB->select(course_name, section_name), folder);

}

/**
 * @brief Controller::get_assignment finds an assignment by its name
 * @param name the name of the assignment to search for
 * @return a pointer to the assignment found
 */
Assignment* Controller::get_assignment(const QString name) {
    for(Assignment* assignment:_assignments)
        if (assignment->_name == name)
            return assignment;
    return nullptr;
}

/**
 * @brief Controller::show_rubric prints the rubrics for assignments
 */
void Controller::show_rubrics() {

    std::cout<<std::endl<<"Showing rubrics"<<std::endl;

    for(Assignment *assignment : _assignments) {
        std::cout<<(assignment->_name).toUtf8().data()<<std::endl;
            for(Criterion *criterion : assignment->_rubric->_criteria) {
                std::cout<<"    ->"<<(criterion->_name).toUtf8().data()<< " (? / " << criterion->_out_of << ")" << std::endl;
                criterion->show_children();
            }
    }

}


/**
 * @brief Controller::clear_course clears cached data from course
 * @param course_name name of the course
 */
void Controller::clear_assignments() {

    for(Assignment* assignment:_assignments)
        delete assignment;

    _assignments.clear();

}

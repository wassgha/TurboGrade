#include "controller.h"

/**
 * @brief Controller::Controller constructor used to create tables
 * and load information from the database
 * @param drop_tables pass true to delete all information from the database
 * @param dbname the name of the database to connect to
 */
Controller::Controller(bool drop_tables, QString dbname)
{

    SHOW_WHERE;

    // Initialize random number generator
    qsrand(QTime::currentTime().msec());

    // If tables are to be dropped then drop them
    if (drop_tables) {
        DBEngine *_tmpDB = new DBEngine("DropConnection", dbname);
        _tmpDB->drop_tables();
        delete _tmpDB;
    }

    // Create database connections
    _courseDB           = new CourseDB(this, dbname);
    _sectionDB          = new SectionDB(this, dbname);
    _studentDB          = new StudentDB(this, dbname);
    _assignmentDB       = new AssignmentDB(this, dbname);
    _submissionDB       = new SubmissionDB(this, dbname);
    _rubricDB           = new RubricDB(this, dbname);
    _commentDB          = new CommentDB(this, dbname);

    // Initialize containers
    _courses = new std::vector<Course*>();
    _assignments = new std::vector<Assignment*>();
    _grades = new std::map<Criterion*, int>();

    // Load from database
    _assignmentDB->load_all();
    _courseDB->load_all();

}


Controller::~Controller()
{
    delete _commentDB;
    delete _submissionDB;
    delete _assignmentDB;
    delete _rubricDB;
    delete _courseDB;
    delete _sectionDB;
    delete _studentDB;

    for(Course* course:*_courses)
        delete course;

    for(Assignment* assignment:*_assignments)
        delete assignment;

    for(std::pair<Criterion*, int> grade : *_grades){
        delete grade.first;
    }
    delete _grades;

}

/**************************************
 *          Course Operations         *
 **************************************/



/**
 * @brief Controller::add_course adds a course to the engine
 * @param id table id of the course
 * @param name name of the course
 */
Course* Controller::add_course(int id, const QString name) {

    Course *new_course = new Course(id, name, this);

    _courses->push_back(new_course);

    return new_course;
}


/**
 * @brief Controller::get_course finds a course by its name
 * @param name the name of the course to search for
 * @return the course found
 */
Course* Controller::get_course(const QString name) {
    for(Course* course:*_courses)
        if (course->_name == name)
            return course;
    return nullptr;
}

/**
 * @brief Controller::get_courses returns a vector of all
 * courses in the system
 * @return all courses
 */
std::vector<Course*>* Controller::get_courses() {

    return _courses;

}



/**
 * @brief Controller::show_courses Displays courses (used for
 * debugging purposes)
 */
void Controller::show_courses() {
    for(Course *course : *_courses) {
        std::cout<<(course->_name).toStdString()<<std::endl;
            for(Section *section : *course->_sections) {
                std::cout<<"    ->"<< section->_name.toStdString()<<std::endl;
                for(Student *student : *section->_students) {
                    std::cout<<"        ->"<< student->_name.toStdString() <<" (" << student->_username.toStdString() << ")"<<std::endl;
                    for(Submission *submission : *student->_submissions) {
                        std::cout<<"            -> Submission for "<< submission->_assignment->_name.toStdString() <<std::endl;
                        for(Comment *comment : *submission->_comments) {
                            std::cout<<"                + Comment (" << comment->_grade <<" ): \""
                                     << (comment->_text).toStdString()
                                     << "\" from " << comment->_start_pos << " to " << comment->_end_pos
                                     << " about " << comment->_criterion->_name.toStdString()
                                     <<std::endl;
                        }
                    }
                }
                for(std::pair<Assignment*, QString> assignment : *section->_assignments)
                    std::cout<<"        *"<< (assignment.first->_name).toStdString() <<std::endl;
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
Assignment* Controller::add_assignment(int id,
                                const QString name,
                                const QString objective) {

    Assignment *new_assignment = new Assignment(id, name, objective, this);

    _assignments->push_back(new_assignment);

    return new_assignment;
}

/**
 * @brief Controller::get_assignment finds an assignment by its name
 * @param name the name of the assignment to search for
 * @return a pointer to the assignment found
 */
Assignment* Controller::get_assignment(const QString name) {
    for(Assignment* assignment : *_assignments)
        if (assignment->_name == name)
            return assignment;
    return nullptr;
}

/**
 * @brief Controller::get_assignment finds an assignment by its table id
 * @param id the id of the assignment to search for
 * @return a pointer to the assignment found
 */
Assignment* Controller::get_assignment(const int id) {
    for(Assignment* assignment : *_assignments)
        if (assignment->_id == id)
            return assignment;
    return nullptr;
}

/**
 * @brief Controller::get_assignments returns a vector of all
 * assignments in the system
 * @return all assignments
 */
std::vector<Assignment*>* Controller::get_assignments() {

    return _assignments;

}

/**************************************
 *        Grading Operations          *
 **************************************/

void Controller::add_grade(Criterion *criterion, int grade){
    _grades->emplace(std::make_pair(criterion, grade));
}

std::map<Criterion*, int> *Controller::get_grades(){
    return _grades;
}

/**************************************
 *        UI Operations               *
 **************************************/

/**
 * @brief Controller::show_rubric prints the rubrics for assignments
 */
void Controller::show_rubrics() {

    std::cout<<std::endl<<"Showing rubrics"<<std::endl;

    for(Assignment *assignment : *_assignments) {
        std::cout<<(assignment->_name).toStdString()<<std::endl;
            for(Criterion *criterion : *assignment->_rubric->_criteria) {
                std::cout<<"    ->"<<(criterion->_name).toStdString()<< " (? / " << criterion->_out_of << ")" << std::endl;
                criterion->show_children();
            }
    }

}

/**
 * @brief Controller::rand_color returns a random
 * flat color
 */
QString Controller::rand_color() {
    return _flat_colors.at(qrand() % _flat_colors.count());
}

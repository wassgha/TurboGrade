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
    _gradeDB            = new GradeDB(this, dbname);

    // Initialize containers
    _courses = new std::vector<Course*>();
    _assignments = new std::vector<Assignment*>();
    _grades = new std::map<Criterion*, int>();
    _criteria = new std::vector<Criterion*>();

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

/**
 * @brief Controller::set_curr_submission sets the current submission and
 * refreshes the _grades map with the new information regarding the submission
 * @param submission the new submission
 */
void Controller::set_curr_submission(Submission *submission){
    _curr_submission = submission;
    refresh_grades_map(submission);
}

/**
 * @brief Controller::refresh_grades_map refreshes the _grades map and the
 * _criteria vec. Here we reconcile the professor's overrides and the
 * aggregation of grading points from comments
 * @param submission the submission to refresh with
 */
void Controller::refresh_grades_map(Submission *submission){
    //TODO CLEANUP OLD CRITERIA -> GRADES MAPPING
    _grades->clear();
    //Refreshes the _criteria map
    refresh_criteria_vec(submission);
    //Add the criterion to the map with a score of 0
    for(Criterion* criterion: *_criteria){
        add_grade(criterion,0);
    }
    //For each comment, update the grade value in the table to its current value,
    //plus the comments grade value. Since we start at 0, this computes final grade
    std::vector<Comment*> *com = submission->_comments;
    for(Comment* comment : *com){
        Criterion *crit = comment->_criterion;
        add_grade(crit, get_grade(crit) + comment->_grade);
    }

    //load all of the grades from the db... If a grade has been overwritten in db,
    //it will overwrite the expected grade here
    _gradeDB->load_all(submission, _criteria);
}

/**
 * @brief Controller::refresh_criteria_vec refreshes the _criteria vector using
 * the Submissions rubric
 * @param submission the submission to refresh with
 */
void Controller::refresh_criteria_vec(Submission *submission){
    //TODO CLEANUP OLD CRITERIA
    _criteria->clear();
    //refresh the critera vector to contain the vector for current submission
    _criteria = submission->_assignment->_rubric->_criteria;
}

/**
 * @brief Controller::add_grade adds a grade to a specific criterion,
 * ASSUMES WE KNOW THE SUBMISSION
 * @param criterion the criterion
 * @param grade the value to set the grade to
 */
void Controller::add_grade(Criterion *criterion, int grade){
    _grades->emplace(std::make_pair(criterion, grade));
}

/**
 * @brief Controller::get_grades getter for the _grades map
 * @return the _grades map containing Criterion, grade mappings
 */
std::map<Criterion*, int> *Controller::get_grades(){
    return _grades;
}

/**
 * @brief Controller::get_grade retrieves the grade for the given criterion
 * ASSUMES WE KNOW THE SUBMISSION
 * @param criterion the criterion in question
 * @return the grade for that criterion, -1 if non existant
 */
int Controller::get_grade(Criterion *criterion){
    try {
        return _grades->at(criterion);
    }
    catch (std::out_of_range& e) {
        qDebug() << "Tried to access grade for criterion not in map.";
        return -1;
    }
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

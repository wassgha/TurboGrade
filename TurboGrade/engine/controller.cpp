#include "controller.h"

/**
 * @brief Controller::Controller constructor used to create tables
 * and load information from the database
 * @param drop_tables pass true to delete all information from the database
 * @param dbname the name of the database to connect to
 */
Controller::Controller(bool drop_tables, QString dbname, bool git_sync):
    settings("PfaffCorp", "TurboGrade"),
    _git_sync(git_sync)
{

    SHOW_WHERE;

    dbname = QDir(qApp->applicationDirPath()).absoluteFilePath(dbname);

    // Initialize random number generator
    qsrand(QTime::currentTime().msec());

    // Create application settings
    if (!settings.contains("general/theme"))
        settings.setValue("general/theme", "Dark Theme");
    if (!settings.contains("general/repo_url"))
        settings.setValue("general/repo_url", "https://turbograde:PK4R29Dede@github.com/turbograde/sync.git");
    if (!settings.contains("general/repo_pwd"))
        settings.setValue("general/repo_pwd", "PK4R29Dede");
    if (!settings.contains("general/font_size"))
        settings.setValue("general/font_size", 12);

    // Create Git connection and pull data/database
    if (_git_sync) {
        _git = new GitModule("sync", settings.value("general/repo_url").toString(), settings.value("general/repo_pwd").toString());
        _git->clone();
        sync_git();
    }

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

    // Initialize semesters (should at least have semesters from current, previous and next years)
    _all_semesters<<"Spring " + QString::number(QDate::currentDate().year() + 1);
    _all_semesters<<"Fall " + QString::number(QDate::currentDate().year() + 1);
    _all_semesters<<"Spring " + QString::number(QDate::currentDate().year());
    _all_semesters<<"Fall " + QString::number(QDate::currentDate().year());
    _all_semesters<<"Spring " + QString::number(QDate::currentDate().year() - 1);
    _all_semesters<<"Fall " + QString::number(QDate::currentDate().year() - 1);
    _current_semester = ((QDate::currentDate().month() < 6)?"Spring ":"Fall ") + QString::number(QDate::currentDate().year());

    // Initialize containers
    _courses = new std::vector<Course*>();
    _assignments = new std::vector<Assignment*>();

    // Load from database
    _assignmentDB->load_all();
    _courseDB->load_all();

}


/**
 * @brief Controller::~Controller Destructor
 */
Controller::~Controller()
{
    if (_git_sync)
        sync_git();

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

}

/**************************************
 *          Course Operations         *
 **************************************/



/**
 * @brief Controller::add_course adds a course to the engine
 * @param id table id of the course
 * @param name name of the course
 * @param semester the semester the course was taught in
 */
Course* Controller::add_course(const QString name, const QString semester, int id) {

    Course *new_course = new Course(name, semester, this, id);

    _courses->push_back(new_course);

    return new_course;
}

/**
 * @brief Controller::remove_course removes a course from the software.
 * Also removes all of the courses sections
 * @param course the course to remove
 */
void Controller::remove_course(Course *course){
    if(course == nullptr){
        return;
    }
    // erase from DB
    _courseDB->remove(course->_id);
    // erase comment from comments vector
    _courses->erase(std::remove(_courses->begin(), _courses->end(), course),
                    _courses->end());
    for(Section *section: *course->_sections){
        course->remove_section(section);
    }
    delete course;
}


/**
 * @brief Controller::get_course finds a course by its name
 * @param name the name of the course to search for
 * @param semester the semester the course was taught in
 * @return the course found
 */
Course* Controller::get_course(const QString name, const QString semester) {
    for(Course* course:*_courses)
        if (course->_name == name && course->_semester == semester)
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
                    std::cout<<"        ->"<< student->_name.toStdString() <<std::endl;
                    for(Submission *submission : *student->_submissions) {
                        std::cout<<"            -> Submission for "<< submission->_assignment->_name.toStdString() <<std::endl;
                        for(Comment *comment : *submission->_comments) {
                            std::cout<<"                + Comment (" << comment->_grade <<" ): \""
                                     << (comment->_text).toStdString()
                                     << "\" from " << comment->_start_pos << " to " << comment->_end_pos
                                     << " about " << comment->_criterion->_name.toStdString()
                                     <<std::endl;
                        }
                        for(Criterion *criterion : *submission->_assignment->_rubric->_criteria) {
                            std::cout<<"                * Grade on " << criterion->_name.toStdString() << ":";
                            std::cout<< submission->get_grade(criterion) << " out of " << criterion->_out_of <<" "<<std::endl;
                        }
                    }
                }
                for(Assignment* assignment : *section->_assignments)
                    std::cout<<"        *"<< (assignment->_name).toStdString() <<std::endl;
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
Assignment* Controller::add_assignment(const QString name, const QString objective,
                                       bool full_grade, int id) {

    Assignment *new_assignment = new Assignment(name, objective, this, full_grade, id);

    _assignments->push_back(new_assignment);

    return new_assignment;
}

/**
 * @brief Controller::remove_assignment remove the assignment from the program
 * Also removes the assignment from all sections, and removes the rubric.
 * @param assignment the assignment to remove
 */
void Controller::remove_assignment(Assignment *assignment){
    if(assignment == nullptr){
        return;
    }
    // erase from DB
    _assignmentDB->remove(assignment->_id);
    // erase from sections
    for(Course *course : *_courses){
        for(Section *section : *course->_sections){
            for(Assignment *sectionAssignment: *section->_assignments){
                if(assignment == sectionAssignment){
                    section->remove_assignment(assignment);
                }
            }
        }
    }
    // erase assignment from assignments vector
    _assignments->erase(std::remove(_assignments->begin(), _assignments->end(), assignment),
                    _assignments->end());

    // erase the rubric with it
    for(Criterion *criterion : *assignment->_rubric->_criteria){
        for(Criterion *subCriterion : *criterion->_sub_criteria){
            assignment->_rubric->remove_criterion(subCriterion);
        }
        assignment->_rubric->remove_criterion(criterion);
    }
    delete assignment;
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

void Controller::refresh_autocomplete(Assignment *assignment) {
    _all_comments = _commentDB->load_model(assignment);
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
        std::cout<<(assignment->_name).toStdString()<<" has "<< QString::number(assignment->_rubric->_criteria->size()).toStdString()<< " criteria " << std::endl;
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

/**************************************
 *        Git synchronization               *
 **************************************/

/**
 * @brief Controller::sync_git pulls then pushes
 * to the git repository
 */
void Controller::sync_git() {
    if (!_git_sync)
        return;
    _git->pull();
    _git->add_all();
    _git->commit("TurboGrade Synchronization");
    _git->push(true);
}

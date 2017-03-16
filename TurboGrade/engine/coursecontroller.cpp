#include "coursecontroller.h"

/**
 * @brief CourseController::CourseController default
 * constructor
 */
CourseController::CourseController()
{
    _courseDB = new CourseDB(this);
    _sectionDB = new SectionDB(this);

    _courseDB->load_all();
    _sectionDB->load_all();
}

/**
 * @brief CourseController::~CourseController destructor,
 * frees memory properly
 */
CourseController::~CourseController(){

    delete _courseDB;
    delete _sectionDB;

    _courses.clear();
}

/**
 * @brief CourseController::add_course adds a course to the engine
 * @param name name of the course
 * @param load whether to add to the database or only locally
 */
void CourseController::add_course(const QString name, bool load) {

    Course *new_course = new Course(name);

    _courses.push_back(new_course);

    if (!load)
        _courseDB->add(name);
}

/**
 * @brief CourseController::get_course finds a course by its name
 * @param name the name of the course to search for
 * @return the course found
 */
Course* CourseController::get_course(const QString name) {
    for(Course* course:_courses)
        if (course->_name == name)
            return course;
    return nullptr;
}

/**
 * @brief CourseController::add_section adds a section to a course
 * @param course_name name of the course
 * @param name name of the section
 * @param load whether to add to the database or only locally
 */
void CourseController::add_section(const QString course_name, const QString name, bool load) {

    Course *cur_course = get_course(course_name);

    if (cur_course != nullptr)
        cur_course->add_section(name);
    else
        return;

    if (!load)
        _sectionDB->add(_courseDB->select(cur_course->_name), name);
}


void CourseController::show_courses() {
    for(Course *course : _courses) {
        std::cout<<(course->_name).toUtf8().data()<<std::endl;
            for(Section *section : course->_sections)
                std::cout<<"    ->"<<(section->_name).toUtf8().data()<<std::endl;
    }
}

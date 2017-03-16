#include "coursecontroller.h"

/**
 * @brief CourseController::CourseController default
 * constructor
 */
CourseController::CourseController()
{
    _courseDB = new CourseDB(this);
    _sectionDB = new SectionDB(this);
    _studentDB = new StudentDB(this);

    _courseDB->load_all();
    _sectionDB->load_all();
    _studentDB->load_all();
}

/**
 * @brief CourseController::~CourseController destructor,
 * frees memory properly
 */
CourseController::~CourseController(){

    delete _courseDB;
    delete _sectionDB;
    delete _studentDB;

    _courses.clear();
}

/**
 * @brief CourseController::add_course adds a course to the engine
 * @param name name of the course
 * @param load whether to add to the database or only locally
 */
void CourseController::add_course(const QString name,
                                  bool load) {

    Course *new_course = new Course(name);

    _courses.push_back(new_course);

    if (!load)
        _courseDB->add(name);
}


/**
 * @brief CourseController::add_section adds a section to a course
 * @param course_name name of the course
 * @param name name of the section
 * @param load whether to add to the database or only locally
 */
void CourseController::add_section(const QString course_name,
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
 * @brief CourseController::add_section adds a section to a course
 * @param course_name name of the course
 * @param name name of the section
 * @param load whether to add to the database or only locally
 */
void CourseController::add_student(const  QString course_name,
                                   const QString section_name,
                                   const QString name,
                                   bool load)
{
    Course *cur_course = get_course(course_name);
    Section *cur_section = nullptr;
    if (cur_course != nullptr)
        cur_section = cur_course->get_section(section_name);
    else
        return;

    if (cur_section != nullptr)
        cur_section->add_student(name);
    else
        return;

    if (!load)
        _studentDB->add(_courseDB->select(cur_course->_name), name);

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
 * @brief CourseController::clear_course clears cached data from course
 * @param course_name name of the course
 */
void CourseController::clear_course(const QString course_name) {

    Course *cur_course = get_course(course_name);
    cur_course->_sections.clear();

}


/**
 * @brief CourseController::clear_section clears cached data from section
 * (removes students)
 * @param course_name name of the course
 * @param section_name name of the section
 */
void CourseController::clear_section(const QString course_name, const QString section_name) {

    Course *cur_course = get_course(course_name);
    Section *cur_section = cur_course->get_section(section_name);
    cur_section->_students.clear();

}

/**
 * @brief CourseController::show_courses Displays courses (used for
 * debugging purposes)
 */
void CourseController::show_courses() {
    for(Course *course : _courses) {
        std::cout<<(course->_name).toUtf8().data()<<std::endl;
            for(Section *section : course->_sections) {
                std::cout<<"    ->"<<(section->_name).toUtf8().data()<<std::endl;
                for(Student *student : section->_students)
                    std::cout<<"        ->"<<(student->_name).toUtf8().data()<<std::endl;
            }
    }
}

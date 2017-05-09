#include "section.h"

/**
 * @brief Section::Section Constructor, create a new section locally
 * @param name          name of the section, ex. "01"
 * @param course        pointer to the course this section belongs to
 * @param controller    current controller object
 * @param id            -1 if new otherwise the table id if it exists
 */
Section::Section(QString name, Course* course, Controller* controller, int id)
{

    SHOW_WHERE;

    _controller = controller;

    // If id is -1 then we're creating locally and we should add to the database
    if (id == -1)
        _id = _controller->_sectionDB->add(course->_id, name);
    else
        _id = id;

    _name = name;
    _course = course;

    // Section students
    _students = new std::vector<Student*>();
    // Section assignments (assignment and folder)
    _assignments = new std::vector<Assignment*>();

    _color = _controller->rand_color();

    // Load the assignments and students to the section
    _controller->_assignmentDB->load_all(this);
    _controller->_studentDB->load_all(this);
}

/**
 * @brief Section::update updates the Section in memory and DB
 * @param name the new name of the section
 */
void Section::update(QString name){
    _name = name;

    _controller->_sectionDB->update(name, _id);
}

/**
 * @brief Section::~Section Destructor
 */
Section::~Section()
{
    for(Student* student:*_students)
        delete student;
    delete _students;

    delete _assignments;
}


/**
 * @brief Section::add_student adds a student to this section
 * @param name name of the student
 * @param username identifier of the student
 */
Student* Section::add_student(const QString name, int id) {

    Student *new_student = new Student(name, this, _controller, id);

    _students->push_back(new_student);

    return new_student;
}

/**
 * @brief Section::remove_student removes student from section, and also
 * deletes all submissions from student.
 * @param student the student to remove
 */
void Section::remove_student(Student *student){
    if(student == nullptr){
        return;
    }
    // erase from DB
    _controller->_studentDB->remove(student->_id);
    // erase student from students vector
    _students->erase(std::remove(_students->begin(), _students->end(), student),
                    _students->end());
    for(Submission *submission : *student->_submissions){
        student->remove_submission(submission);
    }
    delete student;
}

/**
 * @brief Section::get_student finds a student by their name
 * @param name the student identifier
 * @return the student found
 */
Student* Section::get_student(const QString name) {
    for(Student* student:*_students)
        if (student->_name == name)
            return student;
    return nullptr;
}

/**
 * @brief Section::add_assignment adds an assignment to this section
 * @param assignment a pointer to the assignment
 * @param folder the folder where submissions can be found
 */
Assignment* Section::add_assignment(Assignment* assignment, bool load) {


    _assignments->push_back(assignment);

    if (!load)
        _controller->_assignmentDB->link(assignment->_id, _id);

    return assignment;
}

/**
 * @brief Section::get_assignment finds an assignment by its name
 * @param name the name of the assignment to search for
 * @return the assignment
 */
Assignment* Section::get_assignment(const QString name) {
    for(Assignment* assignment:*_assignments)
        if (assignment->_name == name)
            return assignment;

    return nullptr;
}

/**
 * @brief Section::remove_assignment erases the assignment from the section.
 * This also propagates to delete all submissions for the students in the section
 * for the given assignment.
 *
 * NOTE: THIS METHOD DOES NOT DELETE THE ASSIGNMENT, IT ONLY REMOVES THE
 * SECTION -> ASSIGNMENT LINK
 * @param assignment the assignment to delete
 */
void Section::remove_assignment(Assignment *assignment){
    if(assignment == nullptr){
        return;
    }
    // erase from DB
    _controller->_assignmentDB->remove_link(assignment->_id, _id);
    // erase assignment from assignment vector
    _assignments->erase(std::remove(_assignments->begin(), _assignments->end(), assignment),
                    _assignments->end());
    for(Student *student : *_students){
        student->remove_submission(student->get_submission(assignment));
    }
}

std::vector<Assignment*>* Section::get_assignments() {

    return _assignments;

}

std::vector<Student*>* Section::get_students() {

    return _students;

}
/**
 * @brief Section::num_submissions_total returns the number
 * of submissions for a specified assignment
 * @param assignment the assignment
 * @return total number of submissions
 */
int Section::num_submissions_total(Assignment* assignment) {
    int i = 0;
    for (Student* student : *_students) {
        if (student->get_submission(assignment) != nullptr) {
            i++;
        }
    }
    return i;
}

/**
 * @brief Section::num_submissions_graded returns the number
 * of finalized (graded) submissions for a specified assignment
 * @param assignment the assignment
 * @return total number of graded submissions
 */
int Section::num_submissions_graded(Assignment* assignment) {
    int i = 0;
    for (Student* student : *_students) {
        if (student->get_submission(assignment) != nullptr && student->get_submission(assignment)->_status == 2) {
            i++;
        }
    }
    return i;
}

/**
 * @brief Section::num_submissions_graded returns the number
 * of finalized (graded) submissions for a specified assignment
 * @param assignment the assignment
 * @return total number of graded submissions
 */
int Section::num_submissions_ungraded(Assignment* assignment) {
    int i = 0;
    for (Student* student : *_students) {
        if (student->get_submission(assignment) != nullptr &&
                student->get_submission(assignment)->_status != 2) {
            i++;
        }
    }
    return i;
}

/**
 * @brief Section::get_random_ungraded selects a random submission
 * to be graded for a specific assignment
 * @param assignment the assignment
 * @return the submission
 */
Submission* Section::get_random_ungraded(Assignment* assignment) {
    if (num_submissions_ungraded(assignment) != 0 ) {
        Student * rand_student = nullptr;
        while (rand_student == nullptr ||
               rand_student->get_submission(assignment) == nullptr ||
               rand_student->get_submission(assignment)->_status == 2)
            rand_student = _students->at(qrand() % ((int)_students->size()));
        return rand_student->get_submission(assignment);
    } else {
        return nullptr;
    }
}

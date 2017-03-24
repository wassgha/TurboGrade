#ifndef CONTROLLER_H
#define CONTROLLER_H

/**
 * @brief The Controller class deals with
 * data interactions between the database
 * and the local data structures.
 */

#include <iostream>
#include <vector>
#include <algorithm>

#include "course.h"
#include "section.h"
#include "student.h"
#include "assignment.h"
#include "submission.h"
#include "rubric.h"
#include "criterion.h"

#include "../db/assignmentdb.h"
#include "../db/submissiondb.h"
#include "../db/rubricdb.h"
#include "../db/coursedb.h"
#include "../db/sectiondb.h"
#include "../db/studentdb.h"

class CourseDB;
class SectionDB;
class StudentDB;
class AssignmentDB;
class SubmissionDB;
class RubricDB;

class Controller
{
public:
    Controller();
    ~Controller();

    /**********************************
     *       Course operations        *
     **********************************/

    // Add a course to the software
    void add_course(const QString name,
                    bool load = false);
    // Adds a section to a course
    void add_section(const QString course_name,
                     const QString name,
                     bool load = false);
    // Adds a student to a section
    void add_student(const QString course_name,
                     const QString section_name,
                     const QString name,
                     const QString username,
                     bool load = false);

    // Searches for a course by name and returns it
    Course* get_course(const QString name);

    // Clears all locally cached course data (sections)
    void clear_course(const QString course_name);

    // Clears all locally cached section data (students)
    void clear_section_students(const QString course_name,
                                const QString section_name);

    // Clears all locally cached section data (assignments)
    void clear_section_assignments(const QString course_name,
                                   const QString section_name);

    // Clears all locally cached student data (submissions)
    void clear_student_submissions(const QString course_name,
                                   const QString section_name,
                                   const QString username);

    // Prints all courses and sections
    void show_courses();

    /**********************************
     *       Assignment operations    *
     **********************************/

    // Add a assignment to the software
    void add_assignment(const QString name,
                        const QString objective,
                        bool load = false);

    // Link assignment to a section
    void link_assignment(const QString course_name,
                         const QString section_name,
                         const QString assignment_name,
                         const QString folder,
                         bool load = false);

    // Adds a submission to a student
    void add_submission(const QString course_name,
                        const QString section_name,
                        const QString student_name,
                        const QString student_username,
                        const QString assignment_name,
                        bool load = false);

    // Adds a submission to a student by objects
    void add_submission(Student* student,
                        Assignment* assignment,
                        bool load = false);

    // Adds a criterion to a rubric
    void add_criterion(const QString assignment_name,
                      const QString name,
                      const QString parent_name,
                      int out_of,
                      bool load = false);

    // Searches for an assignment by name and returns it
    Assignment* get_assignment(const QString name);

    // Shows rubric for all assignments
    void show_rubrics();

    // Clears all locally cached assignment data
    void clear_assignments();

private:
    /*
     * Database containers
     */


    // Course database table
    CourseDB *_courseDB;
    // Section database table
    SectionDB *_sectionDB;
    // Student database table
    StudentDB *_studentDB;
    // Assignment database table
    AssignmentDB *_assignmentDB;
    // Submission database table
    SubmissionDB *_submissionDB;
    // Rubric database table
    RubricDB *_rubricDB;

    /*
     * Local containers
     */

    // All courses in the engine
    std::vector<Course*> _courses;

    // All assignments in the engine
    std::vector<Assignment*> _assignments;
};

#endif // CONTROLLER_H

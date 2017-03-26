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

#include "../tools/macro.h"
#include "../tools/objectidentifier.h"

#include "course.h"
#include "section.h"
#include "student.h"
#include "assignment.h"
#include "submission.h"
#include "rubric.h"
#include "criterion.h"
#include "comment.h"

#include "../db/assignmentdb.h"
#include "../db/submissiondb.h"
#include "../db/rubricdb.h"
#include "../db/coursedb.h"
#include "../db/sectiondb.h"
#include "../db/studentdb.h"
#include "../db/commentdb.h"

class CourseDB;
class SectionDB;
class StudentDB;
class AssignmentDB;
class SubmissionDB;
class RubricDB;
class CommentDB;

class Controller : public ObjectIdentifier
{
public:

    // Constructor used to initialize database
    Controller(bool drop_tables = false, QString dbname = "turbograde.sqlite");
    // Destructor
    ~Controller();

    /**********************************
     *       Course operations        *
     **********************************/

    // Add a course to the software
    Course* add_course(int id, const QString name);
    // Searches for a course by name and returns it
    Course* get_course(const QString name);
    // Retuns vector of all courses in the system
    std::vector<Course*>* get_courses();
    // Prints all courses and sections
    void show_courses();

    /**********************************
     *       Assignment operations    *
     **********************************/

    // Add a assignment to the software
    Assignment* add_assignment(int id,
                               const QString name,
                               const QString objective);
    // Searches for an assignment by name and returns it
    Assignment* get_assignment(const QString name);
    // Searches for an assignment by table ID and returns it
    Assignment* get_assignment(const int id);
    // Retuns vector of all assignments in the system
    std::vector<Assignment*>* get_assignments();
    // Shows rubric for all assignments
    void show_rubrics();


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
    // Comment database table
    CommentDB *_commentDB;

private:

    /*
     * Local containers
     */

    // All courses in the engine
    std::vector<Course*> *_courses;

    // All assignments in the engine
    std::vector<Assignment*> *_assignments;
};

#endif // CONTROLLER_H

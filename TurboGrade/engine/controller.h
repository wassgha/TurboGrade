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
#include <QObject>
#include <QStandardPaths>
#include <map>

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
#include "../db/gradedb.h"

class CourseDB;
class SectionDB;
class StudentDB;
class AssignmentDB;
class SubmissionDB;
class RubricDB;
class CommentDB;
class GradeDB;

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
    Course* add_course(const QString name, const QString semester, int id = -1);
    // Remove a course from the software
    void remove_course(Course *course);
    // Searches for a course by name and returns it
    Course* get_course(const QString name, const QString semester);
    // Retuns vector of all courses in the system
    std::vector<Course*>* get_courses();
    // Prints all courses and sections
    void show_courses();

    /**********************************
     *       Assignment operations    *
     **********************************/

    // Add a assignment to the software
    Assignment* add_assignment(const QString name, const QString objective,
                               bool full_grade = false, int id = -1);
    // Remove an assignment from the software
    void remove_assignment(Assignment *assignment);
    // Searches for an assignment by name and returns it
    Assignment* get_assignment(const QString name);
    // Searches for an assignment by table ID and returns it
    Assignment* get_assignment(const int id);
    // Retuns vector of all assignments in the system
    std::vector<Assignment*>* get_assignments();
    // Shows rubric for all assignments
    void show_rubrics();
    // Refresh auto-complete
    void refresh_autocomplete(Assignment *assignment);

    /**********************************
     *       UI Related Operations    *
     **********************************/
    QString rand_color();

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
    // Grade database table
    GradeDB *_gradeDB;
    // Auto-complete list
    QSqlQueryModel *_all_comments;
    // All semesters used
    QStringList _all_semesters;
    // Current semester
    QString _current_semester;

    /*
     * UI variables
     */
    const QStringList _flat_colors = QStringList()  <<"#63c46b"<<"#3498db"
                                                    <<"#9b59b6"<<"#34495e"
                                                    <<"#c0392b"<<"#f39c12"
                                                    <<"#2980b9"<<"#D44A59"
                                                    <<"#462446"<<"#FFC153"
                                                    <<"#47B39D"<<"#897FBA"
                                                    <<"#60646D"<<"#65878F";

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

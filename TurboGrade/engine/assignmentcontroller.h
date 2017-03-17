#ifndef ASSIGNMENTCONTROLLER_H
#define ASSIGNMENTCONTROLLER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "coursecontroller.h"
#include "assignment.h"
#include "../db/assignmentdb.h"
#include "../db/submissiondb.h"

class AssignmentDB;
class SubmissionDB;

class AssignmentController
{
public:
    // Constructor
    AssignmentController(CourseController* courseController);
    // Destructor
    ~AssignmentController();

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

    // Link assignment to a section by objects
    void link_assignment(Section* section,
                        Assignment* assignment,
                        const QString folder,
                        bool load);

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
                        bool load);

    // Searches for an assignment by name and returns it
    Assignment* get_assignment(const QString name);

    // Clears all locally cached assignment data
    void clear_assignments();

private:
    /*
     * Local containers
     */

    // All courses in the engine
    std::vector<Assignment*> _assignments;
    CourseController *_courseController;

    /*
     * Database containers
     */

    // Assignment database table
    AssignmentDB *_assignmentDB;
    // Submission database table
    SubmissionDB *_submissionDB;
};

#endif // ASSIGNMENTCONTROLLER_H

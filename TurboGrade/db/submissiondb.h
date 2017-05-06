#ifndef SUBMISSIONDB_H
#define SUBMISSIONDB_H

/**
 * @brief SubmissionDB is the interface for the
 * submission database table. It is used to add
 * and retrieve rows from the table.
 */

#include "dbengine.h"
#include "../engine/controller.h"

class Controller;

class SubmissionDB : public DBEngine
{
public:
    // Parametrized constructor
    SubmissionDB(Controller *controller, QString dbname):
        DBEngine("SubmissionDB", dbname),
        _controller(controller){}
    // Destructor
    ~SubmissionDB();


    // Adds a row to the submission table
    int add(int student_id, int assignment_id, QString general_comment, int status);
    // Gets row id matching submission
    int select(int student_id, int assignment_id);
    // Loads submissions for a specific student
    void load_all(Student *student);
    // Updates the grading status of a submission
    void update_status(int submission_id, int status);
    // Update the general comment
    void update_general_comment(int submission_id, QString general_comment);
    // Deletes a row from the submission table
    void remove(int submission_id);

    // Controller
    Controller* _controller;
};

#endif // SUBMISSIONDB_H

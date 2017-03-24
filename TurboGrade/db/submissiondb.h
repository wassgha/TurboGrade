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
    // Constructor
    SubmissionDB();
    // Parametrized constructor
    SubmissionDB(Controller *controller):
        DBEngine("SubmissionDB"),
        _controller(controller){}
    // Destructor
    ~SubmissionDB();


    // Adds a row to the submission table
    bool add(int student_id, int assignment_id);
    // Adds a row to the file table
    bool add_file(int submission_id, QString filename);
    // Gets row id matching submission
    int select(int student_id, int assignment_id);
    // Loads submissions and links them to the controller
    void load_all();
    // Loads submissions for a specific student
    void load_student_submissions(int student_id);


    // Controller
    Controller* _controller;
};

#endif // SUBMISSIONDB_H

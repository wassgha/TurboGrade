#ifndef GRADEDB_H
#define GRADEDB_H
#include "../engine/submission.h"
#include "../engine/criterion.h"
#include <vector>
#include "dbengine.h"
#include "../engine/controller.h"
class Controller;

class GradeDB : public DBEngine
{
public:
    GradeDB();
    // Constructor
    GradeDB(Controller *controller, QString dbname):
        DBEngine("GradeDB", dbname),
        _controller(controller){}
    // Destructor
    ~GradeDB();


    // Adds a row to the table
    int add(int rubric_id, int submission_id, int grade);

    // Updates a row in the table
    int update(int rubric_id, int submission_id, int grade);

    // Gets row id matching rubric and submission
    int select(int rubric_id, int submission_id);

    // Load all grades to controller for the submission and criterion
    void load_all(Submission* submission, std::vector<Criterion*> *criteria);

    // Load grade for a single criterion
    void load_criterion(Submission* submission, Criterion* criterion);

    //Controller
    Controller *_controller;
};

#endif // GRADEDB_H

#ifndef SUBMISSION_H
#define SUBMISSION_H

/**
 * @brief The Submission class holds information
 * about a single submission (by whom and for which
 * assignment).
 */


#include <iostream>
#include <vector>
#include <QString>
#include <QObject>

#include "../tools/macro.h"
#include "../tools/objectidentifier.h"

#include "controller.h"
#include "assignment.h"
#include "student.h"
#include "comment.h"

class Controller;
class Student;
class Assignment;
class Comment;

class Submission : public ObjectIdentifier, public QObject
{
public:
    Submission() = delete; //don't allow default constructor
    // Parametrized constructor
    Submission(int id, Assignment* assignment, Student* student, Controller * controller);
    // Destructor
    ~Submission();
    // Add a comment on the submission
    void add_comment(int id, QString filename,
                     Criterion *criterion,
                     QString text, int grade,
                     int start_pos, int end_pos);



    /**********************************
     *    Grade Related Operations    *
     **********************************/
    void set_curr_submission(Submission *submission);

    void refresh_grades_map(Submission *submission);

    void refresh_criteria_vec(Submission *submission);

    //ASSUMING ONLY 1 SUBMISSION BEING WORKED ON AT ONCE

    //returns map of all criterion and their corresp. grades
    std::map<Criterion*, int> *get_grades();

    //adds a grade to the map
    void add_grade(Criterion* criterion, int grade, bool load = false);

    //updates a grade in the map
    void update_grade(Criterion* criterion, int grade, bool load = false);

    //retrieves the grade for the criterion on the current submission
    int get_grade(Criterion* criterion);

    //retrieves the  total grade for the current submission
    int get_grade();

    // Submission id
    int _id;
    // Submission belongs to student
    Student* _student;
    // Submission assignment
    Assignment* _assignment = nullptr;
    // Submission comments
    std::vector<Comment*> *_comments;    
    // The collection of criterion and their grades for the current submission
    std::map<Criterion*, int> *_grades;
    // Controller
    Controller *_controller;
};

#endif // SUBMISSION_H

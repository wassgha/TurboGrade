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

    // Submission id
    int _id;
    // Submission belongs to student
    Student* _student;
    // Submission assignment
    Assignment* _assignment = nullptr;
    // Submission comments
    std::vector<Comment*> *_comments;
    // Controller
    Controller *_controller;
};

#endif // SUBMISSION_H

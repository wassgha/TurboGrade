#ifndef COMMENT_H
#define COMMENT_H

/**
 * @brief The Comment class holds information
 * about a single comment (grade adjustment, text
 * and for which file / submission / line).
 */


#include <iostream>
#include <vector>
#include <QString>

#include "../tools/macro.h"
#include "../tools/objectidentifier.h"

#include "controller.h"
#include "assignment.h"
#include "student.h"
#include "criterion.h"
#include "submission.h"

class Controller;
class Student;
class Assignment;
class Criterion;
class Submission;

class Comment : public ObjectIdentifier
{
public:

    Comment() = delete; //don't allow default constructor
    // Parametrized constructor
    Comment(int id,
            Submission* submission,
            QString filename,
            Criterion* criterion,
            QString text,
            int grade,
            int start_pos,
            int end_pos,
            Controller * controller);
    // Destructor
    ~Comment();

    // Comment id
    int _id;
    // Which submission is the comment on
    Submission* _submission;
    // Which file is the comment on
    QString _filename;
    // Which rubric criterion does this comment belong to
    Criterion *_criterion;
    // The text of the comment
    QString _text;
    // Grade score
    int _grade;
    // Position in file (start and end positions)
    int _start_pos;
    int _end_pos;
    // Color (for UI)
    QString _color;
    // Controller
    Controller *_controller;
};

#endif // COMMENT_H

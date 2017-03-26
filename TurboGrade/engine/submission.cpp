#include "submission.h"

/**
 * @brief Submission::Submission creates a submission and adds it to the
 * database if it doesn't exist
 * @param id the table id for the submission (-1 if this is a new entry)
 * @param assignment the assignment this submission belongs to
 * @param student the student this submission belongs to
 * @param controller the current controller
 */
Submission::Submission(int id, Assignment *assignment,
                       Student* student, Controller * controller)
{

    SHOW_WHERE;

    _controller = controller;

    if (id == -1)
        _id = _controller->_submissionDB->add(student->_id, assignment->_id);
    else
        _id = id;

    _assignment = assignment;
    _student = student;

    // Submission comments
    _comments = new std::vector<Comment*>();

    _controller->_commentDB->load_all(this);
}


/**
 * @brief Submission::add_comment adds a comment made on this submission
 */
void Submission::add_comment(int id, QString filename,
                             Criterion *criterion,
                             QString text, int grade,
                             int start_pos, int end_pos) {

    Comment *new_comment = new Comment(id, this, filename, criterion, text, grade, start_pos, end_pos, _controller);

    _comments->push_back(new_comment);
}

Submission::~Submission()
{
    for (Comment* comment : *_comments)
        delete comment;
    delete _comments;
}

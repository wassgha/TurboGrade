#include "comment.h"

/**
 * @brief Comment::Comment creates a comment and adds it to the
 * database if it doesn't exist
 * @param id the comment id for the submission (-1 if this is a new entry)
 * @param submission the submission this comments is about
 * @param filename the file this comments is about
 * @param criterion the rubric criterion this comments belongs to
 * @param text the text of the comment
 * @param grade the grade adjustment (+1, -1, etc.)
 * @param start_pos character index for the start of the comment
 * @param end_pos character index for the end of the comment
 * @param controller the current controller
 */
Comment::Comment(int id, Submission* submission,
                       QString filename, Criterion* criterion,
                       QString text, int grade,
                       int start_pos, int end_pos,
                       Controller * controller)
{

    SHOW_WHERE;

    _controller = controller;

    if (id == -1)
        _id = _controller->_commentDB->add(submission->_id, filename,
                                           criterion->_id, text, grade,
                                           start_pos, end_pos);
    else
        _id = id;

    _filename = filename;
    _text = text;
    _grade = grade;
    _submission = submission;
    _criterion = criterion;
    _start_pos = start_pos;
    _end_pos = end_pos;
}

Comment::~Comment()
{
}

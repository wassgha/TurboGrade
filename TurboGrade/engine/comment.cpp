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
Comment::Comment(Submission* submission,
                       QString filename, Criterion* criterion,
                       QString text, int grade,
                       int start_pos, int end_pos,
                       Controller * controller, int id)
{

    SHOW_WHERE;

    _controller = controller;
    _submission = submission;
    _filename = filename;
    _text = text;
    _grade = grade;
    _criterion = criterion;
    _start_pos = start_pos;
    _end_pos = end_pos;

    // If id is -1 then we're creating locally and we should add to the database
    if (id == -1) {

        // Add the comment to the database
        _id = _controller->_commentDB->add(submission->_id,
                                           filename,
                                           (criterion == nullptr ? 0 : criterion->_id),
                                           text,
                                           grade,
                                           start_pos, end_pos);

        // Adjust the grade according to the comment
        qDebug()<<"Adjusting grade for comment"<<endl;
        _submission->update_grade(_criterion,
                  (
                  _submission->get_grade(_criterion) == -1 ?
                        0 : _submission->get_grade(_criterion)
                   ) + _grade);
    } else {
        _id = id;
    }

}

/**
 * @brief Comment::update updates the comment in memory and in DB
 * @param filename the new filename
 * @param criterion the new criterion
 * @param text the new text
 * @param grade the new grade
 * @param start_pos the new start position
 * @param end_pos the new end position
 */
void Comment::update( QString filename, Criterion* criterion,
                      QString text, int grade,
                      int start_pos, int end_pos){
    //subtract the old grade
    _submission->update_grade(_criterion, _submission->get_grade(_criterion) - _grade);

    _filename = filename;
    _criterion = criterion;
    _text = text;
    _grade = grade;
    _start_pos = start_pos;
    _end_pos = end_pos;

    // add new grade
    _submission->update_grade(_criterion, _submission->get_grade(_criterion) + _grade);

    // update the comment DB
    _controller->_commentDB->update(_filename, _criterion->_id, _text, _grade, _start_pos, _end_pos, _id);

    // refresh auto complete
    _controller->refresh_autocomplete();

}

/**
 * @brief Comment::~Comment Destructor
 */
Comment::~Comment()
{
}

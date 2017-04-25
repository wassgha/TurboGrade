#ifndef COMMENTDB_H
#define COMMENTDB_H

/**
 * @brief CommentDB is the interface for the
 * comments database table. It is used to add
 * and retrieve rows from the table.
 */

#include "dbengine.h"
#include "../engine/controller.h"

class Controller;

class CommentDB : public DBEngine
{
public:

    // Parametrized constructor
    CommentDB(Controller *controller, QString dbname):
        DBEngine("CommentDB", dbname),
        _controller(controller){}
    // Destructor
    ~CommentDB();

    // Adds a row to the comment table
    int add(int submission_id, QString filename,
            int criterion_id, QString comment_text,
            int grade, int start_pos,
            int end_pos);

    // Erases a comment from the comment table
    void remove(int comment_id);

    // Updates a comment from the comment table
    void update(QString filename,
                int criterion_id, QString comment_text,
                int grade, int start_pos,
                int end_pos, int comment_id);

    // Loads comments for a specific submission
    void load_all(Submission *submission);

    // Load all comments for autocompleting
    QSqlTableModel* load_model();


    // Controller
    Controller* _controller;
};

#endif // COMMENTDB_H

#ifndef ASSIGNMENTVIEW_H
#define ASSIGNMENTVIEW_H


/**
 * @brief The AssignmentView is the view responsible
 * for displaying assignments in a given section
 */

#include "rubricview.h"
#include "ui_rubricview.h"

#include "cardsview.h"
#include "ui_cardsview.h"

#include "dashboard.h"

class CardsView;

class AssignmentView: public CardsView
{
    Q_OBJECT
public:
    AssignmentView(QWidget* parent = 0, QObject* section = nullptr, Controller* controller = nullptr);
    ~AssignmentView();

public slots:
    // Required for a cards view, reloads the assignments
    void refresh_cards() override;
    // Slot to transition to the student view
    void show_students();
    // Slot to transition to the submission view
    void show_submissions(QObject* assignment);
    // Callback for the "add new" form, adds a new assinment to the database
    void add_new();
    // Callback for the "add new" form, add a selected existing assignment to this section
    void add_existing(int id);

private:
    void refresh_existing_assignments();

    Controller *_controller;
    Section* _section;
    RubricView *_rubric_view = nullptr;
    QComboBox* _assignment_id = nullptr;

};

#endif // ASSIGNMENTVIEW_H

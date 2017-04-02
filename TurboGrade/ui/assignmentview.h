#ifndef ASSIGNMENTVIEW_H
#define ASSIGNMENTVIEW_H

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
    void refresh_cards() override;
    void add_new();
    void show_students();
    void add_existing(int id);

private:
    void refresh_combobox();

    Controller *_controller;
    Section* _section;
    RubricView *_rubric_view = nullptr;
    QComboBox* _assignment_id = nullptr;

};

#endif // ASSIGNMENTVIEW_H

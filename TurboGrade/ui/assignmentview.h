#ifndef ASSIGNMENTVIEW_H
#define ASSIGNMENTVIEW_H

#include "cardsview.h"
#include "ui_cardsview.h"

#include "dashboard.h"

class CardsView;

class AssignmentView: public CardsView
{
    Q_OBJECT
public:
    AssignmentView(QWidget* parent = 0, QObject* section = nullptr, Controller* controller = nullptr);

public slots:
    void refresh_cards() override;
    void save_new() override;
    void show_students();

private:
    Controller *_controller;
    Section* _section;

};

#endif // ASSIGNMENTVIEW_H

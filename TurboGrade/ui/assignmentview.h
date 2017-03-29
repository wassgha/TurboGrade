#ifndef ASSIGNMENTVIEW_H
#define ASSIGNMENTVIEW_H

#include "cardsview.h"
#include "ui_cardsview.h"

class CardsView;

class AssignmentView: public CardsView
{
public:
    AssignmentView(QWidget* parent = 0, void* section = nullptr, Controller* controller = nullptr):
        CardsView(parent)
    {

        _controller = controller;
        _section = (Section*)section;
        add_dialog = new AddDialog(this, "assignment", _controller);
        connect(add_dialog, SIGNAL(submit()), this, SLOT(save_new()));

        add_btn = new QPushButton("Add assignment");
        add_btn->setCursor(Qt::PointingHandCursor);
        add_btn->setObjectName("add_btn");
        connect(add_btn, SIGNAL(clicked(bool)), this, SLOT(new_course()));

        refresh_cards();
    }

public slots:
    void refresh_cards() override {

        remove_cards();

        add_card(add_btn);
        for(std::pair<Assignment*, QString> assignment : *_section->_assignments) {
            Card* new_assignment = new Card(assignment.first->_name,
                                         assignment.first->_objective,
                                         assignment.first->_color, &assignment);
            cards.push_back(new_assignment);
            connect(new_assignment, SIGNAL(clicked(void *)), parent()->parent(), SLOT(show_submissions(void *)));
            add_card(new_assignment);
        }

    }

    void save_new() override {
//        Assignment *assignment = _controller->add_assignment(-1, add_dialog->ui->name->text(), add_dialog->ui->objective->text())
//        _section->add_assignment(assignment, add_dialog->ui->folder->text(), false);
        add_dialog->ui->name->clear();
        refresh_cards();
    }

private:
    Controller *_controller;
    Section* _section;

};

#endif // ASSIGNMENTVIEW_H

#ifndef COURSEVIEW_H
#define COURSEVIEW_H

#include "cardsview.h"
#include "ui_cardsview.h"

class CardsView;

class CourseView: public CardsView
{
public:
    CourseView(QWidget* parent = 0, Controller* controller = nullptr):
        CardsView(parent)
    {

        _controller = controller;
        add_dialog = new AddDialog(this, "course", _controller);
        connect(add_dialog, SIGNAL(submit()), this, SLOT(save_new()));

        add_btn = new QPushButton("Add course");
        add_btn->setCursor(Qt::PointingHandCursor);
        add_btn->setObjectName("add_btn");
        connect(add_btn, SIGNAL(clicked(bool)), this, SLOT(new_course()));

        _breadcrumb = new Breadcrumb(parent);
        ui->verticalLayout->insertWidget(0, _breadcrumb);
        refresh_cards();
    }

public slots:
    void refresh_cards() override {

        remove_cards();

        add_card(add_btn);
        for(Course* course : *_controller->get_courses()) {
            Card* new_course = new Card(course->_name,
                                        QString::number(course->get_sections()->size()) + " section(s)",
                                        course->_color, course);
            cards.push_back(new_course);
            connect(new_course, SIGNAL(clicked(QObject*)), parent(), SLOT(show_sections(QObject*)));
            add_card(new_course);
        }

    }

    void save_new() override {
        _controller->add_course(-1, add_dialog->ui->name->text());
        add_dialog->ui->name->clear();
        refresh_cards();
    }

private:
    Controller *_controller;

};

#endif // COURSEVIEW_H

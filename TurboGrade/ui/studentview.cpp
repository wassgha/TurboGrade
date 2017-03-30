#include "studentview.h"

StudentView::StudentView(QWidget* parent, Controller* controller):
    ListView(parent)
{

    _controller = controller;
    add_dialog = new FormDialog(this, "New Student");
    connect(add_dialog, SIGNAL(submit()), this, SLOT(save_new()));

    add_btn = new QPushButton("Add course");
    add_btn->setCursor(Qt::PointingHandCursor);
    add_btn->setObjectName("add_btn");
    connect(add_btn, SIGNAL(clicked(bool)), this, SLOT(new_course()));

    ui->verticalLayout->insertWidget(0, _breadcrumb);
    refresh_cards();
}

void StudentView::refresh_cards() {

    remove_cards();

    add_card(add_btn);
    for(Course* course : *_controller->get_courses()) {
        Card* new_course = new Card(course->_name,
                                    QString::number(course->get_sections()->size()) + " section(s)",
                                    course->_color, course);
        cards.push_back(new_course);
        connect(new_course, SIGNAL(clicked(QObject*)), _parent, SLOT(show_sections(QObject*)));
        add_card(new_course);
    }

}

void StudentView::save_new() {
    _controller->add_course(-1, add_dialog->val("name"));
    refresh_cards();
}

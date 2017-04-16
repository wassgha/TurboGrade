#include "courseview.h"

CourseView::CourseView(QWidget* parent, Controller* controller):
    CardsView(parent)
{

    _controller = controller;

    add_dialog = new FormDialog(this, "New Course");
    add_dialog->add_field("QLineEdit", "name", "Course Name :", "CS 150");
    connect(add_dialog, SIGNAL(submit()), this, SLOT(save_new()));

    add_btn = new QPushButton("Add course");
    add_btn->setCursor(Qt::PointingHandCursor);
    add_btn->setObjectName("add_btn");
    connect(add_btn, SIGNAL(clicked(bool)), this, SLOT(open_add_dialog()));

    ui->verticalLayout->insertWidget(0, _breadcrumb);
    refresh_cards();

}

void CourseView::refresh_cards() {

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

void CourseView::save_new() {
    _controller->add_course(add_dialog->val("name"));
    refresh_cards();
}

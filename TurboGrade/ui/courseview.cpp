#include "courseview.h"

CourseView::CourseView(QWidget* parent, Controller* controller):
    CardsView(parent)
{

    _controller = controller;

    _semesters_model = new QStringListModel();
    _semesters_model->setStringList(_controller->_all_semesters);

    add_dialog = new FormDialog(this, "New Course");
    add_dialog->add_field("QLineEdit", "name", "Course Name :", "CS 150");
    _semester_select = dynamic_cast<QComboBox*>(add_dialog->add_field("QComboBox", "semester", "Semester :"));
    _semester_select->setModel(_semesters_model);
    connect(add_dialog, SIGNAL(submit()), this, SLOT(save_new()));

    add_btn = new QPushButton("Add course");
    add_btn->setCursor(Qt::PointingHandCursor);
    add_btn->setObjectName("add_btn");
    connect(add_btn, SIGNAL(clicked(bool)), this, SLOT(open_add_dialog()));

    _semester_switch = new QComboBox();
    _semester_switch->setModel(_semesters_model);
    _semester_switch->setCurrentIndex(2);
    connect(_semester_switch, SIGNAL(currentIndexChanged(int)), this, SLOT(refresh_cards()));

    _breadcrumb->add_to_back(_semester_switch);
    ui->verticalLayout->insertWidget(0, _breadcrumb);
    refresh_cards();

}

void CourseView::refresh_cards() {

    remove_cards();

    add_card(add_btn);
    for(Course* course : *_controller->get_courses()) {
        if (course->_semester == _semester_switch->currentText()) {
            Card* new_course = new Card(course->_name,
                                        QString::number(course->get_sections()->size()) + " section(s)",
                                        course->_color, course);
            cards.push_back(new_course);
            connect(new_course, SIGNAL(clicked(QObject*)), _parent, SLOT(show_sections(QObject*)));
            add_card(new_course);
        }
    }

}

void CourseView::save_new() {
    _controller->add_course(add_dialog->val("name"), _semester_select->currentText());
    _semester_switch->setCurrentText(_semester_select->currentText());
    add_dialog->val("semester");
    refresh_cards();
}

#include "studentview.h"

StudentView::StudentView(QWidget* parent, QObject* section, Controller* controller):
    ListView(parent)
{

    _controller = controller;
    _section = (Section*)section;

    add_dialog = new FormDialog(this, "New Student");
    add_dialog->add_field("QLabel", "warning", "Please be aware that students are added automatically when you import \n"
                                               "submissions. Only manually add students if they do not have a submission.");
    add_dialog->add_field("QLineEdit", "name", "Student's name :", "John Appleseed");
    connect(add_dialog, SIGNAL(submit()), this, SLOT(save_new()));

    add_btn = new QPushButton("Add student");
    add_btn->setCursor(Qt::PointingHandCursor);
    add_btn->setObjectName("add_btn");
    connect(add_btn, SIGNAL(clicked(bool)), this, SLOT(new_course()));

    _breadcrumb->add_item(_section->_course->_name, SLOT(show_sections(QObject*)), _section->_course);
    _breadcrumb->add_item(_section->_name, SLOT(show_assignments(QObject*)), _section);
    _breadcrumb->add_switcher("Assignments", "Students", true);
    connect(_breadcrumb, SIGNAL(switcher_toggled()), dynamic_cast<StudentView*>(this), SLOT(show_assignments()));

    ui->verticalLayout->insertWidget(0, _breadcrumb);
    refresh_cards();
}

void StudentView::show_assignments() {
    ((Dashboard*)_parent)->show_assignments(_section);
}

void StudentView::refresh_cards() {

    remove_cards();

    add_card(add_btn);
    for(Student* student : *_section->_students) {
        Card* new_student = new Card(student->_name,
                                    "Avg. Grade : 96%",
                                    student->_color, student);
        cards.push_back(new_student);
//      connect(new_student, SIGNAL(clicked(QObject*)), _parent, SLOT(show_sections(QObject*)));
        add_card(new_student);
    }

}

void StudentView::save_new() {
    _section->add_student(add_dialog->val("name"));
    refresh_cards();
}

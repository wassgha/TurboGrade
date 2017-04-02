#include "submissionview.h"

SubmissionView::SubmissionView(QWidget* parent, QObject* section,
                               QObject* assignment, Controller* controller):
    ListView(parent)
{

    _controller = controller;
    _section = (Section*)section;
    _assignment = (Assignment*)assignment;

    add_dialog = new FormDialog(this, "Import Submissions");
    add_dialog->add_field("QLabel", "info", "Submissions are copied and stored within TurboGrade, \n"
                                             "you can delete the original folder if you wish.");
    add_dialog->add_field("QLabel", "instructions", "Please unzip the Moodle submissions and point \n"
                                                    "to the folder where you unzipped them.");
    add_dialog->add_field("QFileDialog", "select_folder", "Choose folder", ":/misc/res/folder.png");
    connect(add_dialog, SIGNAL(submit()), this, SLOT(save_new()));

    add_btn = new QPushButton("Import submissions");
    add_btn->setCursor(Qt::PointingHandCursor);
    add_btn->setObjectName("add_btn");
    connect(add_btn, SIGNAL(clicked(bool)), this, SLOT(new_course()));

    _breadcrumb->add_item(_section->_course->_name, SLOT(show_sections(QObject*)), _section->_course);
    _breadcrumb->add_item(_section->_name, SLOT(show_assignments(QObject*)), _section);
    _breadcrumb->add_item(_assignment->_name, SLOT(show_submissions(QObject*)), _assignment, this);
    ui->verticalLayout->insertWidget(0, _breadcrumb);

    refresh_cards();
}

void SubmissionView::show_submissions(QObject* assignment) {
    dynamic_cast<Dashboard*>(_parent)->show_submissions(_section, assignment);
}

void SubmissionView::show_assignments() {
    dynamic_cast<Dashboard*>(_parent)->show_assignments(_section);
}

void SubmissionView::refresh_cards() {

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

void SubmissionView::save_new() {
    _section->add_student(-1, add_dialog->val("name"), add_dialog->val("username"));
    refresh_cards();
}

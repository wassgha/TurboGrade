#include "assignmentview.h"

AssignmentView::AssignmentView(QWidget* parent, QObject* section, Controller* controller):
    CardsView(parent)
{

    _controller = controller;
    _section = (Section*)section;

    add_dialog = new FormDialog(this, "New Assignment");
    add_dialog->add_field("QLineEdit", "name", "Assignment Name :", "Binary Search Tree");
    connect(add_dialog, SIGNAL(submit()), this, SLOT(save_new()));

    add_btn = new QPushButton("Add assignment");
    add_btn->setCursor(Qt::PointingHandCursor);
    add_btn->setObjectName("add_btn");
    connect(add_btn, SIGNAL(clicked(bool)), this, SLOT(new_course()));

    _breadcrumb->add_item(_section->_course->_name, SLOT(show_sections(QObject*)), _section->_course);
    _breadcrumb->add_item(_section->_name, SLOT(show_assignments(QObject*)), _section);
    _breadcrumb->add_switcher("Students", "Assignments");
    connect(_breadcrumb, SIGNAL(switcher_toggled()), dynamic_cast<AssignmentView*>(this), SLOT(show_students()));

    ui->verticalLayout->insertWidget(0, _breadcrumb);
    refresh_cards();
}


void AssignmentView::show_students() {
    dynamic_cast<Dashboard*>(_parent)->show_students(_section);
}

void AssignmentView::refresh_cards() {

    remove_cards();

    add_card(add_btn);
    for(std::pair<Assignment*, QString> assignment : *_section->_assignments) {
        Card* new_assignment = new Card(assignment.first->_name,
                                     assignment.first->_objective,
                                     assignment.first->_color, assignment.first);
        cards.push_back(new_assignment);
        connect(new_assignment, SIGNAL(clicked(QObject *)), _parent, SLOT(show_submissions(QObject *)));
        add_card(new_assignment);
    }

}

void AssignmentView::save_new() {
//        Assignment *assignment = _controller->add_assignment(-1, add_dialog->ui->name->text(), add_dialog->ui->objective->text())
//        _section->add_assignment(assignment, add_dialog->ui->folder->text(), false);
    refresh_cards();
}

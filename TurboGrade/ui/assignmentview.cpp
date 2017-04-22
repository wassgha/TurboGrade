#include "assignmentview.h"

/**
 * @brief AssignmentView::AssignmentView Constructor, creates a new view that
 * holds assignmets for a specific section
 * @param parent        the dashboard object
 * @param section       the current section
 * @param controller    the controller object
 */
AssignmentView::AssignmentView(QWidget* parent, QObject* section, Controller* controller):
    CardsView(parent)
{

    _controller = controller;
    _section = (Section*)section;


    /**************************************************
     *          Construct the "Add new" Dialog        *
     **************************************************/
    add_dialog = new FormDialog(this, "Assign an existing lab/project");

    // Select an existing assignment
    _assignment_id = (QComboBox*) add_dialog->add_field("QComboBox", "assignment_id", "Existing assignment :");
    refresh_existing_assignments();
    connect(_assignment_id, SIGNAL(currentIndexChanged(int)), this, SLOT(add_existing(int)));

    // Separator

    add_dialog->add_field("Separator", "separator");
    add_dialog->add_field("Title", "title_2", "Add new assignment");

    //Make new assignment

    add_dialog->add_field("QLineEdit", "name", "Assignment Name :", "Binary Search Tree");
    add_dialog->add_field("QTextEdit", "objective",
                          "Assignment Objective :",
                          "This project will help you get familiar with data structures");
    add_dialog->add_field("QCheckBox", "full_grades_checkbox", "Initialize submissions with full grades (grade by penalties)");
    connect(add_dialog, SIGNAL(submit()), this, SLOT(add_new()));

    add_btn = new QPushButton("Add assignment");
    add_btn->setCursor(Qt::PointingHandCursor);
    add_btn->setObjectName("add_btn");
    connect(add_btn, SIGNAL(clicked(bool)), this, SLOT(open_add_dialog()));

    /**************************************************
     *               Breadcrumb Trail                 *
     **************************************************/

    _breadcrumb->add_item(_section->_course->_name, SLOT(show_sections(QObject*)), _section->_course);
    _breadcrumb->add_item(_section->_name, SLOT(show_assignments(QObject*)), _section);
    _breadcrumb->add_switcher("Assignments", "Students", false);
    connect(_breadcrumb, SIGNAL(switcher_toggled()), dynamic_cast<AssignmentView*>(this), SLOT(show_students()));
    ui->verticalLayout->insertWidget(0, _breadcrumb);


    /**************************************************
     *                  Course Cards                  *
     **************************************************/

    refresh_cards();

}

/**
 * @brief AssignmentView::~AssignmentView Destructor
 */
AssignmentView::~AssignmentView() {
    if (_rubric_view != nullptr)
        delete _rubric_view;
    if (_assignment_id != nullptr)
        delete _assignment_id;
}

/**
 * @brief AssignmentView::refresh_existing_assignments reloads the list
 * of existing assignment (to put in the "add new" dialog)
 */
void AssignmentView::refresh_existing_assignments() {
    _assignment_id->clear();
    _assignment_id->addItem("No assignment selected", -1);
    for(Assignment* assignment : *_controller->get_assignments()) {
        if (std::find(_section->_assignments->begin(), _section->_assignments->end(), assignment) == _section->_assignments->end())
            _assignment_id->addItem(assignment->_name, assignment->_id);
    }
}

/**
 * @brief AssignmentView::show_students slot to transition to the student
 * view
 */
void AssignmentView::show_students() {
    dynamic_cast<Dashboard*>(_parent)->show_students(_section);
}

/**
 * @brief AssignmentView::show_submissions slot to transition to the
 * submissions view
 * @param assignment the selected assignment to show submissions for
 */
void AssignmentView::show_submissions(QObject* assignment) {
    dynamic_cast<Dashboard*>(_parent)->show_submissions(_section, assignment);
}

/**
 * @brief AssignmentView::refresh_cards reloads the assignments in the view
 * in case an assignment was added/deleted/updated etc.
 */
void AssignmentView::refresh_cards() {

    remove_cards();

    add_card(add_btn);
    for(Assignment* assignment : *_section->_assignments) {
        Card* new_assignment = new Card(assignment->_name,
                                     assignment->_objective,
                                     assignment->_color, assignment);
        cards.push_back(new_assignment);
        connect(new_assignment, SIGNAL(clicked(QObject *)), this, SLOT(show_submissions(QObject *)));
        add_card(new_assignment);
    }

}

/**
 * @brief AssignmentView::add_new callback for the "add new" dialog,
 * adds the new assignment as described by the dialog to the database
 */
void AssignmentView::add_new() {

    // Capitalize assignment name
    QString assignment_name = add_dialog->val("name");
    assignment_name = assignment_name.left(1).toUpper()+assignment_name.mid(1);

    // Add the assignment
    Assignment *assignment = _controller->add_assignment(assignment_name, add_dialog->val("objective"), add_dialog->val("full_grades_checkbox") == "1");

    // Link it to the current section
    _section->add_assignment(assignment, false);

    // Show the rubric maker
    add_dialog->hide();
    if (_rubric_view != nullptr)
        delete _rubric_view;
    _rubric_view = new RubricView(this, assignment);
    _rubric_view->show();

    // Refresh UI
    refresh_existing_assignments();
    refresh_cards();
}

/**
 * @brief AssignmentView::add_existing callback for the "add new" dialog,
 * links an existing assignment to this section based on the selected
 * item in the "add new" dialog
 * @param id the selected assignment to add to this section
 */
void AssignmentView::add_existing(int id) {
    if (id > 0) {
        int assignment_table_id = _assignment_id->itemData(id).toInt();
        Assignment *assignment = _controller->get_assignment(assignment_table_id);
        _section->add_assignment(assignment, false);
        add_dialog->val("assignment_id");
        add_dialog->hide();
        refresh_existing_assignments();
        refresh_cards();
    }
}

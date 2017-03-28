#include "courses.h"
#include "ui_courses.h"

Courses::Courses(QWidget *parent, Controller *controller) :
    QWidget(parent),
    ui(new Ui::Courses)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_StyledBackground, true);

    _controller = controller;

    new_course_dialog = new NewCourse(this, _controller);
    connect(new_course_dialog, SIGNAL(added_course()), this, SLOT(refresh_courses()));

    add_course_btn = new QPushButton("Add course");
    add_course_btn->setObjectName("add_course");
    connect(add_course_btn, SIGNAL(clicked(bool)), this, SLOT(new_course()));

    refresh_courses();
    refresh_courses();

}

Courses::~Courses()
{
    for (Card* course: courses) {
        delete course;
    }
    delete ui;
}

void Courses::refresh_courses() {

    remove_courses();

    add_course(add_course_btn);
    for(Course* course : *_controller->get_courses()) {
        Dashboard *dashboard = qobject_cast<Dashboard*> (this->parent());
        QString color = dashboard->flat_colors.at(qrand() % dashboard->flat_colors.count());
        Card* new_course = new Card(course->_name, "2 sections", color);
        courses.push_back(new_course);
        connect(new_course, SIGNAL(clicked()), this, SLOT(open_editor()));
        add_course(new_course);
    }

}

void Courses::add_course(QWidget *course) {
    if (cur_col >= max_col) {
        cur_col = 0;
        cur_row++;
    }
    QGridLayout *grid =  (QGridLayout*) ui->scrollAreaWidgetContents->layout();
    grid->addWidget(course, cur_row, cur_col);
    cur_col++;
}

void Courses::remove_courses() {
    QGridLayout *grid =  (QGridLayout*) ui->scrollAreaWidgetContents->layout();
    grid->removeWidget(add_course_btn);
    for (Card* course: courses) {
        grid->removeWidget(course);
        delete course;
    }
    courses.clear();
    cur_col = 0;
    cur_row = 0;
}

void Courses::new_course() {
    new_course_dialog->show();
}

void Courses::open_editor() {
    ((Dashboard *)parent()->parent())->grade_submission->show();
}

#include "courses.h"
#include "ui_courses.h"

Courses::Courses(QWidget *parent, Controller *controller) :
    QWidget(parent),
    ui(new Ui::Courses)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_StyledBackground, true);

    _controller = controller;

    QPushButton *add_course_btn = new QPushButton("Add course");
    add_course_btn->setObjectName("add_course");
    add_course(add_course_btn);
    show_courses();

}

Courses::~Courses()
{
    delete ui;
}

void Courses::show_courses() {
    std::cout<<"Reading from database (found "<<_controller->get_courses()->size()<< ")"<<std::endl;
    for(Course* course : *_controller->get_courses()) {
        std::cout<<"Course : "<<course->_name.toStdString()<<std::endl;
        add_course(new QPushButton(course->_name));
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

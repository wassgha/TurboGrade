#include "courses.h"
#include "ui_courses.h"

Courses::Courses(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Courses)
{
    ui->setupUi(this);

    QPushButton *add_course_btn = new QPushButton("Add course");
    add_course_btn->setObjectName("add_course");
    add_course(add_course_btn);
    QPushButton *btn2 = new QPushButton("test course");
    add_course(btn2);
    QPushButton *btn3 = new QPushButton("test course");
    add_course(btn3);
    QPushButton *btn4 = new QPushButton("test course");
    add_course(btn4);

    setAttribute(Qt::WA_StyledBackground, true);
}

Courses::~Courses()
{
    delete ui;
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

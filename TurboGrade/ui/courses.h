#ifndef COURSES_H
#define COURSES_H

#include <vector>
#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>

#include "../engine/controller.h"
#include "../engine/controller.h"

#include "dashboard.h"
#include "ui_dashboard.h"

#include "newcourse.h"
#include "ui_newcourse.h"

#include "card.h"
#include "ui_card.h"

namespace Ui {
class Courses;
}

class Courses : public QWidget
{
    Q_OBJECT

public:
    explicit Courses(QWidget *parent = 0, Controller* controller = nullptr);
    ~Courses();
    void add_course(QWidget *course);
    void remove_courses();
    Controller *_controller;

private:
    Ui::Courses *ui;
    QPushButton *add_course_btn;
    NewCourse *new_course_dialog;
    int max_col = 3;
    int cur_col = 0;
    int cur_row = 0;
    std::vector<Card*> courses;

public slots:
    void new_course();
    void refresh_courses();
    void open_editor();
};

#endif // COURSES_H

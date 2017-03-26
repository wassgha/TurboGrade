#ifndef COURSES_H
#define COURSES_H

#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>

#include "../engine/controller.h"
#include "../engine/controller.h"

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
    void show_courses();
    Controller *_controller;

private:
    Ui::Courses *ui;
    int max_col = 3;
    int cur_col = 0;
    int cur_row = 0;
};

#endif // COURSES_H

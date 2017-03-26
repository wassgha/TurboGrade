#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>

#include "courses.h"
#include "ui_courses.h"

#include "../engine/controller.h"
#include "../engine/controller.h"


namespace Ui {
class Dashboard;
}

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = 0, Controller* controller = nullptr);
    ~Dashboard();
    Courses *courses;
    Controller *_controller;

private:
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H

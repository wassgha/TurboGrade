#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>

#include "courses.h"
#include "ui_courses.h"

namespace Ui {
class Dashboard;
}

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = 0);
    ~Dashboard();
    Courses *courses;

private:
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H

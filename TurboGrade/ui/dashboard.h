#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>

#include "courses.h"
#include "ui_courses.h"

#include "../engine/controller.h"
#include "../engine/controller.h"

#include "gradesubmission.h"
#include "ui_gradesubmission.h"

class GradeSubmission;

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
    Controller *_controller;
    GradeSubmission *grade_submission;
    QFont roboto;

private:
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H

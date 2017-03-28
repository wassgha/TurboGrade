#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QDesktopServices>

#include "cardsview.h"
#include "ui_courses.h"

#include "../engine/controller.h"
#include "../engine/controller.h"

#include "gradesubmission.h"
#include "ui_gradesubmission.h"

class GradeSubmission;
class CardsView;

namespace Ui {
class Dashboard;
}

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = 0);
    ~Dashboard();
    CardsView *courses;
    Controller *_controller;
    GradeSubmission *grade_submission;
    QFont roboto;

private slots:
    void on_tutorial_btn_clicked();

private:
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H

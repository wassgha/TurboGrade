#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dashboard.h"
#include "ui_dashboard.h"

#include "gradesubmission.h"
#include "ui_gradesubmission.h"

#include "../engine/controller.h"
#include "../engine/controller.h"

#include <QMainWindow>
#include <iostream>
#include <QGraphicsDropShadowEffect>

class GradeSubmission;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Controller *controller;
    GradeSubmission *grade_submission;
    Dashboard *dashboard;
    QFont roboto;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

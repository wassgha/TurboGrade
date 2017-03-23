#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gradesubmission.h"
#include "ui_gradesubmission.h"

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
    GradeSubmission *grade_submission;
    QFont roboto;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H

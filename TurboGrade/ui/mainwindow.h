#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "gradingview.h"
#include "ui_gradingview.h"
#include "gradeoverview.h"
#include "ui_gradeoverview.h"

#include <QMainWindow>
#include <iostream>

class GradeOverview;
class GradingView;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Ui::MainWindow *ui;
    GradingView *grading_view;
    GradeOverview *grade_overview;
    QFont muli;
    QFont montserrat;
public slots:
    void toggle_views();
};

#endif // MAINWINDOW_H

#include <QtWidgets>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    grading_view = new GradingView(this);
    grade_overview = new GradeOverview(this);
    grade_overview->hide();
    setCentralWidget(grading_view);
}

MainWindow::~MainWindow()
{

    delete ui;
}

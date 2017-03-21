#include <QtWidgets>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    grading_view = new GradingView(this->parentWidget());
    grade_overview = new GradeOverview(this->parentWidget());
    ui->stackedWidget->addWidget(grading_view);
    ui->stackedWidget->addWidget(grade_overview);
    ui->stackedWidget->setCurrentWidget(grading_view);
    connect(grading_view, SIGNAL(toggle()), this, SLOT(toggle_views()));
    connect(grade_overview, SIGNAL(toggle()), this, SLOT(toggle_views()));
}

void MainWindow::toggle_views() {

    if (ui->stackedWidget->currentWidget() == grade_overview)

        ui->stackedWidget->setCurrentWidget(grading_view);

    else

        ui->stackedWidget->setCurrentWidget(grade_overview);

}

MainWindow::~MainWindow()
{

    delete ui;
}


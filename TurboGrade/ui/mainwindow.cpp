#include <QtWidgets>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int id = QFontDatabase::addApplicationFont(":/fonts/res/Roboto-Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    roboto = QFont(family);
    roboto.setPointSize(14);

    QApplication::setFont(roboto);

    grade_submission = new GradeSubmission(this->parentWidget());

    ui->mainWidget->addWidget(grade_submission);
    ui->mainWidget->setCurrentWidget(grade_submission);
}

MainWindow::~MainWindow()
{

    delete ui;
}


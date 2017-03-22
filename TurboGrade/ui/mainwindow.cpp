#include <QtWidgets>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QFontDatabase::addApplicationFont(":/fonts/res/muli/Bold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/res/muli/Light.ttf");
    int id = QFontDatabase::addApplicationFont(":/fonts/res/muli/Regular.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    muli = QFont(family);

    QFontDatabase::addApplicationFont(":/fonts/res/montserrat/Bold.ttf");
    QFontDatabase::addApplicationFont(":/fonts/res/montserrat/Light.ttf");
    family = QFontDatabase::applicationFontFamilies(QFontDatabase::addApplicationFont(":/fonts/res/montserrat/Regular.ttf")).at(0);
    montserrat = QFont(family);

    grading_view = new GradingView(this->parentWidget());
    grade_overview = new GradeOverview(this->parentWidget());

//    QApplication::setFont(montserrat);

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


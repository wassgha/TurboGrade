#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(QWidget *parent, Controller *controller) :
    QWidget(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    _controller = controller;

    setAttribute(Qt::WA_StyledBackground, true);

    setWindowTitle(tr("TurboGrade - Grading submission"));

    courses = new Courses(this->parentWidget(), _controller);

    ui->mainWidget->addWidget(courses);
    ui->mainWidget->setCurrentWidget(courses);
}

Dashboard::~Dashboard()
{
    delete ui;
    delete courses;
}

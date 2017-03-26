#include "dashboard.h"
#include "ui_dashboard.h"

Dashboard::Dashboard(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground, true);

    setWindowTitle(tr("TurboGrade - Grading submission"));

    courses = new Courses(this->parentWidget());

    ui->mainWidget->addWidget(courses);
    ui->mainWidget->setCurrentWidget(courses);
}

Dashboard::~Dashboard()
{
    delete ui;
    delete courses;
}

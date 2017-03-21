#include "gradeoverview.h"
#include "ui_gradeoverview.h"

GradeOverview::GradeOverview(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GradeOverview)
{
    ui->setupUi(this);
}

GradeOverview::~GradeOverview()
{
    delete ui;
}

void GradeOverview::on_overview_clicked()
{
    MainWindow* parent = qobject_cast<MainWindow*>(this->parent());
    if (parent == 0) { return; }
    parent->setCentralWidget(parent->grading_view);
    parent->grade_overview->hide();
    parent->grading_view->show();
}

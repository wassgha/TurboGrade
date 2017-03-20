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

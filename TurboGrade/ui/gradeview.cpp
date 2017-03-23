#include "gradeview.h"
#include "ui_gradeview.h"

GradeView::GradeView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GradeView)
{
    ui->setupUi(this);
}

GradeView::~GradeView()
{
    delete ui;
}

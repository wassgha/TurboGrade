#include "gradeview.h"
#include "ui_gradeview.h"

GradeView::GradeView(QWidget *parent, Controller *controller) :
    QWidget(parent),
    ui(new Ui::GradeView)
{
    ui->setupUi(this);

    _controller = controller;

}

GradeView::~GradeView()
{
    delete ui;
}

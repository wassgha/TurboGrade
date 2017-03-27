#include "newcourse.h"
#include "ui_newcourse.h"

NewCourse::NewCourse(QWidget *parent) :
    QDialog(parent, Qt::Sheet),
    ui(new Ui::NewCourse)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_StyledBackground, true);
    ui->name->setAttribute(Qt::WA_MacShowFocusRect, false);
    QWidget::setWindowModality(Qt::WindowModal);

}

NewCourse::~NewCourse()
{
    delete ui;
}

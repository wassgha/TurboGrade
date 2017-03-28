#include "newcourse.h"
#include "ui_newcourse.h"

NewCourse::NewCourse(QWidget *parent, Controller *controller) :
    QDialog(parent, Qt::Sheet),
    ui(new Ui::NewCourse)
{
    ui->setupUi(this);

    _controller = controller;

    setWindowTitle("New course");
    setAttribute(Qt::WA_StyledBackground, true);
    ui->name->setAttribute(Qt::WA_MacShowFocusRect, false);
    QWidget::setWindowModality(Qt::WindowModal);

}

NewCourse::~NewCourse()
{
    delete ui;
}

void NewCourse::on_cancel_btn_clicked()
{
    hide();
}

void NewCourse::on_ok_btn_clicked()
{
    _controller->add_course(-1, ui->name->text());

    ui->name->clear();
    emit added_course();
    hide();
}

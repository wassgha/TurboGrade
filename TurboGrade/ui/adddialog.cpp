#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent, Controller *controller) :
    QDialog(parent, Qt::Sheet),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);

    _controller = controller;

    setWindowTitle("New course");
    setAttribute(Qt::WA_StyledBackground, true);
    ui->name->setAttribute(Qt::WA_MacShowFocusRect, false);
    QWidget::setWindowModality(Qt::WindowModal);

}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::on_cancel_btn_clicked()
{
    hide();
}

void AddDialog::on_ok_btn_clicked()
{
    _controller->add_course(-1, ui->name->text());

    ui->name->clear();
    emit submit();
    hide();
}

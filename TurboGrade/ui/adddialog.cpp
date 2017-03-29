#include "adddialog.h"
#include "ui_adddialog.h"

AddDialog::AddDialog(QWidget *parent, QString name, Controller *controller) :
    QDialog(parent, Qt::Sheet),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);

    _controller = controller;

    setWindowTitle("New " + name);
    setAttribute(Qt::WA_StyledBackground, true);
    ui->name->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->name_label->setText(name.left(1).toUpper()+name.mid(1) + " name :");
    ui->title->setText("New " + name);
    ui->ok_btn->setText("ADD " + name);
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
    emit submit();
    hide();
}

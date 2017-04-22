#include "criteriondialog.h"
#include "ui_criteriondialog.h"

CriterionDialog::CriterionDialog(QWidget *parent, Criterion* parent_criterion) :
    QDialog(parent, Qt::Sheet),
    ui(new Ui::CriterionDialog),
  _parent_criterion(parent_criterion)
{
    ui->setupUi(this);
    setWindowTitle("Add Criterion");
    setAttribute(Qt::WA_StyledBackground, true);
    ui->name->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->grade->setAttribute(Qt::WA_MacShowFocusRect, false);

    ui->title->setText("Parent : " + _parent_criterion->_name);

    QWidget::setWindowModality(Qt::WindowModal);
}

CriterionDialog::~CriterionDialog()
{
    delete ui;
}

void CriterionDialog::on_cancel_btn_clicked()
{
    hide();
}

void CriterionDialog::on_ok_btn_clicked()
{
    emit submit();
    hide();
}

void CriterionDialog::disableSubmit() {
    ui->ok_btn->setEnabled(false);
}

void CriterionDialog::enableSubmit() {
    ui->ok_btn->setEnabled(true);
}

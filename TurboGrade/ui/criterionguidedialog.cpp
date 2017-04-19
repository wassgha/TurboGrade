#include "criterionguidedialog.h"
#include "ui_criterionguidedialog.h"

CriterionGuideDialog::CriterionGuideDialog(QWidget *parent, Criterion* parent_criterion) :
    QDialog(parent, Qt::Sheet),
    ui(new Ui::CriterionGuideDialog),
    _parent_criterion(parent_criterion)
{
    ui->setupUi(this);
    setWindowTitle("Add Guide");
    setAttribute(Qt::WA_StyledBackground, true);
    ui->title->setText("Grading Guide for : " + _parent_criterion->_name);
    QWidget::setWindowModality(Qt::WindowModal);

}

CriterionGuideDialog::~CriterionGuideDialog()
{
    delete ui;
}


void CriterionGuideDialog::set_column_width() {
    int column_width = floor(ui->guide->size().width()/ui->guide->columnCount());
    qDebug()<<"Current column width : " << column_width;
    for (int i = 0; i < ui->guide->columnCount(); i++) {
        ui->guide->setColumnWidth(i, column_width);
    }
}


void CriterionGuideDialog::disableSubmit() {
    ui->ok_btn->setEnabled(false);
}

void CriterionGuideDialog::enableSubmit() {
    ui->ok_btn->setEnabled(true);
}

void CriterionGuideDialog::on_ok_btn_clicked()
{
    emit submit();
    hide();
}

void CriterionGuideDialog::on_cancel_btn_clicked()
{
    hide();
}

void CriterionGuideDialog::on_row_count_valueChanged(int value)
{
    ui->guide->setColumnCount(value);
    set_column_width();
}

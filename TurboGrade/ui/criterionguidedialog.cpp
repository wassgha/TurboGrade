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
    ui->score_per_level->setText("Score per level : " + QString::number(_parent_criterion->total_grade()/2));
    QWidget::setWindowModality(Qt::WindowModal);
    ui->row_count->setValue(2);

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
    ui->score_per_level->setText("Score per level : " + QString::number(_parent_criterion->total_grade()/value));
    ui->guide->setColumnCount(value);
    set_column_width();
}

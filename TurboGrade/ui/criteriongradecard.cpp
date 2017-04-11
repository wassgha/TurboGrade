#include "criteriongradecard.h"
#include "ui_criteriongradecard.h"

CriterionGradeCard::CriterionGradeCard(QWidget *parent, Criterion* criterion, int grade) :
    QWidget(parent),
    ui(new Ui::CriterionGradeCard)
{
    ui->setupUi(this);
    ui->criterion->setTitle(criterion->_name);
    ui->grade->setValue(grade);
    ui->out_of->setText("(out of " + QString::number(criterion->_out_of) + ")");
    if (!criterion->has_children()) {
        ui->grade->setEnabled(true);
    }
}

CriterionGradeCard::~CriterionGradeCard()
{
    delete ui;
}

void CriterionGradeCard::update_grade(int grade) {
    ui->grade->setValue(grade);
}

#include "criteriongradecard.h"
#include "ui_criteriongradecard.h"

CriterionGradeCard::CriterionGradeCard(QWidget *parent, Criterion* criterion, Submission* submission) :
    QWidget(parent),
    ui(new Ui::CriterionGradeCard)
{

    _submission = submission;
    _criterion = criterion;

    ui->setupUi(this);
    ui->criterion->setTitle(criterion->_name);
    ui->out_of->setText("(out of " + QString::number(criterion->_out_of) + ")");
    if (!criterion->has_children()) {
        ui->grade->setEnabled(true);
    }
    update_grade();
}

CriterionGradeCard::~CriterionGradeCard()
{
    delete ui;
}

void CriterionGradeCard::update_grade() {
    ui->grade->setValue(_submission->get_grade(_criterion));
}

void CriterionGradeCard::on_grade_valueChanged(int grade)
{
    _submission->update_grade(_criterion, grade);
}

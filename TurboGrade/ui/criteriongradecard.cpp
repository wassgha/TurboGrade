#include "criteriongradecard.h"
#include "ui_criteriongradecard.h"

CriterionGradeCard::CriterionGradeCard(QWidget *parent, Criterion* criterion, Submission* submission) :
    QWidget(parent),
    ui(new Ui::CriterionGradeCard)
{

    ui->setupUi(this);

    _submission = submission;
    _criterion = criterion;

    if (criterion->_parent != nullptr) {
        ui->comments_box->hide();
        ui->children->setContentsMargins(0,0,0,0);
    }

    ui->criterion->setTitle(criterion->_name);
    ui->out_of->setText("(out of " + QString::number(criterion->_out_of) + ")");
    ui->grade->setMaximum(criterion->_out_of);
    ui->grade->setAttribute(Qt::WA_MacShowFocusRect, false);
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
    emit grade_changed();
}

void CriterionGradeCard::insert_child(QWidget* child) {
    ui->children->addWidget(child);
}

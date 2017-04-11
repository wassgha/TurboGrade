#include "gradeview.h"
#include "ui_gradeview.h"
#include "criteriongradecard.h"
#include "ui_criteriongradecard.h"

GradeView::GradeView(QWidget *parent, Controller *controller) :
    QWidget(parent),
    ui(new Ui::GradeView)
{
    ui->setupUi(this);

    installEventFilter(this);

    _controller = controller;
    _parent = dynamic_cast<GradeSubmission*>(parent);

    for (Criterion* criterion : *_parent->_submission->_assignment->_rubric->_criteria) {
        ui->verticalLayout_3->insertWidget(2,
                                           new CriterionGradeCard(
                                               this,
                                               criterion,
                                               _parent->_submission->get_grade(criterion)));
    }

}

GradeView::~GradeView()
{
    delete ui;
}

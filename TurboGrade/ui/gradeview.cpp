#include "gradeview.h"
#include "ui_gradeview.h"

GradeView::GradeView(QWidget *parent, Controller *controller) :
    QWidget(parent),
    ui(new Ui::GradeView)
{
    ui->setupUi(this);

    installEventFilter(this);

    _controller = controller;
    _parent = dynamic_cast<GradeSubmission*>(parent);

    for (Criterion* criterion : *_parent->_submission->_assignment->_rubric->_criteria) {

        CriterionGradeCard *card = new CriterionGradeCard(
                    this,
                    criterion,
                    _parent->_submission->get_grade(criterion));
        _cards[criterion] = card;
        ui->verticalLayout_3->insertWidget(2, card);
    }

}

void GradeView::update_grades() {
    for (std::pair<Criterion*, CriterionGradeCard*>card : _cards) {
        card.second->update_grade(_parent->_submission->get_grade(card.first));
    }
}

GradeView::~GradeView()
{
    for (std::pair<Criterion*, CriterionGradeCard*>card : _cards) {
        delete card.second;
    }
    delete ui;
}

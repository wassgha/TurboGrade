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
                    _parent->_submission);
        _cards[criterion] = card;
        ui->verticalLayout_3->insertWidget(2, card);
        connect(card, SIGNAL(grade_changed()), this, SLOT(update_grades()));
        for (Criterion* child : *criterion->_sub_criteria) {

            CriterionGradeCard *child_card = new CriterionGradeCard(
                        this,
                        child,
                        _parent->_submission);
            _cards[child] = child_card;
            card->insert_child(child_card);
            connect(child_card, SIGNAL(grade_changed()), this, SLOT(update_grades()));
        }
    }

    ui->dummy1->hide();
    ui->dummy2->hide();

}

void GradeView::update_grades() {
    for (std::pair<Criterion*, CriterionGradeCard*>card : _cards) {
        card.second->update_grade();
    }
}

GradeView::~GradeView()
{
    for (std::pair<Criterion*, CriterionGradeCard*>card : _cards) {
        delete card.second;
    }
    delete ui;
}

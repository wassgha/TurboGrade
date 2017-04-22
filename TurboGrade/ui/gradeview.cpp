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
    ui->total_grade->setText("Total Grade : " +
                             QString::number(_parent->_submission->grade_percent()) +
                             "% (" +
                             QString::number(_parent->_submission->get_grade()) +
                             " out of " +
                             QString::number(_parent->_submission->_assignment->_rubric->total_grade()) +
                             ")");
}

GradeView::~GradeView()
{
    for (std::pair<Criterion*, CriterionGradeCard*>card : _cards) {
        delete card.second;
    }
    delete ui;
}

void GradeView::on_finalize_clicked()
{
    _parent->_submission->update_status(2);
}

void GradeView::on_export_pdf_clicked()
{
    QString folder = QFileDialog::getExistingDirectory(this, tr("Save report in..."), QString(),
                                                       QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (folder != "") {
        StudentDeliverable s;
        QString html = s.placeParameters(_parent->_submission);
        HTMLToPDF* report = new HTMLToPDF(html, folder + "/" + _parent->_submission->_student->_name + ".pdf");
    }

}

#include "criteriongradecard.h"
#include "ui_criteriongradecard.h"

CriterionGradeCard::CriterionGradeCard(QWidget *parent, Criterion* criterion, Submission* submission) :
    QWidget(parent),
    ui(new Ui::CriterionGradeCard),
    _parent(dynamic_cast<GradeView*>(parent))
{

    ui->setupUi(this);

    _submission = submission;
    _criterion = criterion;

    if (criterion->_parent != nullptr) {
        ui->children->setContentsMargins(0,0,0,0);
    }

    ui->comments_container->hide();

    ui->title->setText(criterion->_name);
    ui->out_of->setText(" / " + QString::number(criterion->_out_of));
    qDebug() << "testing";
    ui->grade->setMaximum(criterion->_out_of);
    ui->grade->setAttribute(Qt::WA_MacShowFocusRect, false);
    if (!criterion->has_children()) {
        ui->grade->setEnabled(true);
    }

    update_grade();
    update_comments();
}

CriterionGradeCard::~CriterionGradeCard()
{
    delete ui;
}

void CriterionGradeCard::update_grade() {
    ui->grade->setValue(_submission->get_grade(_criterion));
    for (int i = 0; i < ui->children->count(); ++i)
    {
        CriterionGradeCard *card = dynamic_cast<CriterionGradeCard*>(ui->children->itemAt(i)->widget());
        if (card != NULL)
        {
            card->update_grade();
        }
    }
}

void CriterionGradeCard::update_comments() {
    QLayoutItem *child;
    for(QWidget *widget: _comments) {
        ui->comments_container_layout->removeWidget(widget);
        if (widget != nullptr)
            delete widget;
    }
    _comments.clear();

    // Record number of comments
    int i = 0;

    for (Comment *comment : _submission->get_comments(_criterion)) {
        // Add the file name
        QLabel *file_name = new QLabel("On file \"" + comment->_filename + "\"");
        _comments.push_back(file_name);
        ui->comments_container_layout->addWidget(file_name);
        // Add the comment card
        CommentCard* comment_card = new CommentCard(this, comment, _parent->_parent, true);
        _comments.push_back(comment_card);
        ui->comments_container_layout->addWidget(comment_card);
        connect(comment_card, SIGNAL(clicked(Comment*)), this, SLOT(show_comment(Comment*)));
        i++;
    }
    for (Criterion *child : _criterion->children()) {
        for (Comment *comment : _submission->get_comments(child)) {
            // Add the file name
            QLabel *file_name = new QLabel("On file \"" + comment->_filename + "\"");
            _comments.push_back(file_name);
            ui->comments_container_layout->addWidget(file_name);
            // Add the comment card
            CommentCard* comment_card = new CommentCard(this, comment, _parent->_parent, true);
            _comments.push_back(comment_card);
            ui->comments_container_layout->addWidget(comment_card);
            connect(comment_card, SIGNAL(clicked(Comment*)), this, SLOT(show_comment(Comment*)));
            i++;
        }
    }

    if (i == 0) {
        QLabel *no_comments = new QLabel("No comments on this criterion");
        _comments.push_back(no_comments);
        ui->comments_container_layout->addWidget(no_comments);
    }
}

void CriterionGradeCard::on_grade_valueChanged(int grade)
{
    if (grade != _submission->get_grade(_criterion)) {
        _submission->update_grade(_criterion, grade);
        emit grade_changed();
    }
}

void CriterionGradeCard::insert_child(QWidget* child) {
    ui->children->addWidget(child);
}

void CriterionGradeCard::show_comment(Comment* comment) {
    _parent->_parent->code_view->show_comment(comment);
}

#include "commentcard.h"
#include "ui_commentcard.h"

CommentCard::CommentCard(QWidget *parent, Comment *comment) :
    QWidget(parent),
    ui(new Ui::CommentCard)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_StyledBackground, true);
    setAttribute(Qt::WA_Hover);
    setMouseTracking(true);

    _comment = comment;

    QString sign = ((_comment->_grade > 0) ? "+" : "-");

    ui->adjust_grade->setText("( " + sign
                                   + QString::number(abs(_comment->_grade))
                                   + " )");
    if (_comment->_grade > 0) {
        ui->adjust_grade->setStyleSheet("#adjust_grade { color : rgb(27, 172, 37); }");
    } else if (_comment->_grade == 0) {
        ui->adjust_grade->hide();
    } else {
        ui->adjust_grade->setStyleSheet("#adjust_grade { color : rgb(195, 0, 66); }");
    }

    ui->comment->setText(_comment->_text);
    if (_comment->_criterion != nullptr) {
        ui->rubric->setText("On rubric: \"" + _comment->_criterion->_name + "\"");
    } else {
        ui->rubric->setText("No rubric specified");
        if (_comment->_grade == 0)
            ui->info_container->hide();
    }
}

CommentCard::~CommentCard()
{
    delete ui;
}

void CommentCard::enterEvent(QEvent * event)
{
    emit mouseOver(_comment);
}

void CommentCard::leaveEvent(QEvent * event)
{
    emit mouseOut(_comment);
}

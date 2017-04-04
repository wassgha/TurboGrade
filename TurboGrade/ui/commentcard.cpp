#include "commentcard.h"
#include "ui_commentcard.h"

CommentCard::CommentCard(QWidget *parent, Comment *comment) :
    QWidget(parent),
    ui(new Ui::CommentCard)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_StyledBackground, true);

    _comment = comment;

    QString sign = ((_comment->_grade > 0) ? "+" : "-");

    ui->adjust_grade->setText("( " + sign
                                   + QString::number(abs(_comment->_grade))
                                   + " )");
    ui->comment->setText(_comment->_text);
    if (_comment->_criterion != nullptr)
        ui->rubric->setText("On rubric: \"" + _comment->_criterion->_name + "\"");
    else
        ui->rubric->setText("");
}

CommentCard::~CommentCard()
{
    delete ui;
}

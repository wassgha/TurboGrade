#include "commentpopup.h"
#include "ui_commentpopup.h"

CommentPopup::CommentPopup(QWidget *parent, Controller *controller) :
    QWidget(parent, Qt::Tool | Qt::FramelessWindowHint),
    ui(new Ui::CommentPopup)
{
    setAttribute(Qt::WA_ShowWithoutActivating);
    ui->setupUi(this);

    _controller = controller;

}

CommentPopup::~CommentPopup()
{
    delete ui;
}

void CommentPopup::on_add_btn_clicked()
{
    this->hide();
    ui->adjust_grade->setValue(0);
    ui->comment->clear();
    ui->rubric->setCurrentIndex(0);
}

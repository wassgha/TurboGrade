#include "commentpopup.h"
#include "ui_commentpopup.h"

CommentPopup::CommentPopup(QWidget *parent) :
    QWidget(parent, Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint),
    ui(new Ui::CommentPopup)
{
    ui->setupUi(this);
}

CommentPopup::~CommentPopup()
{
    delete ui;
}

#include "commentpopup.h"
#include "ui_commentpopup.h"

CommentPopup::CommentPopup(QWidget *parent, Controller *controller) :
    QWidget(parent, Qt::Dialog | Qt::FramelessWindowHint),
    ui(new Ui::CommentPopup)
{
    ui->setupUi(this);

    ui->adjust_grade->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->comment->setAttribute(Qt::WA_MacShowFocusRect, false);
    ui->criterion->setAttribute(Qt::WA_MacShowFocusRect, false);

    _controller = controller;

}

CommentPopup::~CommentPopup()
{
    delete ui;
}

void CommentPopup::on_add_btn_clicked()
{
    qDebug()<<"emitted signal submit";
    emit submit();
}

QString CommentPopup::val(QString name) {

    if (name == "adjust_grade") {
        QString val = ui->adjust_grade->text();
        ui->adjust_grade->setValue(0);
        return val;
    } else if (name == "comment") {
        QString val = ui->comment->text();
        ui->comment->clear();
        return val;
    } else if (name == "criterion") {
        ui->criterion->setCurrentIndex(0);
        return QString();
    } else {
        return QString();
    }

}

QString CommentPopup::peek(QString name) {

    if (name == "adjust_grade") {
        QString val = ui->adjust_grade->text();
        return val;
    } else if (name == "comment") {
        QString val = ui->comment->text();
        return val;
    } else {
        return QString();
    }

}

#ifndef COMMENTPOPUP_H
#define COMMENTPOPUP_H

#include <QWidget>

#include "../engine/controller.h"


namespace Ui {
class CommentPopup;
}

class CommentPopup : public QWidget
{
    Q_OBJECT

public:
    explicit CommentPopup(QWidget *parent = 0, Controller* controller = nullptr);
    ~CommentPopup();
    QString val(QString name);
    QString peek(QString name);

    Ui::CommentPopup *ui;
    Controller *_controller;

private slots:
    void on_add_btn_clicked();

signals:
    void submit();
};

#endif // COMMENTPOPUP_H

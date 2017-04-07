#ifndef COMMENTCARD_H
#define COMMENTCARD_H

#include <QWidget>
#include <QMouseEvent>
#include <QEvent>

#include "../engine/controller.h"


namespace Ui {
class CommentCard;
}

class CommentCard : public QWidget
{
    Q_OBJECT

public:
    explicit CommentCard(QWidget *parent = 0, Comment* comment = nullptr);
    ~CommentCard();

    Ui::CommentCard *ui;
    Comment* _comment;

private slots:
    void enterEvent(QEvent * event);
    void leaveEvent(QEvent * event);

signals:
    void mouseOver(Comment* comment);
    void mouseOut(Comment* comment);
};

#endif // COMMENTCARD_H

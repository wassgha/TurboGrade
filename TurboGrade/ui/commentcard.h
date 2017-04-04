#ifndef COMMENTCARD_H
#define COMMENTCARD_H

#include <QWidget>

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

};

#endif // COMMENTCARD_H

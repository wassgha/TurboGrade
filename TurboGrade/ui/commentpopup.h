#ifndef COMMENTPOPUP_H
#define COMMENTPOPUP_H

#include <QWidget>

namespace Ui {
class CommentPopup;
}

class CommentPopup : public QWidget
{
    Q_OBJECT

public:
    explicit CommentPopup(QWidget *parent = 0);
    ~CommentPopup();
    Ui::CommentPopup *ui;
};

#endif // COMMENTPOPUP_H

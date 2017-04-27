#ifndef COMMENTCARD_H
#define COMMENTCARD_H

#include <QWidget>
#include <QMouseEvent>
#include <QEvent>
#include <QGraphicsDropShadowEffect>

#include "../engine/controller.h"

#include "gradesubmission.h"
#include "ui_gradesubmission.h"

class GradeSubmission;

namespace Ui {
class CommentCard;
}

class CommentCard : public QWidget
{
    Q_OBJECT

public:
    explicit CommentCard(QWidget *parent = 0, Comment* comment = nullptr, GradeSubmission* grade_submission = nullptr, bool grade_view = false);
    ~CommentCard();

    Ui::CommentCard *ui;
    Comment* _comment;

private slots:
    void enterEvent(QEvent * event);
    void leaveEvent(QEvent * event);
    void mousePressEvent(QMouseEvent *event);

    void on_delete_btn_clicked();

signals:
    void mouseOver(Comment* comment);
    void mouseOut(Comment* comment);
    void clicked(Comment* comment);

private:
    GradeSubmission* _grade_submission;
};

#endif // COMMENTCARD_H

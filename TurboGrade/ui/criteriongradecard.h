#ifndef CRITERIONGRADECARD_H
#define CRITERIONGRADECARD_H

#include <QWidget>

#include "../engine/controller.h"

#include "commentcard.h"
#include "ui_commentcard.h"

#include "gradeview.h"
#include "ui_gradeview.h"

class GradeView;

namespace Ui {
class CriterionGradeCard;
}

class CriterionGradeCard : public QWidget
{
    Q_OBJECT

public:
    explicit CriterionGradeCard(QWidget *parent = 0,
                                Criterion* criterion = nullptr,
                                Submission* submission = nullptr);
    ~CriterionGradeCard();
    void update_grade();
    void update_comments();
    void insert_child(QWidget* child);

public slots:
    void show_comment(Comment* comment);

private slots:
    void on_grade_valueChanged(int grade);

    void on_show_comments_clicked();

signals:
    void grade_changed();

private:
    Ui::CriterionGradeCard *ui;
    Submission* _submission;
    Criterion* _criterion;
    std::vector<QWidget*> _comments;
    GradeView* _parent;
};

#endif // CRITERIONGRADECARD_H

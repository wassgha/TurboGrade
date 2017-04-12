#ifndef CRITERIONGRADECARD_H
#define CRITERIONGRADECARD_H

#include <QWidget>

#include "../engine/controller.h"

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

private slots:
    void on_grade_valueChanged(int grade);

private:
    Ui::CriterionGradeCard *ui;
    Submission* _submission;
    Criterion* _criterion;
};

#endif // CRITERIONGRADECARD_H

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
    explicit CriterionGradeCard(QWidget *parent = 0, Criterion* criterion = nullptr, int grade = 0);
    ~CriterionGradeCard();
    void update_grade(int grade);

private:
    Ui::CriterionGradeCard *ui;
};

#endif // CRITERIONGRADECARD_H

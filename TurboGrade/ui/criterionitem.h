#ifndef CRITERIONITEM_H
#define CRITERIONITEM_H

#include <QWidget>
#include "../engine/criterion.h"

namespace Ui {
class CriterionItem;
}

class CriterionItem : public QWidget
{
    Q_OBJECT

public:
    explicit CriterionItem(QWidget *parent = 0, Criterion *criterion = nullptr);
    ~CriterionItem();
    bool isChild();
    Criterion *_criterion = nullptr;
    Ui::CriterionItem *ui;

public slots:
    void add_child();

signals:
    void added_child(Criterion* criterion);

};

#endif // CRITERIONITEM_H

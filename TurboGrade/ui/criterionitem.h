#ifndef CRITERIONITEM_H
#define CRITERIONITEM_H

#include <QWidget>

namespace Ui {
class CriterionItem;
}

class CriterionItem : public QWidget
{
    Q_OBJECT

public:
    explicit CriterionItem(QWidget *parent = 0, QString name = "", int out_of = 0);
    ~CriterionItem();

private:
    Ui::CriterionItem *ui;
};

#endif // CRITERIONITEM_H

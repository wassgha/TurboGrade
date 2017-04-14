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
public slots:
    void add_child();

signals:
//    void add_criterion(Criterion* criterion);

private:
    Ui::CriterionItem *ui;
};

#endif // CRITERIONITEM_H

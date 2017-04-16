#ifndef RUBRICVIEW_H
#define RUBRICVIEW_H

#include "../engine/controller.h"
#include "../engine/controller.h"

#include "criteriondialog.h"
#include "ui_criteriondialog.h"

#include "criterionitem.h"
#include "ui_criterionitem.h"

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>

namespace Ui {
class RubricView;
}

class RubricView : public QWidget
{
    Q_OBJECT

public:
    explicit RubricView(QWidget *parent = 0, Assignment *assignment = nullptr);
    ~RubricView();

private:
    void refresh_criteria();
    void remove_criteria();
    CriterionItem* add_item(Criterion * criterion, CriterionItem *parent = nullptr);
    Ui::RubricView *ui;
    Assignment* _assignment;
    CriterionDialog *_add_dialog = nullptr;
    std::vector<CriterionItem*> items;

private slots:
    void add_criterion();
    void add_child();
    void add_criterion(Criterion* parent);
};

#endif // RUBRICVIEW_H

#ifndef CRITERIONDIALOG_H
#define CRITERIONDIALOG_H

#include <QDialog>
#include "../engine/criterion.h"

namespace Ui {
class CriterionDialog;
}

class CriterionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CriterionDialog(QWidget *parent = 0, Criterion* parent_criterion = nullptr);
    ~CriterionDialog();
    void disableSubmit();
    void enableSubmit();
    Ui::CriterionDialog *ui;
    Criterion *_parent_criterion;

private slots:
    void on_ok_btn_clicked();
    void on_cancel_btn_clicked();


signals:
    void submit();
};

#endif // CRITERIONDIALOG_H

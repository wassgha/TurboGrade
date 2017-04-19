#ifndef CRITERIONGUIDEDIALOG_H
#define CRITERIONGUIDEDIALOG_H

#include <QDialog>
#include "../engine/criterion.h"

namespace Ui {
class CriterionGuideDialog;
}

class CriterionGuideDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CriterionGuideDialog(QWidget *parent = 0, Criterion* parent_criterion = nullptr);
    ~CriterionGuideDialog();
    void disableSubmit();
    void enableSubmit();
    void set_column_width();
    Ui::CriterionGuideDialog *ui;
    Criterion *_parent_criterion;

private slots:
    void on_ok_btn_clicked();
    void on_cancel_btn_clicked();
    void on_row_count_valueChanged(int value);

signals:
    void submit();

};

#endif // CRITERIONGUIDEDIALOG_H

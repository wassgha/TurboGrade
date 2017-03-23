#ifndef GRADESUBMISSION_H
#define GRADESUBMISSION_H

#include <QWidget>

#include "codeview.h"
#include "ui_codeview.h"
#include "gradeview.h"
#include "ui_gradeview.h"

class GradeView;
class CodeView;

namespace Ui {
class GradeSubmission;
}

class GradeSubmission : public QWidget
{
    Q_OBJECT

public:
    explicit GradeSubmission(QWidget *parent = 0);
    ~GradeSubmission();
    CodeView *code_view;
    GradeView *grade_view;

private slots:
    void on_run_clicked();

    void on_toggle_clicked();

    void finished_running();

private:
    Ui::GradeSubmission *ui;
};

#endif // GRADESUBMISSION_H

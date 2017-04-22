#ifndef GRADESUBMISSION_H
#define GRADESUBMISSION_H

#include <QWidget>
#include <QTimer>
#include <QEvent>
#include <QMoveEvent>
#include <QFocusEvent>

#include "../engine/controller.h"
#include "../engine/controller.h"

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
    explicit GradeSubmission(QWidget *parent = 0, Submission *submission = nullptr, Controller* controller = nullptr);
    ~GradeSubmission();
    CodeView *code_view;
    GradeView *grade_view;
    Controller *_controller;
    Submission *_submission;

private slots:
    void refresh_students();

    void on_run_clicked();

    void on_toggle_clicked();

    void finished_running();

    void on_hideName_toggled(bool checked);

private:
    bool eventFilter(QObject *watched, QEvent *event) override;

    Ui::GradeSubmission *ui;
    QProcess *compile = nullptr;
};

#endif // GRADESUBMISSION_H

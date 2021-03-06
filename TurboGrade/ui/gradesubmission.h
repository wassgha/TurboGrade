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

#include "dashboard.h"
#include "ui_dashboard.h"

#include "fireworks.h"

class GradeView;
class CodeView;
class Dashboard;
class CommentCard;

namespace Ui {
class GradeSubmission;
}

class GradeSubmission : public QWidget
{
    Q_OBJECT

public:
    explicit GradeSubmission(QWidget *parent = 0, Submission *submission = nullptr, Controller* controller = nullptr);
    ~GradeSubmission();
    void update_next();
    void update_progress();
    void display_fireworks();
    void update_finalize_button();
    CodeView *code_view;
    GradeView *grade_view;
    Controller *_controller;
    Submission *_submission;

private slots:
    void refresh_students();

    void on_run_clicked();

    void finished_running();

    void on_hideName_toggled(bool checked);

    void on_studentName_currentIndexChanged(int index);

    void show_dashboard();

    void next_submission();

    void hide_fireworks();

    void on_finalize_clicked();

    void on_exportpdf_clicked();

private:
    bool eventFilter(QObject *watched, QEvent *event) override;

    Ui::GradeSubmission *ui;
    QProcess *compile = nullptr;
    Dashboard* _parent = nullptr;
    Fireworks *fireworks = nullptr;

signals:
    void switched_submission(QObject* submission);
};

#endif // GRADESUBMISSION_H

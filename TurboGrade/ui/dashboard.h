#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QDesktopServices>
#include <QFontDatabase>
#include <QTimer>

#include "../engine/controller.h"
#include "../engine/controller.h"

#include "gradesubmission.h"
#include "ui_gradesubmission.h"

#include "courseview.h"
#include "sectionview.h"
#include "assignmentview.h"
#include "studentview.h"
#include "submissionview.h"

class CardsView;
class ListView;


class CourseView;
class SectionView;
class SubmissionView;
class AssignmentView;
class StudentView;
class GradeSubmission;

namespace Ui {
class Dashboard;
}

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = 0);
    ~Dashboard();
    CourseView *courses = nullptr;
    SectionView *sections = nullptr;
    AssignmentView *assignments = nullptr;
    StudentView *students = nullptr;
    SubmissionView *submissions = nullptr;
    Controller *_controller = nullptr;
    GradeSubmission *grade_submission = nullptr;
    QFont roboto;

private slots:
    void on_tutorial_btn_clicked();

public slots:
    void show_courses();
    void show_sections(QObject* course);
    void show_assignments(QObject* section);
    void show_students(QObject* section);
    void show_submissions(QObject* section, QObject* assignment);
    void start_grading(QObject* submission);
    void toggle_headers(bool show);
    void remove_current_widget();

private:
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H

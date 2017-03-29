#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>
#include <QDesktopServices>
#include <QFontDatabase>

#include "../engine/controller.h"
#include "../engine/controller.h"

#include "gradesubmission.h"
#include "ui_gradesubmission.h"

#include "courseview.h"
#include "sectionview.h"
#include "assignmentview.h"

class CourseView;
class SectionView;
class AssignmentView;
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
    Controller *_controller = nullptr;
    GradeSubmission *grade_submission = nullptr;
    QFont roboto;

private slots:
    void on_tutorial_btn_clicked();

public slots:
    void show_sections(void* course);
    void show_assignments(void* section);

private:
    Ui::Dashboard *ui;
};

#endif // DASHBOARD_H

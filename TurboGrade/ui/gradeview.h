#ifndef GRADEVIEW_H
#define GRADEVIEW_H

#include "../engine/controller.h"
#include "../engine/controller.h"

#include "criteriongradecard.h"
#include "ui_criteriongradecard.h"

#include "gradesubmission.h"
#include "ui_gradesubmission.h"

#include "dashboard.h"
#include "ui_dashboard.h"

#include <QMainWindow>
#include <QWidget>

class CriterionGradeCard;

class GradeSubmission;

namespace Ui {
class GradeView;
}

class GradeView : public QWidget
{
    Q_OBJECT

public:
    explicit GradeView(QWidget *parent, Controller* controller = nullptr);
    ~GradeView();
    void update_status();

    Ui::GradeView *ui;
    Controller                  *_controller;
    GradeSubmission             *_parent;
    // Criterion cards
    std::map<Criterion*, CriterionGradeCard*> _cards;


public slots:
    void update_grades();
};

#endif // GRADEVIEW_H

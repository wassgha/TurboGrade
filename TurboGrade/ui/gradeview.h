#ifndef GRADEVIEW_H
#define GRADEVIEW_H

#include "../engine/controller.h"
#include "../engine/controller.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QWidget>

namespace Ui {
class GradeView;
}

class GradeView : public QWidget
{
    Q_OBJECT

public:
    explicit GradeView(QWidget *parent, Controller* controller = nullptr);
    ~GradeView();
    Ui::GradeView *ui;
    Controller *_controller;

};

#endif // GRADEVIEW_H

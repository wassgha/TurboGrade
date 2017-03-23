#ifndef GRADEVIEW_H
#define GRADEVIEW_H

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
    explicit GradeView(QWidget *parent);
    ~GradeView();
    Ui::GradeView *ui;

};

#endif // GRADEVIEW_H

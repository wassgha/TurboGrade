#ifndef GRADEOVERVIEW_H
#define GRADEOVERVIEW_H

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QWidget>

namespace Ui {
class GradeOverview;
}

class GradeOverview : public QWidget
{
    Q_OBJECT

public:
    explicit GradeOverview(QWidget *parent);
    ~GradeOverview();
    Ui::GradeOverview *ui;

private slots:
    void on_code_view_clicked();

signals:
    void toggle();
};

#endif // GRADEOVERVIEW_H

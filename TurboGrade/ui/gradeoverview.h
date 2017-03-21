#ifndef GRADEOVERVIEW_H
#define GRADEOVERVIEW_H

#include "mainwindow.h"

#include <QMainWindow>
#include <QWidget>

namespace Ui {
class GradeOverview;
}

class GradeOverview : public QWidget
{
    Q_OBJECT

public:
    explicit GradeOverview(QWidget *parent = 0);
    ~GradeOverview();

private slots:
    void on_overview_clicked();

private:
    Ui::GradeOverview *ui;
};

#endif // GRADEOVERVIEW_H

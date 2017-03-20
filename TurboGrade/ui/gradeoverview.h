#ifndef GRADEOVERVIEW_H
#define GRADEOVERVIEW_H

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

private:
    Ui::GradeOverview *ui;
};

#endif // GRADEOVERVIEW_H

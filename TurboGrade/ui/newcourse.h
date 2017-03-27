#ifndef NEWCOURSE_H
#define NEWCOURSE_H

#include <QDialog>

namespace Ui {
class NewCourse;
}

class NewCourse : public QDialog
{
    Q_OBJECT

public:
    explicit NewCourse(QWidget *parent = 0);
    ~NewCourse();

private:
    Ui::NewCourse *ui;
};

#endif // NEWCOURSE_H

#ifndef COURSES_H
#define COURSES_H

#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>

namespace Ui {
class Courses;
}

class Courses : public QWidget
{
    Q_OBJECT

public:
    explicit Courses(QWidget *parent = 0);
    ~Courses();
    void add_course(QWidget *course);

private:
    Ui::Courses *ui;
    int max_col = 3;
    int cur_col = 0;
    int cur_row = 0;
};

#endif // COURSES_H

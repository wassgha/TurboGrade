#ifndef NEWCOURSE_H
#define NEWCOURSE_H

#include "../engine/controller.h"
#include "../engine/controller.h"

#include <QDialog>

namespace Ui {
class NewCourse;
}

class NewCourse : public QDialog
{
    Q_OBJECT

public:
    explicit NewCourse(QWidget *parent = 0, Controller *controller = nullptr);
    ~NewCourse();
    Controller *_controller;

private slots:
    void on_cancel_btn_clicked();

    void on_ok_btn_clicked();

private:
    Ui::NewCourse *ui;

signals:
    void added_course();

};

#endif // NEWCOURSE_H

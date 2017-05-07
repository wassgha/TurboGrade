#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>
#include "../engine/controller.h"

namespace Ui {
class Preferences;
}

class Preferences : public QDialog
{
    Q_OBJECT

public:
    explicit Preferences(QWidget *parent = 0, Controller *controller = nullptr);
    ~Preferences();

private slots:
    void on_save_btn_clicked();

private:
    Ui::Preferences *ui;
    Controller *_controller;
};

#endif // PREFERENCES_H

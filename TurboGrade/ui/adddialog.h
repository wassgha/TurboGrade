#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include "../engine/controller.h"
#include "../engine/controller.h"

#include <QDialog>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = 0, QString name = "", Controller *controller = nullptr);
    ~AddDialog();
    Controller *_controller;
    Ui::AddDialog *ui;

private slots:
    void on_cancel_btn_clicked();

    void on_ok_btn_clicked();

signals:
    void submit();

};

#endif // ADDDIALOG_H

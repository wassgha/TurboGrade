#ifndef FORMDIALOG_H
#define FORMDIALOG_H

#include "../engine/controller.h"
#include "../engine/controller.h"

#include <QDialog>
#include <QFileDialog>
#include <QLineEdit>
#include <QTextEdit>

namespace Ui {
class FormDialog;
}

class FormDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FormDialog(QWidget *parent = 0, QString title = "New");
    ~FormDialog();

    QWidget* add_field(QString type,
                   QString name = "obj",
                   QString label = "",
                   QString placeholder = "");
    QString val(QString name);

    Ui::FormDialog *ui;
    std::map<QString, QWidget*> _fields;
    std::map<QString, QString> _field_types;

    QString _data = "";

private slots:
    void on_cancel_btn_clicked();

    void on_ok_btn_clicked();

    void select_folder();

signals:
    void submit();

};

#endif // FORMDIALOG_H

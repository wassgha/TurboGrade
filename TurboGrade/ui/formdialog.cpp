#include "formdialog.h"
#include "ui_formdialog.h"

FormDialog::FormDialog(QWidget *parent, QString title) :
    QDialog(parent, Qt::Sheet),
    ui(new Ui::FormDialog)
{
    ui->setupUi(this);

    setWindowTitle(title);
    setAttribute(Qt::WA_StyledBackground, true);
    ui->title->setText(title);

    ui->formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
    ui->formLayout->setFieldGrowthPolicy(QFormLayout::ExpandingFieldsGrow);
    ui->formLayout->setFormAlignment(Qt::AlignLeft | Qt::AlignTop);
    ui->formLayout->setLabelAlignment(Qt::AlignLeft);

    QWidget::setWindowModality(Qt::WindowModal);

}

FormDialog::~FormDialog()
{
    for(std::pair<QString, QWidget*> field: _fields)
        delete field.second;
    delete ui;
}

void FormDialog::add_field(QString type, QString name,
                           QString label, QString placeholder) {
    if (type == "QLineEdit") {

        QLineEdit* field = new QLineEdit();
        field->setAttribute(Qt::WA_MacShowFocusRect, false);
        field->setObjectName(name);
        field->setPlaceholderText(placeholder);
        _fields[name] = field;
        _field_types[name] = type;
        ui->formLayout->addRow(label, field);

    }
}

QString FormDialog::val(QString name) {

    if (_field_types[name] == "QLineEdit") {
        QLineEdit* field = findChild<QLineEdit*>(name);
        QString text = field->text();
        field->clear();
        return text;
    }
}

void FormDialog::on_cancel_btn_clicked()
{
    hide();
}

void FormDialog::on_ok_btn_clicked()
{
    emit submit();
    hide();
}

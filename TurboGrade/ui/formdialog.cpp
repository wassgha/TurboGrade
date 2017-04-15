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
    delete ui;
}

QWidget* FormDialog::add_field(QString type, QString name,
                           QString label, QString placeholder) {

    QWidget* field;

    if (type == "QLineEdit") {

        field = new QLineEdit();
        dynamic_cast<QLineEdit*>(field)->setAttribute(Qt::WA_MacShowFocusRect, false);
        dynamic_cast<QLineEdit*>(field)->setObjectName(name);
        dynamic_cast<QLineEdit*>(field)->setPlaceholderText(placeholder);
        ui->formLayout->addRow(label, field);

    } else if (type == "QLabel") {

        field = new QLabel(label);
        dynamic_cast<QLabel*>(field)->setAttribute(Qt::WA_MacShowFocusRect, false);
        dynamic_cast<QLabel*>(field)->setObjectName(name);
        ui->formLayout->addRow(field);

    } else if (type == "QProgressBar") {

        field = new QProgressBar();
        dynamic_cast<QProgressBar*>(field)->setObjectName(name);
        dynamic_cast<QProgressBar*>(field)->setMaximum(0);
        dynamic_cast<QProgressBar*>(field)->setValue(0);
        ui->formLayout->addRow(field);
        field->hide();

    } else if (type == "QCheckBox") {

        field = new QCheckBox(label);
        dynamic_cast<QCheckBox*>(field)->setObjectName(name);
        ui->formLayout->addRow(field);

    } else if (type == "Separator") {

        field = new QFrame();
        dynamic_cast<QFrame*>(field)->setFrameShape(QFrame::HLine);
        dynamic_cast<QFrame*>(field)->setFrameShadow(QFrame::Sunken);
        dynamic_cast<QFrame*>(field)->setObjectName(name);
        ui->formLayout->addRow(field);

    } else if (type == "QComboBox") {

        field = new QComboBox();
        dynamic_cast<QComboBox*>(field)->setObjectName(name);
        ui->formLayout->addRow(label, field);

    } else if (type == "QFileDialog") {

        field = new QPushButton(label);
        dynamic_cast<QPushButton*>(field)->setObjectName(name);
        QPixmap pixmap(placeholder);
        QIcon ButtonIcon(pixmap);
        dynamic_cast<QPushButton*>(field)->setIcon(ButtonIcon);
        dynamic_cast<QPushButton*>(field)->setIconSize(QSize(16,16));
        dynamic_cast<QPushButton*>(field)->setCursor(Qt::PointingHandCursor);
        ui->formLayout->addRow(field);
        connect(field, SIGNAL(clicked()), this, SLOT(select_folder()));

    } else if (type == "QTextEdit") {

        field = new QTextEdit();
        dynamic_cast<QTextEdit*>(field)->setAttribute(Qt::WA_MacShowFocusRect, false);
        dynamic_cast<QTextEdit*>(field)->setObjectName(name);
        dynamic_cast<QTextEdit*>(field)->setPlaceholderText(placeholder);
        dynamic_cast<QTextEdit*>(field)->setStyleSheet("#" + name + " {"
                                                        "max-height: 45px;"
                                                        "}");
        ui->formLayout->addRow(label, field);

    } else if (type == "Title") {

        field = new QLabel(label);
        dynamic_cast<QLabel*>(field)->setObjectName(name);
        dynamic_cast<QLabel*>(field)->setStyleSheet("#" + name + " {"
                                                        "text-transform: capitalize;"
                                                        "font-size: 16px;"
                                                        "font-weight: bold;"
                                                        "}");
        ui->formLayout->addRow(field);

    } else {

        return nullptr;

    }

    _fields[name] = field;
    _field_types[name] = type;
    return field;
}

QString FormDialog::val(QString name) {

    if (_field_types[name] == "QLineEdit") {
        QLineEdit* field = findChild<QLineEdit*>(name);
        QString text = field->text();
        field->clear();
        return text;
    } else if (_field_types[name] == "QTextEdit") {
        QTextEdit* field = findChild<QTextEdit*>(name);
        QString text = field->toPlainText();
        field->clear();
        return text;
    } else if (_field_types[name] == "QComboBox") {
        QComboBox* field = findChild<QComboBox*>(name);
        field->setCurrentIndex(0);
        return "";
    } else if (_field_types[name] == "QFileDialog") {
        return _data;
    } else if (_field_types[name] == "QCheckBox") {
        QCheckBox* field = findChild<QCheckBox*>(name);
        bool checked = field->isChecked();
        field->setChecked(false);
        return checked  ? "1" : "0";
    } else {
        return QString();
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

void FormDialog::select_folder() {
    _data = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                              "",
                                              QFileDialog::ShowDirsOnly
                                              | QFileDialog::DontResolveSymlinks);
}

void FormDialog::disableSubmit() {
    ui->ok_btn->setEnabled(false);
}

void FormDialog::enableSubmit() {
    ui->ok_btn->setEnabled(true);
}

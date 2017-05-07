#include "preferences.h"
#include "ui_preferences.h"

Preferences::Preferences(QWidget *parent, Controller * controller) :
    QDialog(parent, Qt::Sheet),
    _controller(controller),
    ui(new Ui::Preferences)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_StyledBackground, true);
    QWidget::setWindowModality(Qt::WindowModal);
    _controller = controller;
    ui->repo_pwd->setText(_controller->settings.value("general/repo_pwd").toString());
    ui->repo_url->setText(_controller->settings.value("general/repo_url").toString());
    ui->theme->setCurrentText(_controller->settings.value("general/theme").toString());
    ui->font_size->setValue(_controller->settings.value("general/font_size").toInt());
}

Preferences::~Preferences()
{
    delete ui;
}

void Preferences::on_save_btn_clicked()
{
    _controller->settings.setValue("general/repo_pwd", ui->repo_pwd->text());
    _controller->settings.setValue("general/repo_url", ui->repo_url->text());
    _controller->settings.setValue("general/theme", ui->theme->currentText());
    _controller->settings.setValue("general/font_size", ui->font_size->value());
    hide();
}

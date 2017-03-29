#include "card.h"
#include "ui_card.h"


Card::Card(QString title, QString info, QString color, void* obj) :
    QWidget(0),
    ui(new Ui::Card)
{
    ui->setupUi(this);
    ui->title->setText(title);
    ui->info->setText(info);
    ui->logo->setStyleSheet("background: " + color + ";");
    ui->logo->setText(title.left(2).toUpper());
    _obj = obj;
}

Card::~Card()
{
    delete ui;
}

void Card::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        emit clicked(_obj);
    }
}

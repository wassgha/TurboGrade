#include "card.h"
#include "ui_card.h"


Card::Card(QString title, QString info, QString color, QObject* obj, bool initials) :
    QWidget(0),
    ui(new Ui::Card)
{
    setCursor(Qt::PointingHandCursor);
    ui->setupUi(this);
    ui->title->setText(title);
    ui->info->setText(info);
    ui->logo->setStyleSheet("background: " + color + ";");
    if (initials && title.split(" ").count() > 1) {
        ui->logo->setText(title.split(" ").at(0).left(1).toUpper() + title.split(" ").at(1).left(1).toUpper());
    } else {
        ui->logo->setText(title.left(2).toUpper());
    }
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

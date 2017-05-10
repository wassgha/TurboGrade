#include "card.h"
#include "ui_card.h"


Card::Card(QString title, QString info, QString color, QObject* obj, bool initials, bool disabled) :
    QWidget(0),
    ui(new Ui::Card),
    _disabled(disabled)
{
    setCursor(Qt::PointingHandCursor);
    ui->setupUi(this);
    if (_disabled) {
        setCursor(Qt::ArrowCursor);
        QGraphicsOpacityEffect * op = new QGraphicsOpacityEffect();
        op->setOpacity(0.5);
        setGraphicsEffect(op);
        setAutoFillBackground(true);
    }
    ui->title->setText(title);
    ui->info->setText(info);
    ui->logo->setStyleSheet("background: " + color + ";");
    if (initials && title.split(" ").count() > 1) {
        ui->logo->setText(title.split(" ").at(0).left(1).toUpper() + title.split(" ").at(1).left(1).toUpper());
    } else {
        ui->logo->setText(title.left(2).toUpper());
    }
    _obj = obj;
    connect(ui->remove, SIGNAL(clicked()), this, SLOT(emit_deleted()));
}

Card::~Card()
{
    delete ui;
}

void Card::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && !_disabled) {
        emit clicked(_obj);
    }
}

void Card::emit_deleted() {
    emit deleted(_obj);
}

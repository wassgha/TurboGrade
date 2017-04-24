#include "fireworks.h"

Fireworks::Fireworks(QWidget *parent) :
    QFrame(parent, Qt::FramelessWindowHint),
    _parent(parent)
{

    QMovie *animation = new QMovie(":/misc/res/fireworks_1.gif");
    animation->setObjectName("animation");
    animation->setScaledSize(QSize(400, 300));
    animation->start();

    QLabel *gif = new QLabel(this);
    gif->setMovie(animation);
    gif->setObjectName("gif");
    gif->setAlignment(Qt::AlignCenter);
    gif->move(0,0);
    gif->resize(400, 300);
    gif->setStyleSheet("#gif { background:rgb(99, 187, 169); border-radius: 4px; padding: 10px;}");

    resize(gif->width() + 20 , gif->height() + 20);

    QFont helvetica("Helvetica", 40);
    helvetica.setBold(true);
    QFontMetrics fm(helvetica);
    QLabel *text = new QLabel(this);
    text->setText("Done Grading!");
    text->setObjectName("done");
    text->setAlignment(Qt::AlignCenter);
    text->setFont(helvetica);
    text->setStyleSheet("#done { color: white;}");
    text->move(width() / 2 - fm.width(text->text()) / 2, height() / 2 - 3 * fm.height()  / 4);

    setObjectName("fireworks");
    setStyleSheet("background: transparent;");
    this->setAttribute(Qt::WA_TranslucentBackground);
    update();
}

void Fireworks::update() {
    move(_parent->width() / 2 - width() / 2, _parent->height() / 2 - height() / 2);
}


Fireworks::~Fireworks() {

}

#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <QWidget>
#include <QMouseEvent>
#include <QGraphicsOpacityEffect>

namespace Ui {
class Card;
}

class Card : public QWidget
{
    Q_OBJECT

public:
    explicit Card(QString title, QString info, QString color, QObject* obj, bool initials = false, bool disabled = false);
    ~Card();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::Card *ui;
    QObject* _obj;
    bool _disabled = false;

signals:
    void clicked(QObject* obj);
};

#endif // CARD_H

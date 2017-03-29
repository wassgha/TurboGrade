#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <QWidget>
#include <QMouseEvent>

namespace Ui {
class Card;
}

class Card : public QWidget
{
    Q_OBJECT

public:
    explicit Card(QString title, QString info, QString color, void* obj);
    ~Card();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::Card *ui;
    void* _obj;

signals:
    void clicked(void* obj);
};

#endif // CARD_H

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
    explicit Card(QString title, QString info, QString color);
    ~Card();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::Card *ui;

signals:
    void clicked();
};

#endif // CARD_H

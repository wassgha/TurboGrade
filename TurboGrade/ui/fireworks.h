#ifndef FIREWORKS_H
#define FIREWORKS_H

#include <QMovie>
#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class Fireworks : public QFrame
{
    Q_OBJECT
public:
    explicit Fireworks(QWidget *parent = 0);
    ~Fireworks();
    void update();
    QWidget* _parent = nullptr;
};

#endif // FIREWORKS_H

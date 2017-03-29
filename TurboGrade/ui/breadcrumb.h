#ifndef BREADCRUMB_H
#define BREADCRUMB_H

#include <QWidget>
#include <QSignalMapper>

#include "ui_breadcrumb.h"
#include "clickablelabel.h"

namespace Ui {
class Breadcrumb;
}

class Breadcrumb : public QWidget
{
    Q_OBJECT

public:
    explicit Breadcrumb(QWidget *parent = 0);
    ~Breadcrumb();
    void add_item(const QString text, const char* slot, QObject* arg);
    void add_home();

private:
    Ui::Breadcrumb *ui;
    std::vector<QLabel*> items;
    QWidget* _parent;
};

#endif // BREADCRUMB_H

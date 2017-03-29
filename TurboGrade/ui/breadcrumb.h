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
    void add_item(const QString text, const char* slot, void* arg);
    void add_home();

private:
    Ui::Breadcrumb *ui;
    std::vector<QLabel*> items;
};

#endif // BREADCRUMB_H

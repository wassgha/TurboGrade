#ifndef BREADCRUMB_H
#define BREADCRUMB_H

#include <QWidget>

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
    void add_item(const QString text, const QObject *context, const char* slot);

private:
    Ui::Breadcrumb *ui;
};

#endif // BREADCRUMB_H

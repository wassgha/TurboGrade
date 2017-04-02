#ifndef BREADCRUMB_H
#define BREADCRUMB_H

#include <QWidget>
#include <QSignalMapper>

#include "switcher.h"

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
    void add_item(const QString text, const char* slot, QObject* arg, QObject* slot_holder = nullptr);
    void add_home();
    void add_switcher(QString left, QString right, bool default_state);

private:
    Ui::Breadcrumb *ui;
    std::vector<QLabel*> items;
    QWidget* _parent;

signals:
    void switcher_toggled();
};

#endif // BREADCRUMB_H

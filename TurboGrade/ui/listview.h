#ifndef LISTVIEW_H
#define LISTVIEW_H

#include <vector>
#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>

#include "breadcrumb.h"

#include "adddialog.h"
#include "ui_adddialog.h"

#include "card.h"
#include "ui_card.h"

namespace Ui {
class ListView;
}

class ListView : public QWidget
{
    Q_OBJECT

public:
    explicit ListView(QWidget *parent = 0);
    ~ListView();
    void add_card(QWidget *course);
    void remove_cards();

protected:
    Ui::ListView *ui;
    int max_col = 3;
    int cur_col = 0;
    int cur_row = 0;
    std::vector<Card*> cards;
    QPushButton *add_btn;
    AddDialog *add_dialog;
    Breadcrumb* _breadcrumb = nullptr;
    QWidget* _parent = nullptr;

public slots:
    virtual void new_course();
    virtual void refresh_cards();
    virtual void save_new();
};

#endif // LISTVIEW_H

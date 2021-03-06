#ifndef CARDSVIEW_H
#define CARDSVIEW_H

#include <vector>
#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>

#include "breadcrumb.h"

#include "formdialog.h"
#include "ui_formdialog.h"

#include "card.h"
#include "ui_card.h"

namespace Ui {
class CardsView;
}

class CardsView : public QWidget
{
    Q_OBJECT

public:
    explicit CardsView(QWidget *parent = 0);
    ~CardsView();
    void add_card(QWidget *course);
    void remove_cards();

protected:
    Ui::CardsView *ui;
    int max_col = 3;
    int cur_col = 0;
    int cur_row = 0;
    std::vector<Card*> cards;
    QPushButton *add_btn;
    FormDialog *add_dialog = nullptr;
    Breadcrumb* _breadcrumb = nullptr;
    QWidget* _parent = nullptr;

public slots:
    virtual void open_add_dialog();
    virtual void refresh_cards();
    virtual void save_new();
    void resizeEvent(QResizeEvent* event);
};

#endif // CARDSVIEW_H

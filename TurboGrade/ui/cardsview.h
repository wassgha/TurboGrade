#ifndef CARDSVIEW_H
#define CARDSVIEW_H

#include <vector>
#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QLabel>

#include "../engine/controller.h"
#include "../engine/controller.h"

#include "dashboard.h"
#include "ui_dashboard.h"

#include "adddialog.h"
#include "ui_newcourse.h"

#include "card.h"
#include "ui_card.h"

namespace Ui {
class CardsView;
}

class CardsView : public QWidget
{
    Q_OBJECT

public:
    explicit CardsView(QWidget *parent = 0, Controller* controller = nullptr);
    ~CardsView();
    void add_card(QWidget *course);
    void remove_cards();
    Controller *_controller;

private:
    Ui::CardsView *ui;
    QPushButton *add_btn;
    AddDialog *add_dialog;
    int max_col = 3;
    int cur_col = 0;
    int cur_row = 0;
    std::vector<Card*> courses;

public slots:
    void new_course();
    void refresh_cards();
    void open_editor();
};

#endif // CARDSVIEW_H

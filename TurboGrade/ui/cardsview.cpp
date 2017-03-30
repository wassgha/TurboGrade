#include "cardsview.h"
#include "ui_cardsview.h"

CardsView::CardsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CardsView)
{
    ui->setupUi(this);
    _parent = parent;
    _breadcrumb = new Breadcrumb(parent);

    setAttribute(Qt::WA_StyledBackground, true);

}

CardsView::~CardsView()
{
    for (Card* card: cards) {
        delete card;
    }
    delete ui;
    if (_breadcrumb != nullptr)
        delete _breadcrumb;
}

void CardsView::add_card(QWidget *card) {
    if (cur_col >= max_col) {
        cur_col = 0;
        cur_row++;
    }
    QGridLayout *grid =  (QGridLayout*) ui->scrollAreaWidgetContents->layout();
    grid->addWidget(card, cur_row, cur_col);
    cur_col++;
}

void CardsView::refresh_cards() {

}

void CardsView::save_new() {

}

void CardsView::remove_cards() {
    QGridLayout *grid =  (QGridLayout*) ui->scrollAreaWidgetContents->layout();
    grid->removeWidget(add_btn);
    for (Card* card: cards) {
        grid->removeWidget(card);
        delete card;
    }
    cards.clear();
    cur_col = 0;
    cur_row = 0;
}

void CardsView::new_course() {
    add_dialog->show();
}

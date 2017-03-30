#include "listview.h"
#include "ui_listview.h"

ListView::ListView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ListView)
{
    ui->setupUi(this);

    ui->scrollAreaWidgetContents->layout()->setAlignment(Qt::AlignTop);

    _parent = parent;
    _breadcrumb = new Breadcrumb(parent);

    setAttribute(Qt::WA_StyledBackground, true);

}

ListView::~ListView()
{
    for (Card* card: cards) {
        delete card;
    }
    delete ui;
    if (_breadcrumb != nullptr)
        delete _breadcrumb;
}

void ListView::add_card(QWidget *card) {
    if (cur_col >= max_col) {
        cur_col = 0;
        cur_row++;
    }
    QVBoxLayout *box =  (QVBoxLayout*) ui->scrollAreaWidgetContents->layout();
    box->addWidget(card);
    cur_col++;
}

void ListView::refresh_cards() {

}

void ListView::save_new() {

}

void ListView::remove_cards() {
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

void ListView::new_course() {
    add_dialog->show();
}

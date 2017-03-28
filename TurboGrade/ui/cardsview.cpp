#include "cardsview.h"
#include "ui_cardsview.h"

CardsView::CardsView(QWidget *parent, Controller *controller) :
    QWidget(parent),
    ui(new Ui::CardsView)
{
    ui->setupUi(this);

    setAttribute(Qt::WA_StyledBackground, true);

    _controller = controller;

    add_dialog = new AddDialog(this, _controller);
    connect(add_dialog, SIGNAL(submit()), this, SLOT(refresh_cards()));

    add_btn = new QPushButton("Add course");
    add_btn->setCursor(Qt::PointingHandCursor);
    add_btn->setObjectName("add_course");
    connect(add_btn, SIGNAL(clicked(bool)), this, SLOT(new_course()));

    refresh_cards();
}

CardsView::~CardsView()
{
    for (Card* course: courses) {
        delete course;
    }
    delete ui;
}

void CardsView::refresh_cards() {

    remove_cards();

    add_card(add_btn);
    for(Course* course : *_controller->get_courses()) {
        Card* new_course = new Card(course->_name, "2 sections", course->_color);
        courses.push_back(new_course);
        connect(new_course, SIGNAL(clicked()), this, SLOT(open_editor()));
        add_card(new_course);
    }

}

void CardsView::add_card(QWidget *course) {
    if (cur_col >= max_col) {
        cur_col = 0;
        cur_row++;
    }
    QGridLayout *grid =  (QGridLayout*) ui->scrollAreaWidgetContents->layout();
    grid->addWidget(course, cur_row, cur_col);
    cur_col++;
}

void CardsView::remove_cards() {
    QGridLayout *grid =  (QGridLayout*) ui->scrollAreaWidgetContents->layout();
    grid->removeWidget(add_btn);
    for (Card* course: courses) {
        grid->removeWidget(course);
        delete course;
    }
    courses.clear();
    cur_col = 0;
    cur_row = 0;
}

void CardsView::new_course() {
    add_dialog->show();
}

void CardsView::open_editor() {
    ((Dashboard *)parent()->parent())->grade_submission->show();
}

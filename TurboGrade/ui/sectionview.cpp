#include "sectionview.h"

SectionView::SectionView(QWidget* parent, QObject* course, Controller* controller):
    CardsView(parent)
{

    _controller = controller;
    _course = (Course*)course;
    add_dialog = new FormDialog(this, "New Section");
    add_dialog->add_field("QLineEdit",
                          "name",
                           _course->_name + "  .",
                          "01");
    connect(add_dialog, SIGNAL(submit()), this, SLOT(save_new()));

    add_btn = new QPushButton("Add section");
    add_btn->setCursor(Qt::PointingHandCursor);
    add_btn->setObjectName("add_btn");
    connect(add_btn, SIGNAL(clicked(bool)), this, SLOT(open_add_dialog()));

    _breadcrumb->add_item(_course->_name, SLOT(show_sections(QObject *)), _course);
    ui->verticalLayout->insertWidget(0, _breadcrumb);
    refresh_cards();
}

void SectionView::refresh_cards() {

    remove_cards();

    add_card(add_btn);
    for(Section* section : *_course->get_sections()) {
        Card* new_section = new Card(section->_course->_name + "." + section->_name,
                                     QString::number(section->_students->size()) + " student(s) \n"
                                     + QString::number(section->_assignments->size()) + " assignment(s)",
                                     section->_color, section);
        cards.push_back(new_section);
        connect(new_section, SIGNAL(clicked(QObject *)), _parent, SLOT(show_assignments(QObject *)));
        connect(new_section, SIGNAL(deleted(QObject*)), this, SLOT(delete_section(QObject*)));
        add_card(new_section);
    }

}

void SectionView::save_new() {
    _course->add_section(add_dialog->val("name"));
    refresh_cards();
}


void SectionView::delete_section(QObject* section) {
    _course->remove_section(dynamic_cast<Section*>(section));
    refresh_cards();
}


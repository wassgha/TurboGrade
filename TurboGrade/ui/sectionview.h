#ifndef SECTIONVIEW_H
#define SECTIONVIEW_H

#include "clickablelabel.h"

#include "cardsview.h"
#include "ui_cardsview.h"

class CardsView;

class SectionView: public CardsView
{
public:
    SectionView(QWidget* parent = 0, QObject* course = nullptr, Controller* controller = nullptr):
        CardsView(parent)
    {

        _controller = controller;
        _course = (Course*)course;
        add_dialog = new AddDialog(this, "section", _controller);
        connect(add_dialog, SIGNAL(submit()), this, SLOT(save_new()));

        add_btn = new QPushButton("Add section");
        add_btn->setCursor(Qt::PointingHandCursor);
        add_btn->setObjectName("add_btn");
        connect(add_btn, SIGNAL(clicked(bool)), this, SLOT(new_course()));

        _breadcrumb = new Breadcrumb(parent);
        _breadcrumb->add_item(_course->_name, SLOT(show_sections(QObject *)), _course);
        ui->verticalLayout->insertWidget(0, _breadcrumb);
        refresh_cards();
    }

    ~SectionView() {
        delete _breadcrumb;
    }

public slots:
    void refresh_cards() override {

        remove_cards();

        add_card(add_btn);
        for(Section* section : *_course->get_sections()) {
            Card* new_section = new Card(section->_course->_name + "." + section->_name,
                                         QString::number(section->_assignments->size()) + " assignment(s)",
                                         section->_color, section);
            cards.push_back(new_section);
            connect(new_section, SIGNAL(clicked(QObject *)), parent(), SLOT(show_assignments(QObject *)));
            add_card(new_section);
        }

    }

    void save_new() override {
        _course->add_section(-1, add_dialog->ui->name->text());
        add_dialog->ui->name->clear();
        refresh_cards();
    }

private:
    Controller *_controller;
    Course* _course;

};

#endif // SECTIONVIEW_H

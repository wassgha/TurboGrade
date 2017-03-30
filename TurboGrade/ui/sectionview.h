#ifndef SECTIONVIEW_H
#define SECTIONVIEW_H

#include "clickablelabel.h"

#include "cardsview.h"
#include "ui_cardsview.h"

class CardsView;

class SectionView: public CardsView
{
public:
    SectionView(QWidget* parent = 0, QObject* course = nullptr, Controller* controller = nullptr);

public slots:
    void refresh_cards() override;

    void save_new() override;

private:
    Controller *_controller;
    Course* _course;

};

#endif // SECTIONVIEW_H
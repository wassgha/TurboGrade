#ifndef COURSEVIEW_H
#define COURSEVIEW_H

#include "cardsview.h"
#include "ui_cardsview.h"

class CardsView;

class CourseView: public CardsView
{
public:
    CourseView(QWidget* parent = 0, Controller* controller = nullptr);

public slots:
    void refresh_cards() override;
    void save_new() override;

private:
    Controller *_controller;

};

#endif // COURSEVIEW_H

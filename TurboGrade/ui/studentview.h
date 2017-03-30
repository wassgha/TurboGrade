#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include "listview.h"
#include "ui_listview.h"

class StudentView;

class StudentView: public ListView
{
public:
    StudentView(QWidget* parent = 0, Controller* controller = nullptr);

public slots:
    void refresh_cards() override;
    void save_new() override;

private:
    Controller *_controller;

};

#endif // STUDENTVIEW_H

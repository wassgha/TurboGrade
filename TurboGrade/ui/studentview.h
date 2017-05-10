#ifndef STUDENTVIEW_H
#define STUDENTVIEW_H

#include "listview.h"
#include "ui_listview.h"

#include "dashboard.h"

class StudentView;

class StudentView: public ListView
{
    Q_OBJECT
public:
    StudentView(QWidget* parent = 0, QObject* section = nullptr, Controller* controller = nullptr);

public slots:
    void refresh_cards() override;
    void save_new() override;
    void show_assignments();
    void delete_student(QObject* student);

private:
    Controller *_controller;
    Section* _section;

};

#endif // STUDENTVIEW_H

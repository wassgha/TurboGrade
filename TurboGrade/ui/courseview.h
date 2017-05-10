#ifndef COURSEVIEW_H
#define COURSEVIEW_H

#include "cardsview.h"
#include "ui_cardsview.h"

class CardsView;

class CourseView: public CardsView
{
    Q_OBJECT
public:
    CourseView(QWidget* parent = 0, Controller* controller = nullptr);

public slots:
    void refresh_cards() override;
    void save_new() override;
    void delete_course(QObject* course);

private:
    Controller* _controller;
    QComboBox* _semester_select;
    QComboBox* _semester_switch;
    QStringListModel *_semesters_model = nullptr;


};

#endif // COURSEVIEW_H

#ifndef SUBMISSIONVIEW_H
#define SUBMISSIONVIEW_H

#include "listview.h"
#include "ui_listview.h"

#include "dashboard.h"

class SubmissionView;

class SubmissionView: public ListView
{
    Q_OBJECT
public:
    SubmissionView(QWidget* parent = 0, QObject* section = nullptr, QObject* assignment = nullptr, Controller* controller = nullptr);

public slots:
    void refresh_cards() override;
    void save_new() override;
    void show_assignments();
    void show_submissions(QObject* assignment);

private:
    Controller *_controller;
    Section* _section;
    Assignment* _assignment;

};

#endif // SUBMISSIONVIEW_H

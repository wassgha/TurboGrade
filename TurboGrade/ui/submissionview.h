#ifndef SUBMISSIONVIEW_H
#define SUBMISSIONVIEW_H

#include "listview.h"
#include "ui_listview.h"

#include "dashboard.h"
#include "../tools/dirtools.h"
#include "../tools/csvgenerator.h"

class SubmissionView;

class SubmissionView: public ListView
{
    Q_OBJECT
public:
    SubmissionView(QWidget* parent = 0, QObject* section = nullptr, QObject* assignment = nullptr, Controller* controller = nullptr);

public slots:
    void refresh_cards() override;
    void show_assignments();
    void show_submissions(QObject* assignment);
    void import_submission();
    void export_csv();

private:
    Controller *_controller;
    Section* _section;
    Assignment* _assignment;
    QPushButton *export_btn = nullptr;

};

#endif // SUBMISSIONVIEW_H

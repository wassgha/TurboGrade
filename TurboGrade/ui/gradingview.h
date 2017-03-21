#ifndef GRADINGVIEW_H
#define GRADINGVIEW_H

#include "mainwindow.h"
#include "../tools/codeeditor.h"
#include "commentpopup.h"
#include "ui_commentpopup.h"
#include "gradeoverview.h"
#include "ui_gradeoverview.h"

#include <QMainWindow>
#include <QWidget>
#include <QModelIndex>
#include <QFileSystemModel>
#include <QProcess>
#include <iostream>


namespace Ui {
class GradingView;
}

class GradingView : public QWidget
{
    Q_OBJECT

public:
    explicit GradingView(QWidget *parent = 0);
    ~GradingView();

public slots:
    void getSelection();
    void loadFile(QModelIndex item);

private slots:
    void on_run_clicked();

    void on_overview_clicked();

private:
    Ui::GradingView *ui;
    void setupEditor(const QString &file_name);

    CommentPopup* popup = new CommentPopup(this);
    QFileSystemModel *model;
};

#endif // GRADINGVIEW_H

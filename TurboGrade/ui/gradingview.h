#ifndef GRADINGVIEW_H
#define GRADINGVIEW_H

#include "../tools/codeeditor.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
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
    explicit GradingView(QWidget *parent);
    ~GradingView();
    Ui::GradingView *ui;

public slots:
    void getSelection();
    void loadFile(QModelIndex item);

private slots:
    void on_run_clicked();

    void on_overview_clicked();

private:
    void setupEditor(const QString &file_name);

    CommentPopup* popup = new CommentPopup(this);
    QFileSystemModel *model;

signals:
    void toggle();
};

#endif // GRADINGVIEW_H

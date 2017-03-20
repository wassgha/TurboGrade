#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../tools/codeeditor.h"
#include "commentpopup.h"
#include "ui_commentpopup.h"
#include "gradeoverview.h"
#include "ui_gradeoverview.h"

#include <QMainWindow>
#include <QModelIndex>
#include <QFileSystemModel>
#include <iostream>

QT_BEGIN_NAMESPACE
class QTextEdit;
class QLabel;
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void getSelection();
    void loadFile(QModelIndex item);

private slots:
    void on_run_clicked();

    void on_overview_clicked();

private:
    Ui::MainWindow *ui;
    void setupEditor(const QString &file_name);

    CommentPopup* popup = new CommentPopup(this);
    QFileSystemModel *model;
};

#endif // MAINWINDOW_H

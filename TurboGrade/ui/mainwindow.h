#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../tools/codeeditor.h"
#include "commentpopup.h"
#include "ui_commentpopup.h"

#include <QMainWindow>
#include <QModelIndex>
#include <QFileSystemModel>

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

private:
    Ui::MainWindow *ui;
    void setupEditor(const QString &file_name);

    CommentPopup* popup = new CommentPopup(this);
    QFileSystemModel *model;
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../tools/syntaxhighlight.h"
#include "../tools/codeeditor.h"

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
    void about();
    void newFile();
    void openFile(const QString &path = QString());
    void getSelection();
    void loadFile(QModelIndex item);
    void openDir(const QString &path = QString());

private:
    Ui::MainWindow *ui;
    void setupEditor(const QString &file_name);
    void setupFileMenu();
    void setupHelpMenu();

    CodeEditor *editor;
    SyntaxHighlighter *highlighter;
    QWidget* popup = nullptr;
    QLabel* pos = nullptr;
    QFileSystemModel *model;
};

#endif // MAINWINDOW_H

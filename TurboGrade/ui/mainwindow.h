#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../tools/syntaxhighlight.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QTextEdit;
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

private:
    Ui::MainWindow *ui;
    void setupEditor(const QString &file_name);
    void setupFileMenu();
    void setupHelpMenu();

    QTextEdit *editor;
    SyntaxHighlighter *highlighter;
};

#endif // MAINWINDOW_H

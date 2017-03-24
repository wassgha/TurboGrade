#ifndef CODEVIEW_H
#define CODEVIEW_H

#include "../tools/codeeditor.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commentpopup.h"
#include "ui_commentpopup.h"
#include "gradeview.h"
#include "ui_gradeoverview.h"

#include <QMainWindow>
#include <QWidget>
#include <QModelIndex>
#include <QFileSystemModel>
#include <QProcess>
#include <iostream>


namespace Ui {
class CodeView;
}

class CodeView : public QWidget
{
    Q_OBJECT

public:
    explicit CodeView(QWidget *parent);
    ~CodeView();
    Ui::CodeView *ui;

public slots:
    void getSelection();
    void loadFile(QModelIndex item);

private:
    void setupCodeEditor(const QString &file_name);

    CommentPopup *_popup = new CommentPopup(this);
    QFileSystemModel *_model;

};

#endif // CODEVIEW_H
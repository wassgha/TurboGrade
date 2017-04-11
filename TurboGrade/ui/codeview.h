#ifndef CODEVIEW_H
#define CODEVIEW_H

#include "../engine/controller.h"
#include "../engine/controller.h"

#include "../tools/codeeditor.h"

#include "dashboard.h"
#include "ui_dashboard.h"

#include "gradesubmission.h"
#include "ui_gradesubmission.h"

#include "commentpopup.h"
#include "ui_commentpopup.h"

#include "commentcard.h"
#include "ui_commentcard.h"

#include "gradeview.h"
#include "ui_gradeview.h"

#include <QMainWindow>
#include <QDesktopWidget>
#include <QWidget>
#include <QEvent>
#include <QMoveEvent>
#include <QModelIndex>
#include <QFileSystemModel>
#include <QProcess>
#include <QCompleter>
#include <iostream>
#include <QCloseEvent>

class GradeSubmission;

namespace Ui {
    class CodeView;
}

class CodeView : public QWidget
{
    Q_OBJECT

public:
    explicit CodeView(QWidget *parent, Controller* controller = nullptr);
    ~CodeView();
    QString current_folder();
    QString current_file();
    Ui::CodeView                *ui;
    Controller                  *_controller;
    GradeSubmission             *_parent;
    std::vector<CommentCard*>   _comment_cards;

public slots:
    void getSelection();
    void loadFile(QModelIndex item);
    void expandToDepth(QString file);
    void add_comment();
    void highlight_comment(Comment * comment);
    void unhighlight_comment(Comment * comment);

private:
    void refresh_criteria();
    void setupCodeEditor(const QString &file_name);
    bool eventFilter(QObject *obj, QEvent *event) override;
    void refresh_comments();
    void refresh_autocomplete();
    void move_popup();

    CommentPopup        *_popup;
    QFileSystemModel    *_model;
    QCompleter          *_completer;

};

#endif // CODEVIEW_H

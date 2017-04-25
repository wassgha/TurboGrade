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
#include <QStandardItemModel>
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
class CommentCard;

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
    void move_popup();
    void show_comment(Comment * comment);
    void refresh_criteria();
    void refresh_comments();
    void refresh_autocomplete();
    Ui::CodeView                *ui;
    Controller                  *_controller;
    GradeSubmission             *_parent;
    std::vector<CommentCard*>   _comment_cards;
    CommentPopup                *_popup;

public slots:
    void getSelection();
    void loadFile(QModelIndex item);
    void finished_loading();
    void add_comment();
    void highlight_comment(Comment * comment);
    void unhighlight_comments();
    void auto_completed(QModelIndex index);

private:
    void setupCodeEditor(const QString &file_name);
    bool eventFilter(QObject *obj, QEvent *event) override;

    QFileSystemModel    *_model;
    QCompleter          *_completer = nullptr;
    QString             _root_path;
    QModelIndex         root_index;
    QString             first_file;
    QModelIndex         first_file_index;

};

#endif // CODEVIEW_H

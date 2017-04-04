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
#include <QWidget>
#include <QEvent>
#include <QMoveEvent>
#include <QModelIndex>
#include <QFileSystemModel>
#include <QProcess>
#include <iostream>

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
    Ui::CodeView *ui;
    Controller *_controller;
    GradeSubmission *_parent;
    std::vector<CommentCard*> _comment_cards;

public slots:
    void getSelection();
    void loadFile(QModelIndex item);
    void expandToDepth(QString file);
    void add_comment();

private:
    void refresh_criteria();
    void setupCodeEditor(const QString &file_name);
    bool eventFilter(QObject *obj, QEvent *event);
    void refresh_comments();

    CommentPopup *_popup = new CommentPopup(this);
    QFileSystemModel *_model;

};

#endif // CODEVIEW_H

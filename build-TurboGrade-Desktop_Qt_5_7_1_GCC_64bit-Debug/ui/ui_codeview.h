/********************************************************************************
** Form generated from reading UI file 'codeview.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODEVIEW_H
#define UI_CODEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../tools/codeeditor.h"
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_CodeView
{
public:
    QGridLayout *gridLayout;
    QSplitter *splitter_3;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QTreeView *treeView;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *grade_view;
    CodeEditor *editor;
    QScrollArea *comments;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *comment_layout;
    QWidget *general_comments_box;
    QVBoxLayout *verticalLayout;
    QLabel *general_comments_label;
    QPlainTextEdit *general_comments;
    ClickableLabel *save_general_comment;
    QLabel *comments_title;
    QTextEdit *terminal;

    void setupUi(QWidget *CodeView)
    {
        if (CodeView->objectName().isEmpty())
            CodeView->setObjectName(QStringLiteral("CodeView"));
        CodeView->resize(799, 490);
        CodeView->setAutoFillBackground(false);
        CodeView->setStyleSheet(QLatin1String("QWidget#CodeView {\n"
"	background: #232730;\n"
"}\n"
"\n"
"#comments #scrollAreaWidgetContents {\n"
"	background: transparent;\n"
"}\n"
"\n"
"QTreeView#treeView {\n"
"        /* background: rgb(66, 76, 96); */\n"
"		/* background: #535663; */\n"
"		background: transparent;\n"
"        border: none;\n"
"        color: white;\n"
"        padding-top: 10px;\n"
"        /* border-radius: 3px; */\n"
"    	   show-decoration-selected: 1;\n"
"	   width: 360px;\n"
"}\n"
"\n"
"QTreeView::item {\n"
"	color: #aab0bc;\n"
"}\n"
"\n"
"QTreeView::branch:selected,\n"
"QTreeView::item:selected,\n"
"QTreeView::item:selected:active,\n"
"QTreeView::item:selected:!active {\n"
"	background: #2b2f3b;\n"
"	color: white;\n"
"}\n"
"\n"
"QSplitter::handle:horizontal {\n"
"        image: url(:/misc/res/splitter.png);\n"
"}\n"
"\n"
"QSplitter::handle:vertical {\n"
"        image: url(:/misc/res/splitter2.png);\n"
"}\n"
"\n"
"QScrollArea#comments {\n"
"	border: none;\n"
"	background: url(:/misc/res/comment.png);\n"
"	background-repeat: no"
                        "ne;\n"
"	background-position: center center;\n"
"}\n"
"\n"
"#comments_title {\n"
"	color:white;\n"
"	text-transform: uppercase;\n"
"	font-weight: bold;\n"
"}\n"
"QScrollArea#comments > #scrollAreaWidgetContents {\n"
"	border: none;\n"
"	background: transparent;\n"
"}\n"
"\n"
"#terminal {\n"
"	background: rgba(0, 0, 0, 60);\n"
"	border-radius: 3px;\n"
"	color: white;\n"
"	padding: 10px;\n"
"	color: #EFEFEF;\n"
"	max-height: 100px;\n"
"}\n"
"\n"
"\n"
"\n"
"QWidget#general_comments_box {\n"
"	background: #ffea8d;\n"
"	border-radius: 3px;\n"
"}\n"
"#general_comments {\n"
"	background: transparent;\n"
"}\n"
"#general_comments_label {\n"
"	text-transform: uppercase;\n"
"	color: rgb(107, 100, 51);\n"
"	font-family: \"Montserrat\", sans-serif;\n"
"	font-weight: bold;\n"
"	font-weight: 400;\n"
"	padding: 0px;\n"
"} "));
        gridLayout = new QGridLayout(CodeView);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(8, 8, 8, 8);
        splitter_3 = new QSplitter(CodeView);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setOrientation(Qt::Vertical);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setMinimumSize(QSize(360, 0));
        splitter->setMaximumSize(QSize(360, 16777215));
        splitter->setOrientation(Qt::Vertical);
        treeView = new QTreeView(splitter);
        treeView->setObjectName(QStringLiteral("treeView"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy1);
        treeView->setMinimumSize(QSize(120, 0));
        treeView->setMaximumSize(QSize(360, 16777215));
        treeView->setBaseSize(QSize(0, 0));
        treeView->setAutoFillBackground(false);
        treeView->setHeaderHidden(true);
        splitter->addWidget(treeView);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        grade_view = new QVBoxLayout(verticalLayoutWidget);
        grade_view->setSpacing(6);
        grade_view->setContentsMargins(11, 11, 11, 11);
        grade_view->setObjectName(QStringLiteral("grade_view"));
        grade_view->setContentsMargins(0, 0, 8, 0);
        splitter->addWidget(verticalLayoutWidget);
        splitter_2->addWidget(splitter);
        editor = new CodeEditor(splitter_2);
        editor->setObjectName(QStringLiteral("editor"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(editor->sizePolicy().hasHeightForWidth());
        editor->setSizePolicy(sizePolicy2);
        editor->setContextMenuPolicy(Qt::NoContextMenu);
        splitter_2->addWidget(editor);
        comments = new QScrollArea(splitter_2);
        comments->setObjectName(QStringLiteral("comments"));
        comments->setMinimumSize(QSize(300, 0));
        comments->setMaximumSize(QSize(300, 16777215));
        comments->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        comments->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        comments->setWidgetResizable(true);
        comments->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(8, 0, 284, 346));
        scrollAreaWidgetContents->setMinimumSize(QSize(0, 0));
        scrollAreaWidgetContents->setMaximumSize(QSize(16777215, 16777215));
        comment_layout = new QVBoxLayout(scrollAreaWidgetContents);
        comment_layout->setSpacing(12);
        comment_layout->setContentsMargins(11, 11, 11, 11);
        comment_layout->setObjectName(QStringLiteral("comment_layout"));
        comment_layout->setContentsMargins(8, 0, 0, 0);
        general_comments_box = new QWidget(scrollAreaWidgetContents);
        general_comments_box->setObjectName(QStringLiteral("general_comments_box"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(general_comments_box->sizePolicy().hasHeightForWidth());
        general_comments_box->setSizePolicy(sizePolicy3);
        general_comments_box->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(general_comments_box);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        general_comments_label = new QLabel(general_comments_box);
        general_comments_label->setObjectName(QStringLiteral("general_comments_label"));
        sizePolicy3.setHeightForWidth(general_comments_label->sizePolicy().hasHeightForWidth());
        general_comments_label->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(general_comments_label);

        general_comments = new QPlainTextEdit(general_comments_box);
        general_comments->setObjectName(QStringLiteral("general_comments"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(general_comments->sizePolicy().hasHeightForWidth());
        general_comments->setSizePolicy(sizePolicy4);
        general_comments->setFrameShape(QFrame::NoFrame);
        general_comments->setFrameShadow(QFrame::Plain);
        general_comments->setLineWidth(1);
        general_comments->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        general_comments->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        general_comments->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        general_comments->setLineWrapMode(QPlainTextEdit::WidgetWidth);
        general_comments->setBackgroundVisible(false);
        general_comments->setCenterOnScroll(false);

        verticalLayout->addWidget(general_comments);

        save_general_comment = new ClickableLabel(general_comments_box);
        save_general_comment->setObjectName(QStringLiteral("save_general_comment"));
        save_general_comment->setEnabled(false);
        save_general_comment->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout->addWidget(save_general_comment);


        comment_layout->addWidget(general_comments_box);

        comments_title = new QLabel(scrollAreaWidgetContents);
        comments_title->setObjectName(QStringLiteral("comments_title"));
        sizePolicy3.setHeightForWidth(comments_title->sizePolicy().hasHeightForWidth());
        comments_title->setSizePolicy(sizePolicy3);

        comment_layout->addWidget(comments_title);

        comments->setWidget(scrollAreaWidgetContents);
        splitter_2->addWidget(comments);
        splitter_3->addWidget(splitter_2);
        terminal = new QTextEdit(splitter_3);
        terminal->setObjectName(QStringLiteral("terminal"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(terminal->sizePolicy().hasHeightForWidth());
        terminal->setSizePolicy(sizePolicy5);
        terminal->setMinimumSize(QSize(0, 100));
        terminal->setMaximumSize(QSize(16777215, 120));
        terminal->setBaseSize(QSize(0, 100));
        terminal->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        terminal->setReadOnly(true);
        splitter_3->addWidget(terminal);

        gridLayout->addWidget(splitter_3, 0, 0, 1, 1);


        retranslateUi(CodeView);

        QMetaObject::connectSlotsByName(CodeView);
    } // setupUi

    void retranslateUi(QWidget *CodeView)
    {
        CodeView->setWindowTitle(QApplication::translate("CodeView", "CodeView", Q_NULLPTR));
        general_comments_label->setText(QApplication::translate("CodeView", "GENERAL COMMENTS", Q_NULLPTR));
        general_comments->setPlainText(QString());
        general_comments->setPlaceholderText(QApplication::translate("CodeView", "Enter general comments ...", Q_NULLPTR));
        save_general_comment->setText(QApplication::translate("CodeView", "SAVED", Q_NULLPTR));
        comments_title->setText(QApplication::translate("CodeView", "Comments on this file", Q_NULLPTR));
        terminal->setHtml(QApplication::translate("CodeView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Terminal output:</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CodeView: public Ui_CodeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODEVIEW_H

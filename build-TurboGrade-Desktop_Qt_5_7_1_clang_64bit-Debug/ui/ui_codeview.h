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
#include <QtWidgets/QSplitter>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>
#include "../tools/codeeditor.h"

QT_BEGIN_NAMESPACE

class Ui_CodeView
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QTreeView *treeView;
    CodeEditor *editor;
    QToolBox *toolBox;
    QWidget *page_5;
    QWidget *page_6;

    void setupUi(QWidget *CodeView)
    {
        if (CodeView->objectName().isEmpty())
            CodeView->setObjectName(QStringLiteral("CodeView"));
        CodeView->resize(700, 478);
        CodeView->setStyleSheet(QLatin1String("#treeView {\n"
"        /* background: rgb(66, 76, 96); */\n"
"		background: #535663;\n"
"        border: none;\n"
"        color: white;\n"
"        padding-top: 10px;\n"
"        border-radius: 3px;\n"
"}\n"
"\n"
"QSplitter::handle:horizontal {\n"
"        image: url(:/misc/res/splitter.png);\n"
"}"));
        gridLayout_2 = new QGridLayout(CodeView);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter = new QSplitter(CodeView);
        splitter->setObjectName(QStringLiteral("splitter"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(splitter->sizePolicy().hasHeightForWidth());
        splitter->setSizePolicy(sizePolicy);
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(8);
        treeView = new QTreeView(splitter);
        treeView->setObjectName(QStringLiteral("treeView"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(treeView->sizePolicy().hasHeightForWidth());
        treeView->setSizePolicy(sizePolicy1);
        treeView->setMinimumSize(QSize(120, 0));
        treeView->setMaximumSize(QSize(250, 16777215));
        treeView->setBaseSize(QSize(0, 0));
        treeView->setAutoFillBackground(false);
        treeView->setHeaderHidden(true);
        splitter->addWidget(treeView);
        editor = new CodeEditor(splitter);
        editor->setObjectName(QStringLiteral("editor"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(editor->sizePolicy().hasHeightForWidth());
        editor->setSizePolicy(sizePolicy2);
        splitter->addWidget(editor);
        toolBox = new QToolBox(splitter);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        page_5 = new QWidget();
        page_5->setObjectName(QStringLiteral("page_5"));
        page_5->setGeometry(QRect(0, 0, 187, 408));
        toolBox->addItem(page_5, QStringLiteral("Page 1"));
        page_6 = new QWidget();
        page_6->setObjectName(QStringLiteral("page_6"));
        page_6->setGeometry(QRect(0, 0, 187, 408));
        toolBox->addItem(page_6, QStringLiteral("Page 2"));
        splitter->addWidget(toolBox);

        gridLayout->addWidget(splitter, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(CodeView);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(CodeView);
    } // setupUi

    void retranslateUi(QWidget *CodeView)
    {
        CodeView->setWindowTitle(QApplication::translate("CodeView", "CodeView", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_5), QApplication::translate("CodeView", "Page 1", Q_NULLPTR));
        toolBox->setItemText(toolBox->indexOf(page_6), QApplication::translate("CodeView", "Page 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CodeView: public Ui_CodeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODEVIEW_H

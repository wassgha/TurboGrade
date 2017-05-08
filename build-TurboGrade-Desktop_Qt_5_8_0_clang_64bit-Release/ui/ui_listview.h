/********************************************************************************
** Form generated from reading UI file 'listview.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LISTVIEW_H
#define UI_LISTVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ListView
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *ListView)
    {
        if (ListView->objectName().isEmpty())
            ListView->setObjectName(QStringLiteral("ListView"));
        ListView->resize(586, 252);
        ListView->setStyleSheet(QLatin1String("#ListView, #scrollArea {\n"
"        background: #f1f2f6;\n"
"        border: none;\n"
"}\n"
"\n"
"QAbstractScrollArea #scrollAreaWidgetContents  {\n"
" background-color:transparent;\n"
"        border: none;\n"
"}\n"
"\n"
"Card {\n"
"        height: 70px;\n"
"        max-height: 70px;\n"
"}\n"
"\n"
"#add_btn {\n"
"        height: 70px;\n"
"        max-height: 70px;\n"
"        background: transparent;\n"
"        padding : -3px;\n"
"        color: rgb(174, 176, 176);\n"
"        border: 3px dashed rgb(174, 176, 176);\n"
"        font-size: 18px;\n"
"}"));
        verticalLayout = new QVBoxLayout(ListView);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(ListView);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 586, 252));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(ListView);

        QMetaObject::connectSlotsByName(ListView);
    } // setupUi

    void retranslateUi(QWidget *ListView)
    {
        ListView->setWindowTitle(QApplication::translate("ListView", "Form", Q_NULLPTR));
#ifndef QT_NO_ACCESSIBILITY
        ListView->setAccessibleName(QString());
#endif // QT_NO_ACCESSIBILITY
    } // retranslateUi

};

namespace Ui {
    class ListView: public Ui_ListView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LISTVIEW_H

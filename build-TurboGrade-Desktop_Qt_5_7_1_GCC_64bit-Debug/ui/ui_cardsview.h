/********************************************************************************
** Form generated from reading UI file 'cardsview.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARDSVIEW_H
#define UI_CARDSVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CardsView
{
public:
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;

    void setupUi(QWidget *CardsView)
    {
        if (CardsView->objectName().isEmpty())
            CardsView->setObjectName(QStringLiteral("CardsView"));
        CardsView->resize(586, 252);
        CardsView->setStyleSheet(QLatin1String("#CardsView, #scrollArea {\n"
"	background: #f1f2f6;\n"
"	border: none;\n"
"}\n"
"\n"
"QAbstractScrollArea #scrollAreaWidgetContents  {\n"
" background-color:transparent;\n"
"	border: none;\n"
"}\n"
"\n"
"Card {\n"
"	height: 75px;\n"
"	width: 225px;\n"
"	max-width: 225px;\n"
"	max-height: 75px;\n"
"}\n"
"\n"
"#add_btn {\n"
"	height: 75px;\n"
"	width: 225px;\n"
"	max-width: 225px;\n"
"	max-height: 75px;\n"
"	background: transparent;\n"
"	padding : -3px;\n"
"	color: rgb(174, 176, 176);\n"
"	border: 3px dashed rgb(174, 176, 176);\n"
"	font-size: 18px;\n"
"}"));
        verticalLayout = new QVBoxLayout(CardsView);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(CardsView);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 586, 252));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(CardsView);

        QMetaObject::connectSlotsByName(CardsView);
    } // setupUi

    void retranslateUi(QWidget *CardsView)
    {
        CardsView->setWindowTitle(QApplication::translate("CardsView", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CardsView: public Ui_CardsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARDSVIEW_H

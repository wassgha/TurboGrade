/********************************************************************************
** Form generated from reading UI file 'courses.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COURSES_H
#define UI_COURSES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Courses
{
public:
    QGridLayout *gridLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_3;

    void setupUi(QWidget *Courses)
    {
        if (Courses->objectName().isEmpty())
            Courses->setObjectName(QStringLiteral("Courses"));
        Courses->resize(586, 252);
        Courses->setStyleSheet(QLatin1String("#Courses, #scrollArea {\n"
"	background: #f1f2f6;\n"
"	border: none;\n"
"}\n"
"\n"
"QAbstractScrollArea #scrollAreaWidgetContents  {\n"
" background-color:transparent;\n"
"	border: none;\n"
"}\n"
"\n"
"QPushButton {\n"
"	background: white;\n"
"	border: 1px solid lightgray;\n"
"	border-radius: 3px;\n"
"	height: 125px;\n"
"	width: 225px;\n"
"	max-width: 225px;\n"
"}\n"
"\n"
"#add_course {\n"
"	background: transparent;\n"
"	padding : -3px;\n"
"	color: rgb(174, 176, 176);\n"
"	border: 3px dashed rgb(174, 176, 176);\n"
"	font-size: 18px;\n"
"}"));
        gridLayout = new QGridLayout(Courses);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(Courses);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 586, 252));
        gridLayout_3 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(-1, 20, -1, -1);
        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(scrollArea, 0, 0, 1, 1);


        retranslateUi(Courses);

        QMetaObject::connectSlotsByName(Courses);
    } // setupUi

    void retranslateUi(QWidget *Courses)
    {
        Courses->setWindowTitle(QApplication::translate("Courses", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Courses: public Ui_Courses {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COURSES_H

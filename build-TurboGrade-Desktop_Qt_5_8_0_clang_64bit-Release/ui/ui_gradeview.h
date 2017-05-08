/********************************************************************************
** Form generated from reading UI file 'gradeview.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADEVIEW_H
#define UI_GRADEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GradeView
{
public:
    QVBoxLayout *verticalLayout_5;
    QLabel *title;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QLabel *total_grade;

    void setupUi(QWidget *GradeView)
    {
        if (GradeView->objectName().isEmpty())
            GradeView->setObjectName(QStringLiteral("GradeView"));
        GradeView->resize(429, 231);
        GradeView->setAutoFillBackground(false);
        GradeView->setStyleSheet(QLatin1String("QWidget#GradeView {\n"
"	background-color: #2b2f3b;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"#GradeView > #title {\n"
"	color: white;\n"
"	text-transform: uppercase;\n"
"}\n"
"\n"
"\n"
"#GradeView > #total_grade {\n"
"color:white;\n"
"}\n"
"\n"
"#level1 {\n"
"	color: darkgray;\n"
"	/* border: rgb(185, 0, 57); */\n"
"	background-color: white;\n"
"	border-radius: 6px;\n"
"	padding: 10px;\n"
"	border: 1px solid rgb(236, 239, 239);\n"
"}\n"
"\n"
"#level2 {\n"
"	color: darkgray;\n"
"	/* background: rgb(253, 117, 66); */\n"
"	background-color: white;\n"
"	border-radius: 6px;\n"
"	padding: 10px;\n"
"	border: 1px solid rgb(236, 239, 239);\n"
"}\n"
"#level3 {\n"
"	color: black;\n"
"	background-color: white;\n"
"	border: 3px solid rgb(230, 212, 0);\n"
"	border-radius: 6px;\n"
"	padding: 10px;\n"
"}\n"
"#level4 {\n"
"	color: darkgray;\n"
"	/* background: rgb(90, 175, 40); */\n"
"	background-color: white;\n"
"	border-radius: 6px;\n"
"	padding: 10px;\n"
"	border: 1px solid rgb(236, 239, 239);\n"
"}\n"
"\n"
"\n"
"#scrollArea"
                        "   {\n"
"	/* background-color:rgb(83, 86, 99); */\n"
"	/* background: #2b303c; */\n"
"	background-color:transparent;\n"
"	border-radius:3px;\n"
"}\n"
"QAbstractScrollArea #scrollAreaWidgetContents  {\n"
" background-color:transparent;\n"
"}\n"
"QGroupBox {\n"
"    background-color: white;\n"
"	border-radius:3px;\n"
"	border: 1px solid rgb(236, 239, 239);\n"
"}\n"
"\n"
"QGroupBox>QGroupBox {\n"
"	border: none\n"
"}\n"
"\n"
"QGroupBox #title {\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"	display:none;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(GradeView);
#ifndef Q_OS_MAC
        verticalLayout_5->setSpacing(-1);
#endif
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(8, 8, 8, 8);
        title = new QLabel(GradeView);
        title->setObjectName(QStringLiteral("title"));
        title->setMargin(0);

        verticalLayout_5->addWidget(title);

        scrollArea = new QScrollArea(GradeView);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setStyleSheet(QStringLiteral(""));
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 413, 159));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        scrollAreaWidgetContents->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
#ifndef Q_OS_MAC
        verticalLayout_3->setSpacing(-1);
#endif
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);

        total_grade = new QLabel(GradeView);
        total_grade->setObjectName(QStringLiteral("total_grade"));
        QFont font;
        font.setFamily(QStringLiteral("Open Sans"));
        font.setPointSize(16);
        font.setBold(false);
        font.setWeight(50);
        font.setKerning(false);
        total_grade->setFont(font);
        total_grade->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        total_grade->setMargin(0);

        verticalLayout_5->addWidget(total_grade);


        retranslateUi(GradeView);

        QMetaObject::connectSlotsByName(GradeView);
    } // setupUi

    void retranslateUi(QWidget *GradeView)
    {
        GradeView->setWindowTitle(QApplication::translate("GradeView", "Form", Q_NULLPTR));
        title->setText(QApplication::translate("GradeView", "RUBRIC & GRADING", Q_NULLPTR));
        total_grade->setText(QApplication::translate("GradeView", "Total Grade: 12 out of 15 (80%)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GradeView: public Ui_GradeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADEVIEW_H

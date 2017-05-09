/********************************************************************************
** Form generated from reading UI file 'rubricview.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUBRICVIEW_H
#define UI_RUBRICVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_RubricView
{
public:
    QVBoxLayout *mainLayout;
    QLabel *title;
    QGroupBox *add_box;
    QHBoxLayout *horizontalLayout;
    QLineEdit *criterion_name;
    QLabel *grade_label;
    QSpinBox *criterion_grade;
    ClickableLabel *add_criterion_btn;
    QVBoxLayout *criteria;
    QGroupBox *suggestions;
    QGridLayout *gridLayout;
    ClickableLabel *suggestion_extracredit;
    ClickableLabel *suggestion_correctness;
    ClickableLabel *suggestion_compiles;
    ClickableLabel *suggestion_documentation;
    ClickableLabel *suggestion_design;
    QPushButton *done_btn;

    void setupUi(QDialog *RubricView)
    {
        if (RubricView->objectName().isEmpty())
            RubricView->setObjectName(QStringLiteral("RubricView"));
        RubricView->resize(456, 330);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RubricView->sizePolicy().hasHeightForWidth());
        RubricView->setSizePolicy(sizePolicy);
#ifndef QT_NO_STATUSTIP
        RubricView->setStatusTip(QStringLiteral(""));
#endif // QT_NO_STATUSTIP
        RubricView->setStyleSheet(QLatin1String("QDialog#RubricView {\n"
"	background: white;\n"
"}\n"
"\n"
"#title {\n"
"	font-size: 24px;\n"
"}\n"
"\n"
"#add_box QLineEdit {\n"
"	border: none;\n"
"	background: transparent;\n"
"}\n"
"\n"
"QGroupBox {\n"
"	border: 0px solid gray;\n"
"	border-bottom: 1px solid lightgray;\n"
"	padding-top : 15px;\n"
"	padding-bottom : 15px;\n"
"	padding-right: 0px;\n"
"	margin: 0px;\n"
"}\n"
"\n"
"QGroupBox QGroupBox {\n"
"	border: 0px;\n"
"	border-bottom: 0px solid lightgray;\n"
"}\n"
"\n"
"#last, #suggestions {\n"
"	border-bottom: 0px solid gray;\n"
"}\n"
"\n"
"#suggestions {\n"
"	margin: 0px;\n"
"	padding-bottom: 0px;\n"
"	margin-top: 20px;\n"
"}\n"
"\n"
"#suggestions > QLabel {\n"
"	background: rgba(255, 241, 136, 200);\n"
"	color: rgb(153, 144, 50);\n"
"	border-radius: 3px;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"#has_children {\n"
"	padding-right: 0px;\n"
"	padding-bottom: 0px;\n"
"}\n"
"\n"
"#add_box {\n"
"	margin-top : 0px;\n"
"}\n"
"\n"
"#add_criterion_btn {\n"
"	color: rgb(52, 148, 255);\n"
"	font-weight: bold;\n"
"}\n"
"\n"
""
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
"#done_btn {\n"
"	border:none;\n"
"	text-transform: uppercase;\n"
"	padding: 10px;\n"
"	padding-left: 15px;\n"
"	padding-right: 15px;\n"
"	border-radius: 18px;\n"
"	color: white;\n"
"	background: #61b4ff;\n"
"	width: 100px;\n"
"	height: 18px;\n"
"}\n"
""));
        mainLayout = new QVBoxLayout(RubricView);
        mainLayout->setSpacing(0);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        title = new QLabel(RubricView);
        title->setObjectName(QStringLiteral("title"));

        mainLayout->addWidget(title);

        add_box = new QGroupBox(RubricView);
        add_box->setObjectName(QStringLiteral("add_box"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(add_box->sizePolicy().hasHeightForWidth());
        add_box->setSizePolicy(sizePolicy1);
        add_box->setFlat(true);
        horizontalLayout = new QHBoxLayout(add_box);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 0, -1, 0);
        criterion_name = new QLineEdit(add_box);
        criterion_name->setObjectName(QStringLiteral("criterion_name"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(criterion_name->sizePolicy().hasHeightForWidth());
        criterion_name->setSizePolicy(sizePolicy2);
        criterion_name->setMinimumSize(QSize(0, 30));

        horizontalLayout->addWidget(criterion_name);

        grade_label = new QLabel(add_box);
        grade_label->setObjectName(QStringLiteral("grade_label"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(grade_label->sizePolicy().hasHeightForWidth());
        grade_label->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(grade_label);

        criterion_grade = new QSpinBox(add_box);
        criterion_grade->setObjectName(QStringLiteral("criterion_grade"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(criterion_grade->sizePolicy().hasHeightForWidth());
        criterion_grade->setSizePolicy(sizePolicy4);

        horizontalLayout->addWidget(criterion_grade);

        add_criterion_btn = new ClickableLabel(add_box);
        add_criterion_btn->setObjectName(QStringLiteral("add_criterion_btn"));
        sizePolicy3.setHeightForWidth(add_criterion_btn->sizePolicy().hasHeightForWidth());
        add_criterion_btn->setSizePolicy(sizePolicy3);
        add_criterion_btn->setCursor(QCursor(Qt::PointingHandCursor));
        add_criterion_btn->setTextInteractionFlags(Qt::LinksAccessibleByKeyboard|Qt::LinksAccessibleByMouse);

        horizontalLayout->addWidget(add_criterion_btn);


        mainLayout->addWidget(add_box);

        criteria = new QVBoxLayout();
        criteria->setSpacing(0);
        criteria->setObjectName(QStringLiteral("criteria"));

        mainLayout->addLayout(criteria);

        suggestions = new QGroupBox(RubricView);
        suggestions->setObjectName(QStringLiteral("suggestions"));
        suggestions->setFlat(true);
        gridLayout = new QGridLayout(suggestions);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setHorizontalSpacing(-1);
        gridLayout->setContentsMargins(0, 40, 0, -1);
        suggestion_extracredit = new ClickableLabel(suggestions);
        suggestion_extracredit->setObjectName(QStringLiteral("suggestion_extracredit"));

        gridLayout->addWidget(suggestion_extracredit, 1, 1, 1, 1);

        suggestion_correctness = new ClickableLabel(suggestions);
        suggestion_correctness->setObjectName(QStringLiteral("suggestion_correctness"));

        gridLayout->addWidget(suggestion_correctness, 0, 2, 1, 1);

        suggestion_compiles = new ClickableLabel(suggestions);
        suggestion_compiles->setObjectName(QStringLiteral("suggestion_compiles"));

        gridLayout->addWidget(suggestion_compiles, 1, 0, 1, 1);

        suggestion_documentation = new ClickableLabel(suggestions);
        suggestion_documentation->setObjectName(QStringLiteral("suggestion_documentation"));

        gridLayout->addWidget(suggestion_documentation, 0, 1, 1, 1);

        suggestion_design = new ClickableLabel(suggestions);
        suggestion_design->setObjectName(QStringLiteral("suggestion_design"));

        gridLayout->addWidget(suggestion_design, 0, 0, 1, 1);


        mainLayout->addWidget(suggestions);

        done_btn = new QPushButton(RubricView);
        done_btn->setObjectName(QStringLiteral("done_btn"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/misc/res/confirm.png"), QSize(), QIcon::Normal, QIcon::Off);
        done_btn->setIcon(icon);
        done_btn->setAutoDefault(false);

        mainLayout->addWidget(done_btn);


        retranslateUi(RubricView);

        QMetaObject::connectSlotsByName(RubricView);
    } // setupUi

    void retranslateUi(QDialog *RubricView)
    {
        RubricView->setWindowTitle(QApplication::translate("RubricView", "Form", Q_NULLPTR));
#ifndef QT_NO_WHATSTHIS
        RubricView->setWhatsThis(QString());
#endif // QT_NO_WHATSTHIS
        title->setText(QApplication::translate("RubricView", "Binary Search Tree", Q_NULLPTR));
        add_box->setTitle(QString());
        criterion_name->setPlaceholderText(QApplication::translate("RubricView", "Add a new criterion", Q_NULLPTR));
        grade_label->setText(QApplication::translate("RubricView", "Total Pts.:", Q_NULLPTR));
        add_criterion_btn->setText(QApplication::translate("RubricView", "ADD", Q_NULLPTR));
        suggestions->setTitle(QApplication::translate("RubricView", "Suggestions", Q_NULLPTR));
        suggestion_extracredit->setText(QApplication::translate("RubricView", "Extra-credit", Q_NULLPTR));
        suggestion_correctness->setText(QApplication::translate("RubricView", "Correctness", Q_NULLPTR));
        suggestion_compiles->setText(QApplication::translate("RubricView", "Compiles", Q_NULLPTR));
        suggestion_documentation->setText(QApplication::translate("RubricView", "Documentation", Q_NULLPTR));
        suggestion_design->setText(QApplication::translate("RubricView", "Design", Q_NULLPTR));
        done_btn->setText(QApplication::translate("RubricView", "Done", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class RubricView: public Ui_RubricView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUBRICVIEW_H

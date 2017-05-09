/********************************************************************************
** Form generated from reading UI file 'formdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMDIALOG_H
#define UI_FORMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *title;
    QSpacerItem *verticalSpacer;
    QFormLayout *formLayout;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_btn;
    QPushButton *ok_btn;

    void setupUi(QWidget *FormDialog)
    {
        if (FormDialog->objectName().isEmpty())
            FormDialog->setObjectName(QStringLiteral("FormDialog"));
        FormDialog->resize(400, 161);
        FormDialog->setStyleSheet(QLatin1String("QWidget#FormDialog\n"
"{\n"
"	background: white;\n"
"}\n"
"\n"
"QLabel {\n"
"	text-transform: capitalize;\n"
"}\n"
"\n"
"#title {\n"
"	text-transform: capitalize;\n"
"	font-size: 16px;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QLineEdit, QTextEdit {\n"
"	border: none;\n"
"	border-bottom: 2px solid rgba(0,0,0,10);\n"
"	outline:none;\n"
"	padding: 5px;\n"
"}\n"
"\n"
"QLineEdit::focus, QTextEdit::focus {\n"
"	border: none;\n"
"	border-bottom: 2px solid lightgray;\n"
"	outline:none;\n"
"}\n"
"\n"
"#cancel_btn {\n"
"	border:none;\n"
"	background:transparent;\n"
"	color: black;\n"
"	text-transform: uppercase;\n"
"	width: 80px;\n"
"	height: 18px;\n"
"}\n"
"\n"
"#ok_btn {\n"
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
"\n"
"#warning, #info {\n"
"	border:none;\n"
"	text-transform: capitalize;\n"
"	padding: 10px;\n"
"	border-radius: 3"
                        "px;\n"
"	color: white;\n"
"	text-align: center;\n"
"}\n"
"\n"
"#warning {\n"
"	background: #f39c12;\n"
"}\n"
"\n"
"#info {\n"
"	background: #61b4ff;\n"
"}\n"
"\n"
"#select_folder {\n"
"	background: white;\n"
"	border: 1px solid lightgray;\n"
"	border-radius: 3px;\n"
"	padding: 10px;\n"
"	padding-top: 20px;\n"
"	padding-bottom: 20px;\n"
"}\n"
"\n"
"QComboBox {\n"
"	border: none;\n"
"	outline:none;\n"
"	padding: 10px;\n"
"	min-width: 100px;\n"
"	border-bottom: 2px solid rgba(0,0,0,10);\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 10px;\n"
"    height: 10px;\n"
"    border-image: url(:/misc/res/caret-down.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"	background: transparent;\n"
"	border: none;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(FormDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        title = new QLabel(FormDialog);
        title->setObjectName(QStringLiteral("title"));

        verticalLayout->addWidget(title);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setHorizontalSpacing(-1);
        formLayout->setVerticalSpacing(20);
        formLayout->setContentsMargins(-1, 20, -1, 20);

        verticalLayout->addLayout(formLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancel_btn = new QPushButton(FormDialog);
        cancel_btn->setObjectName(QStringLiteral("cancel_btn"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cancel_btn->sizePolicy().hasHeightForWidth());
        cancel_btn->setSizePolicy(sizePolicy);
        cancel_btn->setMaximumSize(QSize(16777215, 16777215));
        cancel_btn->setCursor(QCursor(Qt::PointingHandCursor));
        cancel_btn->setFlat(true);

        horizontalLayout_2->addWidget(cancel_btn);

        ok_btn = new QPushButton(FormDialog);
        ok_btn->setObjectName(QStringLiteral("ok_btn"));
        sizePolicy.setHeightForWidth(ok_btn->sizePolicy().hasHeightForWidth());
        ok_btn->setSizePolicy(sizePolicy);
        ok_btn->setMaximumSize(QSize(16777215, 16777215));
        ok_btn->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QStringLiteral(":/misc/res/confirm.png"), QSize(), QIcon::Normal, QIcon::Off);
        ok_btn->setIcon(icon);
        ok_btn->setIconSize(QSize(16, 16));
        ok_btn->setFlat(true);

        horizontalLayout_2->addWidget(ok_btn);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(FormDialog);

        ok_btn->setDefault(true);


        QMetaObject::connectSlotsByName(FormDialog);
    } // setupUi

    void retranslateUi(QWidget *FormDialog)
    {
        FormDialog->setWindowTitle(QApplication::translate("FormDialog", "Form", Q_NULLPTR));
        title->setText(QApplication::translate("FormDialog", "New Course", Q_NULLPTR));
        cancel_btn->setText(QApplication::translate("FormDialog", "Cancel", Q_NULLPTR));
        ok_btn->setText(QApplication::translate("FormDialog", " CONFIRM", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FormDialog: public Ui_FormDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMDIALOG_H

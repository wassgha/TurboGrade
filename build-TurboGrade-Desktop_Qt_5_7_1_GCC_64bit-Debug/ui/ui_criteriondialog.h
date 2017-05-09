/********************************************************************************
** Form generated from reading UI file 'criteriondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRITERIONDIALOG_H
#define UI_CRITERIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CriterionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *title;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *name_label;
    QLineEdit *name;
    QLabel *total_pts_label;
    QSpinBox *grade;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_btn;
    QPushButton *ok_btn;

    void setupUi(QWidget *CriterionDialog)
    {
        if (CriterionDialog->objectName().isEmpty())
            CriterionDialog->setObjectName(QStringLiteral("CriterionDialog"));
        CriterionDialog->resize(400, 191);
        CriterionDialog->setStyleSheet(QLatin1String("#CriterionDialog\n"
"{\n"
"        background: white;\n"
"}\n"
"\n"
"QLabel {\n"
"        text-transform: capitalize;\n"
"}\n"
"\n"
"#title {\n"
"        text-transform: capitalize;\n"
"        font-size: 16px;\n"
"        font-weight: bold;\n"
"}\n"
"\n"
"QLineEdit, QTextEdit {\n"
"        border: none;\n"
"        border-bottom: 2px solid rgba(0,0,0,10);\n"
"        outline:none;\n"
"        padding: 5px;\n"
"}\n"
"\n"
"QLineEdit::focus, QTextEdit::focus {\n"
"        border: none;\n"
"        border-bottom: 2px solid lightgray;\n"
"        outline:none;\n"
"}\n"
"\n"
"#cancel_btn {\n"
"        border:none;\n"
"        background:transparent;\n"
"        color: black;\n"
"        text-transform: uppercase;\n"
"        width: 80px;\n"
"        height: 18px;\n"
"}\n"
"\n"
"#ok_btn {\n"
"        border:none;\n"
"        text-transform: uppercase;\n"
"        padding: 10px;\n"
"        padding-left: 15px;\n"
"        padding-right: 15px;\n"
"        border-radius: 18px;\n"
"        color: white;\n"
"        back"
                        "ground: #61b4ff;\n"
"        width: 100px;\n"
"        height: 18px;\n"
"}\n"
"\n"
"#warning, #info {\n"
"        border:none;\n"
"        text-transform: capitalize;\n"
"        padding: 10px;\n"
"        border-radius: 3px;\n"
"        color: white;\n"
"        text-align: center;\n"
"}\n"
"\n"
"#warning {\n"
"        background: #f39c12;\n"
"}\n"
"\n"
"#info {\n"
"        background: #61b4ff;\n"
"}\n"
"\n"
"#select_folder {\n"
"        background: white;\n"
"        border: 1px solid lightgray;\n"
"        border-radius: 3px;\n"
"        padding: 10px;\n"
"        padding-top: 20px;\n"
"        padding-bottom: 20px;\n"
"}"));
        verticalLayout = new QVBoxLayout(CriterionDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        title = new QLabel(CriterionDialog);
        title->setObjectName(QStringLiteral("title"));

        verticalLayout->addWidget(title);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 20, -1, 20);
        name_label = new QLabel(CriterionDialog);
        name_label->setObjectName(QStringLiteral("name_label"));

        horizontalLayout->addWidget(name_label);

        name = new QLineEdit(CriterionDialog);
        name->setObjectName(QStringLiteral("name"));

        horizontalLayout->addWidget(name);

        total_pts_label = new QLabel(CriterionDialog);
        total_pts_label->setObjectName(QStringLiteral("total_pts_label"));

        horizontalLayout->addWidget(total_pts_label);

        grade = new QSpinBox(CriterionDialog);
        grade->setObjectName(QStringLiteral("grade"));

        horizontalLayout->addWidget(grade);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancel_btn = new QPushButton(CriterionDialog);
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

        ok_btn = new QPushButton(CriterionDialog);
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


        retranslateUi(CriterionDialog);

        ok_btn->setDefault(true);


        QMetaObject::connectSlotsByName(CriterionDialog);
    } // setupUi

    void retranslateUi(QWidget *CriterionDialog)
    {
        CriterionDialog->setWindowTitle(QApplication::translate("CriterionDialog", "Form", Q_NULLPTR));
        title->setText(QApplication::translate("CriterionDialog", "Parent:", Q_NULLPTR));
        name_label->setText(QApplication::translate("CriterionDialog", "Criterion: ", Q_NULLPTR));
        total_pts_label->setText(QApplication::translate("CriterionDialog", "Total Pts.:", Q_NULLPTR));
        cancel_btn->setText(QApplication::translate("CriterionDialog", "Cancel", Q_NULLPTR));
        ok_btn->setText(QApplication::translate("CriterionDialog", " CONFIRM", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CriterionDialog: public Ui_CriterionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRITERIONDIALOG_H

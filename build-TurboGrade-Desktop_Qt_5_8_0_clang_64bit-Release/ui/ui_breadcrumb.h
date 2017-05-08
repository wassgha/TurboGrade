/********************************************************************************
** Form generated from reading UI file 'breadcrumb.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BREADCRUMB_H
#define UI_BREADCRUMB_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Breadcrumb
{
public:
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *switcher_group;

    void setupUi(QWidget *Breadcrumb)
    {
        if (Breadcrumb->objectName().isEmpty())
            Breadcrumb->setObjectName(QStringLiteral("Breadcrumb"));
        Breadcrumb->resize(638, 37);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Breadcrumb->sizePolicy().hasHeightForWidth());
        Breadcrumb->setSizePolicy(sizePolicy);
        Breadcrumb->setMaximumSize(QSize(16777215, 41));
        Breadcrumb->setStyleSheet(QLatin1String("QWidget#Breadcrumb {\n"
"	max-height: 40px;\n"
"	background: white;\n"
"	border: 0px;\n"
"	border-bottom: 1px solid #f1f2f6;\n"
"}\n"
"\n"
"QLabel {\n"
"	color:gray;\n"
"}\n"
"\n"
"#last {\n"
"	color: black;\n"
"}\n"
"\n"
"#home {\n"
"	width: 20px;\n"
"	height: 35px;\n"
"	max-width: 20px;\n"
"	max-height: 35px;\n"
"	margin: 10px;\n"
"}\n"
"\n"
"#switcher {\n"
"	min-width: 35px;\n"
"	max-height: 20px;\n"
"	\n"
"}\n"
"#switcher_left, #switcher_right {\n"
"	margin: 5px;\n"
"}\n"
"\n"
"#export_csv_btn, #export_pdf_btn {\n"
"	background:transparent;\n"
"	text-transform: capitalize;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(Breadcrumb);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        horizontalLayout_3->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(376, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        switcher_group = new QHBoxLayout();
        switcher_group->setObjectName(QStringLiteral("switcher_group"));
        switcher_group->setContentsMargins(-1, -1, 12, -1);

        horizontalLayout_3->addLayout(switcher_group);


        retranslateUi(Breadcrumb);

        QMetaObject::connectSlotsByName(Breadcrumb);
    } // setupUi

    void retranslateUi(QWidget *Breadcrumb)
    {
        Breadcrumb->setWindowTitle(QApplication::translate("Breadcrumb", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Breadcrumb: public Ui_Breadcrumb {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BREADCRUMB_H

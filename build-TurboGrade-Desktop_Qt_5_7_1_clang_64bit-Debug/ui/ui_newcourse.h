/********************************************************************************
** Form generated from reading UI file 'newcourse.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWCOURSE_H
#define UI_NEWCOURSE_H

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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewCourse
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *title;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QLabel *name_label;
    QLineEdit *name;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_btn;
    QPushButton *ok_btn;

    void setupUi(QWidget *NewCourse)
    {
        if (NewCourse->objectName().isEmpty())
            NewCourse->setObjectName(QStringLiteral("NewCourse"));
        NewCourse->resize(400, 147);
        NewCourse->setStyleSheet(QLatin1String("#NewCourse\n"
"{\n"
"	background: white;\n"
"}\n"
"\n"
"#title {\n"
"	font-size: 16px;\n"
"	font-weight: bold;\n"
"}\n"
"\n"
"QLineEdit {\n"
"	border: none;\n"
"	border-bottom: 2px solid rgba(0,0,0,10);\n"
"	outline:none;\n"
"}\n"
"\n"
"QLineEdit::focus {\n"
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
"	background: white;\n"
"	border-radius: 18px;\n"
"	color: white;\n"
"	background: #61b4ff;\n"
"	width: 100px;\n"
"	height: 18px;\n"
"}"));
        verticalLayout = new QVBoxLayout(NewCourse);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        title = new QLabel(NewCourse);
        title->setObjectName(QStringLiteral("title"));

        verticalLayout->addWidget(title);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        name_label = new QLabel(NewCourse);
        name_label->setObjectName(QStringLiteral("name_label"));

        horizontalLayout->addWidget(name_label);

        name = new QLineEdit(NewCourse);
        name->setObjectName(QStringLiteral("name"));

        horizontalLayout->addWidget(name);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancel_btn = new QPushButton(NewCourse);
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

        ok_btn = new QPushButton(NewCourse);
        ok_btn->setObjectName(QStringLiteral("ok_btn"));
        sizePolicy.setHeightForWidth(ok_btn->sizePolicy().hasHeightForWidth());
        ok_btn->setSizePolicy(sizePolicy);
        ok_btn->setMaximumSize(QSize(16777215, 16777215));
        ok_btn->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QStringLiteral(":/misc/res/course.png"), QSize(), QIcon::Normal, QIcon::Off);
        ok_btn->setIcon(icon);
        ok_btn->setIconSize(QSize(16, 16));
        ok_btn->setFlat(true);

        horizontalLayout_2->addWidget(ok_btn);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(NewCourse);

        ok_btn->setDefault(true);


        QMetaObject::connectSlotsByName(NewCourse);
    } // setupUi

    void retranslateUi(QWidget *NewCourse)
    {
        NewCourse->setWindowTitle(QApplication::translate("NewCourse", "Form", Q_NULLPTR));
        title->setText(QApplication::translate("NewCourse", "New Course", Q_NULLPTR));
        name_label->setText(QApplication::translate("NewCourse", "Course name", Q_NULLPTR));
        cancel_btn->setText(QApplication::translate("NewCourse", "Cancel", Q_NULLPTR));
        ok_btn->setText(QApplication::translate("NewCourse", "Add Course", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class NewCourse: public Ui_NewCourse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWCOURSE_H

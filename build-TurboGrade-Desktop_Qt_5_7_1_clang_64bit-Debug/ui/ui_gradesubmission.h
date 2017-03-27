/********************************************************************************
** Form generated from reading UI file 'gradesubmission.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADESUBMISSION_H
#define UI_GRADESUBMISSION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GradeSubmission
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *logo;
    QComboBox *studentName;
    QCheckBox *hideName;
    QSpacerItem *spacer;
    QPushButton *run;
    QPushButton *toggle;
    QStackedWidget *mainWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *GradeSubmission)
    {
        if (GradeSubmission->objectName().isEmpty())
            GradeSubmission->setObjectName(QStringLiteral("GradeSubmission"));
        GradeSubmission->resize(841, 592);
        GradeSubmission->setStyleSheet(QLatin1String("QWidget#GradeSubmission {\n"
"       /* background: rgb(55, 64, 80); */\n"
"	background: #434653;\n"
"}\n"
"\n"
"QCheckBox#hideName {\n"
"        color: white;\n"
"}\n"
"\n"
"#run, #toggle {\n"
"	padding: 10px;\n"
"	padding-left: 15px;\n"
"	padding-right: 15px;\n"
"	background: white;\n"
"	border-radius: 18px;\n"
"	margin-left : 5px;\n"
"}\n"
"\n"
"#run {\n"
"	color: white;\n"
"	background: #63c46b;\n"
"}"));
        verticalLayout = new QVBoxLayout(GradeSubmission);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(12, 12, 12, 12);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        logo = new QLabel(GradeSubmission);
        logo->setObjectName(QStringLiteral("logo"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logo->sizePolicy().hasHeightForWidth());
        logo->setSizePolicy(sizePolicy);
        logo->setMaximumSize(QSize(100, 24));
        logo->setTextFormat(Qt::PlainText);
        logo->setPixmap(QPixmap(QString::fromUtf8(":/logo/res/logodark.png")));
        logo->setScaledContents(true);
        logo->setWordWrap(false);

        horizontalLayout_4->addWidget(logo);

        studentName = new QComboBox(GradeSubmission);
        studentName->setObjectName(QStringLiteral("studentName"));

        horizontalLayout_4->addWidget(studentName);

        hideName = new QCheckBox(GradeSubmission);
        hideName->setObjectName(QStringLiteral("hideName"));

        horizontalLayout_4->addWidget(hideName);

        spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(spacer);

        run = new QPushButton(GradeSubmission);
        run->setObjectName(QStringLiteral("run"));
        run->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QStringLiteral(":/misc/res/play-button-white.png"), QSize(), QIcon::Normal, QIcon::Off);
        run->setIcon(icon);
        run->setIconSize(QSize(16, 16));

        horizontalLayout_4->addWidget(run);

        toggle = new QPushButton(GradeSubmission);
        toggle->setObjectName(QStringLiteral("toggle"));
        toggle->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/misc/res/grade.png"), QSize(), QIcon::Normal, QIcon::Off);
        toggle->setIcon(icon1);
        toggle->setIconSize(QSize(16, 16));

        horizontalLayout_4->addWidget(toggle);


        verticalLayout->addLayout(horizontalLayout_4);

        mainWidget = new QStackedWidget(GradeSubmission);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        mainWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        mainWidget->addWidget(page_2);

        verticalLayout->addWidget(mainWidget);


        retranslateUi(GradeSubmission);

        toggle->setDefault(false);


        QMetaObject::connectSlotsByName(GradeSubmission);
    } // setupUi

    void retranslateUi(QWidget *GradeSubmission)
    {
        GradeSubmission->setWindowTitle(QApplication::translate("GradeSubmission", "Form", Q_NULLPTR));
        logo->setText(QString());
        studentName->clear();
        studentName->insertItems(0, QStringList()
         << QApplication::translate("GradeSubmission", "Student Name", Q_NULLPTR)
        );
        hideName->setText(QApplication::translate("GradeSubmission", "Hide student name", Q_NULLPTR));
        run->setText(QApplication::translate("GradeSubmission", "Run", Q_NULLPTR));
        toggle->setText(QApplication::translate("GradeSubmission", "View Grade", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GradeSubmission: public Ui_GradeSubmission {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADESUBMISSION_H

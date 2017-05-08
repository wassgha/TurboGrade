/********************************************************************************
** Form generated from reading UI file 'gradesubmission.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_GradeSubmission
{
public:
    QVBoxLayout *verticalLayout;
    QProgressBar *progressBar;
    QHBoxLayout *horizontalLayout_4;
    ClickableLabel *back;
    ClickableLabel *logo;
    QComboBox *studentName;
    QCheckBox *hideName;
    QPushButton *next;
    QSpacerItem *spacer;
    QPushButton *exportpdf;
    QPushButton *run;
    QPushButton *finalize;
    QStackedWidget *mainWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *GradeSubmission)
    {
        if (GradeSubmission->objectName().isEmpty())
            GradeSubmission->setObjectName(QStringLiteral("GradeSubmission"));
        GradeSubmission->setEnabled(true);
        GradeSubmission->resize(950, 369);
        GradeSubmission->setStyleSheet(QLatin1String("QWidget#GradeSubmission {\n"
"       /* background: rgb(55, 64, 80); */\n"
"	/* background: #434653;*/\n"
"	background: #232730;\n"
"}\n"
"\n"
"QCheckBox#hideName {\n"
"        color: white;\n"
"}\n"
"\n"
"QPushButton#run, QPushButton#exportpdf, QPushButton#finalize, QPushButton#next {\n"
"	padding: 10px;\n"
"	padding-left: 15px;\n"
"	padding-right: 15px;\n"
"	background: white;\n"
"	border-radius: 18px;\n"
"	margin-left : 10px;\n"
"}\n"
"\n"
"QPushButton#next::disabled {\n"
"	/*background: #EEE;*/\n"
"	color: gray;\n"
"}\n"
"\n"
"QPushButton#run {\n"
"	color: white;\n"
"	background: #63c46b;\n"
"}\n"
"\n"
"QPushButton#next {\n"
"	background: transparent;\n"
"	border:none;\n"
"	color: rgb(96, 151, 45);\n"
"	padding-left: 5px;\n"
"}\n"
"\n"
"QPushButton#finalize {\n"
"	color: white;\n"
"	background: rgb(204, 51, 51);\n"
"}\n"
"\n"
"QPushButton#finalize::disabled {\n"
"	color: white;\n"
"	background: rgb(204, 204, 204);\n"
"}\n"
"\n"
"QProgressBar#progressBar {\n"
"color: white;\n"
"max-height: 3px;\n"
"}\n"
"QP"
                        "rogressBar#progressBar:horizontal {\n"
"padding: 0px;\n"
"margin: 0px;\n"
"}\n"
"QProgressBar#progressBar::chunk:horizontal {\n"
"background: rgb(96, 151, 45);\n"
"padding: 0px;\n"
"margin: 0px;\n"
"}\n"
"\n"
""));
        verticalLayout = new QVBoxLayout(GradeSubmission);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        progressBar = new QProgressBar(GradeSubmission);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);
        progressBar->setAlignment(Qt::AlignCenter);
        progressBar->setTextVisible(false);
        progressBar->setTextDirection(QProgressBar::TopToBottom);

        verticalLayout->addWidget(progressBar);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(12);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_4->setContentsMargins(18, 18, 18, 18);
        back = new ClickableLabel(GradeSubmission);
        back->setObjectName(QStringLiteral("back"));
        back->setEnabled(true);
        back->setMaximumSize(QSize(20, 20));
        back->setPixmap(QPixmap(QString::fromUtf8(":/misc/res/back.png")));
        back->setScaledContents(true);
        back->setIndent(0);

        horizontalLayout_4->addWidget(back);

        logo = new ClickableLabel(GradeSubmission);
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
        studentName->setEnabled(true);
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(studentName->sizePolicy().hasHeightForWidth());
        studentName->setSizePolicy(sizePolicy1);
        studentName->setEditable(false);
        studentName->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        studentName->setMinimumContentsLength(20);

        horizontalLayout_4->addWidget(studentName);

        hideName = new QCheckBox(GradeSubmission);
        hideName->setObjectName(QStringLiteral("hideName"));
        hideName->setChecked(false);

        horizontalLayout_4->addWidget(hideName);

        next = new QPushButton(GradeSubmission);
        next->setObjectName(QStringLiteral("next"));
        next->setEnabled(false);
        QIcon icon;
        icon.addFile(QStringLiteral(":/misc/res/next_green.png"), QSize(), QIcon::Normal, QIcon::Off);
        icon.addFile(QStringLiteral(":/misc/res/next_gray.png"), QSize(), QIcon::Disabled, QIcon::Off);
        next->setIcon(icon);

        horizontalLayout_4->addWidget(next);

        spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(spacer);

        exportpdf = new QPushButton(GradeSubmission);
        exportpdf->setObjectName(QStringLiteral("exportpdf"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/misc/res/pdf.png"), QSize(), QIcon::Normal, QIcon::Off);
        exportpdf->setIcon(icon1);

        horizontalLayout_4->addWidget(exportpdf);

        run = new QPushButton(GradeSubmission);
        run->setObjectName(QStringLiteral("run"));
        run->setCursor(QCursor(Qt::PointingHandCursor));
        run->setMouseTracking(true);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/misc/res/play-button-white.png"), QSize(), QIcon::Normal, QIcon::Off);
        run->setIcon(icon2);
        run->setIconSize(QSize(16, 16));

        horizontalLayout_4->addWidget(run);

        finalize = new QPushButton(GradeSubmission);
        finalize->setObjectName(QStringLiteral("finalize"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/misc/res/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        finalize->setIcon(icon3);

        horizontalLayout_4->addWidget(finalize);


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

        QMetaObject::connectSlotsByName(GradeSubmission);
    } // setupUi

    void retranslateUi(QWidget *GradeSubmission)
    {
        GradeSubmission->setWindowTitle(QApplication::translate("GradeSubmission", "Form", Q_NULLPTR));
        progressBar->setFormat(QApplication::translate("GradeSubmission", "%p% of submissions graded", Q_NULLPTR));
        back->setText(QString());
        logo->setText(QString());
        studentName->clear();
        studentName->insertItems(0, QStringList()
         << QApplication::translate("GradeSubmission", "Student Name", Q_NULLPTR)
        );
        hideName->setText(QApplication::translate("GradeSubmission", "Hide name", Q_NULLPTR));
        next->setText(QApplication::translate("GradeSubmission", "Next Submission", Q_NULLPTR));
        exportpdf->setText(QApplication::translate("GradeSubmission", "Export PDF", Q_NULLPTR));
        run->setText(QApplication::translate("GradeSubmission", "Run", Q_NULLPTR));
        finalize->setText(QApplication::translate("GradeSubmission", "Finalize", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GradeSubmission: public Ui_GradeSubmission {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADESUBMISSION_H

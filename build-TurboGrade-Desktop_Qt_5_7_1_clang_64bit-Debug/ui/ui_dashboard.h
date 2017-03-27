/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBOARD_H
#define UI_DASHBOARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *header;
    QLabel *logo;
    QSpacerItem *spacer;
    QLabel *last_synced;
    QGroupBox *tutorial;
    QVBoxLayout *verticalLayout_2;
    QLabel *tutorial_head;
    QLabel *tutorial_text;
    QHBoxLayout *tutorial_btns;
    QSpacerItem *horizontalSpacer;
    QPushButton *tutorial_btn;
    QSpacerItem *horizontalSpacer_2;
    QStackedWidget *mainWidget;
    QWidget *page;
    QWidget *page_2;

    void setupUi(QWidget *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName(QStringLiteral("Dashboard"));
        Dashboard->resize(760, 475);
        Dashboard->setStyleSheet(QLatin1String("QWidget#Dashboard {\n"
"	background: #434653;\n"
"}\n"
"#add {\n"
"	padding: 10px;\n"
"	padding-left: 15px;\n"
"	padding-right: 15px;\n"
"	background: white;\n"
"	border-radius: 18px;\n"
"	color: white;\n"
"	background: #61b4ff;\n"
"}\n"
"#tutorial {\n"
"	background: #63c46b;\n"
"	color: white;\n"
"	border : none;\n"
"	text-align: center;\n"
"}\n"
"#tutorial > #tutorial_head, #tutorial > #tutorial_text {\n"
"	color: white;\n"
"	font-size: 16px;\n"
"	text-align: center;\n"
"}\n"
"\n"
"#tutorial > #tutorial_head {\n"
"	font-weight: bold;\n"
"	font-size: 22px;\n"
"}\n"
"\n"
"#tutorial_btn {\n"
"	border-radius: 3px;\n"
"	background: transparent;\n"
"	color: rgb(255, 255, 255);\n"
"	border: 1px solid rgb(255, 255, 255);\n"
"	text-transform: uppercase;\n"
"	max-width: 170px;\n"
"	padding: 8px;\n"
"	text-align:center;\n"
"	height: 20px;\n"
"	margin: 0px;\n"
"}\n"
"\n"
"\n"
"#last_synced {\n"
"	color: white;\n"
"}"));
        verticalLayout = new QVBoxLayout(Dashboard);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        header = new QHBoxLayout();
#ifndef Q_OS_MAC
        header->setSpacing(-1);
#endif
        header->setObjectName(QStringLiteral("header"));
        header->setSizeConstraint(QLayout::SetDefaultConstraint);
        header->setContentsMargins(12, 12, 12, 12);
        logo = new QLabel(Dashboard);
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

        header->addWidget(logo);

        spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        header->addItem(spacer);

        last_synced = new QLabel(Dashboard);
        last_synced->setObjectName(QStringLiteral("last_synced"));

        header->addWidget(last_synced);


        verticalLayout->addLayout(header);

        tutorial = new QGroupBox(Dashboard);
        tutorial->setObjectName(QStringLiteral("tutorial"));
        tutorial->setAlignment(Qt::AlignCenter);
        tutorial->setFlat(true);
        tutorial->setCheckable(false);
        verticalLayout_2 = new QVBoxLayout(tutorial);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 24, -1, 20);
        tutorial_head = new QLabel(tutorial);
        tutorial_head->setObjectName(QStringLiteral("tutorial_head"));
        tutorial_head->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(tutorial_head);

        tutorial_text = new QLabel(tutorial);
        tutorial_text->setObjectName(QStringLiteral("tutorial_text"));
        tutorial_text->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(tutorial_text);

        tutorial_btns = new QHBoxLayout();
        tutorial_btns->setObjectName(QStringLiteral("tutorial_btns"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        tutorial_btns->addItem(horizontalSpacer);

        tutorial_btn = new QPushButton(tutorial);
        tutorial_btn->setObjectName(QStringLiteral("tutorial_btn"));
        tutorial_btn->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QStringLiteral(":/misc/res/play-button-white.png"), QSize(), QIcon::Normal, QIcon::Off);
        tutorial_btn->setIcon(icon);
        tutorial_btn->setFlat(true);

        tutorial_btns->addWidget(tutorial_btn);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        tutorial_btns->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(tutorial_btns);


        verticalLayout->addWidget(tutorial);

        mainWidget = new QStackedWidget(Dashboard);
        mainWidget->setObjectName(QStringLiteral("mainWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(mainWidget->sizePolicy().hasHeightForWidth());
        mainWidget->setSizePolicy(sizePolicy1);
        mainWidget->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        mainWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        mainWidget->addWidget(page_2);

        verticalLayout->addWidget(mainWidget);


        retranslateUi(Dashboard);

        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QWidget *Dashboard)
    {
        Dashboard->setWindowTitle(QApplication::translate("Dashboard", "Form", Q_NULLPTR));
        logo->setText(QString());
        last_synced->setText(QApplication::translate("Dashboard", "Last synced : 5 seconds ago", Q_NULLPTR));
        tutorial->setTitle(QString());
        tutorial_head->setText(QApplication::translate("Dashboard", "New to TurboGrade?", Q_NULLPTR));
        tutorial_text->setText(QApplication::translate("Dashboard", "Take a look at our tutorials on Youtube.", Q_NULLPTR));
        tutorial_btn->setText(QApplication::translate("Dashboard", "WATCH TUTORIALS", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H

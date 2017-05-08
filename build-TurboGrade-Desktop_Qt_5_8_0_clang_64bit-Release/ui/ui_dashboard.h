/********************************************************************************
** Form generated from reading UI file 'dashboard.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_Dashboard
{
public:
    QAction *actionPreferences;
    QAction *actionSomething;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *header;
    QHBoxLayout *header_layout;
    ClickableLabel *logo;
    QSpacerItem *spacer;
    QLabel *last_synced;
    QLabel *network_indicator;
    ClickableLabel *sync_now;
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
    QMenuBar *menubar;
    QMenu *menuApplication;

    void setupUi(QMainWindow *Dashboard)
    {
        if (Dashboard->objectName().isEmpty())
            Dashboard->setObjectName(QStringLiteral("Dashboard"));
        Dashboard->resize(760, 475);
        Dashboard->setStyleSheet(QLatin1String("#centralwidget {\n"
"	background: #434653;\n"
"}\n"
"\n"
"#network_indicator {\n"
"	background: rgb(36, 255, 6);\n"
"	width: 6px;\n"
"	height: 6px;\n"
"	min-width: 6px;\n"
"	min-height: 6px;\n"
"	max-width: 6px;\n"
"	max-height: 6px;\n"
"	border-radius: 3px;\n"
"	margin: 5px;\n"
"}\n"
"\n"
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
"	padd"
                        "ing: 8px;\n"
"	text-align:center;\n"
"	height: 20px;\n"
"	margin: 0px;\n"
"}\n"
"\n"
"#sync_now {\n"
"	color: rgb(51, 204, 0);\n"
"	font-weight: bold;\n"
"	text-transform: uppercase;\n"
"}\n"
"\n"
"\n"
"#last_synced {\n"
"	color: white;\n"
"}\n"
"\n"
"QComboBox {\n"
"	border: none;\n"
"	min-width: 90px;\n"
"	outline:none;\n"
"	padding: 5px;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QComboBox::disabled {\n"
"    background: #E1E1E1;\n"
"}\n"
"\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 10px;\n"
"    height: 10px;\n"
"	margin: 5px;\n"
"    border-image: url(:/misc/res/caret-down.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"	background: transparent;\n"
"	border: none;\n"
"}\n"
"\n"
"\n"
"QSpinBox {\n"
"	border: none;\n"
"	outline:none;\n"
"	padding: 5px;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"QSpinBox::disabled {\n"
"    background: #E1E1E1;\n"
"	color: gray;\n"
"}\n"
"\n"
"QSpinBox::down-button {\n"
"	background:transparent;\n"
"	border: none;\n"
"	padding: 0px;\n"
"}\n"
"\n"
"QSpi"
                        "nBox::down-arrow {\n"
"    width: 10px;\n"
"    height: 10px;\n"
"    border-image: url(:/misc/res/caret-down.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"\n"
"QSpinBox::up-button {\n"
"	background:transparent;\n"
"	border: none;\n"
"	padding: 0px;\n"
"}\n"
"\n"
"QSpinBox::up-arrow {\n"
"    width: 10px;\n"
"    height: 10px;\n"
"    border-image: url(:/misc/res/caret-up.png) 0 0 0 0 stretch stretch;\n"
"}\n"
"QScrollBar {\n"
"	background:transparent;\n"
"	border:none;\n"
"}\n"
"QScrollBar:vertical {\n"
"	max-width: 12px;\n"
"    background: transparent;\n"
"}\n"
"\n"
"QScrollBar:horizontal {\n"
"	max-height: 12px;\n"
"    background: transparent;\n"
"}\n"
"QScrollBar::handle:horizontal, QScrollBar::handle:vertical {\n"
"	background: rgba(0,0,0, 0.2);\n"
"	border-radius: 3px;\n"
"	margin:3px;\n"
"}\n"
"\n"
"QScrollBar:left-arrow:horizontal, QScrollBar::right-arrow:horizontal {\n"
"    background: none;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {\n"
"    background: none;\n"
"}\n"
""
                        "QScrollBar::add-line:horizontal, QScrollBar::add-line:vertical {\n"
"    border: none;\n"
"    background: none;\n"
"    subcontrol-position: right;\n"
"    subcontrol-origin: margin;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal, QScrollBar::sub-line:vertical {\n"
"    border: none;\n"
"    background: none;\n"
"    subcontrol-position: left;\n"
"    subcontrol-origin: margin;\n"
"}"));
        actionPreferences = new QAction(Dashboard);
        actionPreferences->setObjectName(QStringLiteral("actionPreferences"));
        actionPreferences->setMenuRole(QAction::PreferencesRole);
        actionSomething = new QAction(Dashboard);
        actionSomething->setObjectName(QStringLiteral("actionSomething"));
        actionSomething->setIconVisibleInMenu(false);
        centralwidget = new QWidget(Dashboard);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        header = new QWidget(centralwidget);
        header->setObjectName(QStringLiteral("header"));
        header_layout = new QHBoxLayout(header);
#ifndef Q_OS_MAC
        header_layout->setSpacing(-1);
#endif
        header_layout->setObjectName(QStringLiteral("header_layout"));
        header_layout->setSizeConstraint(QLayout::SetDefaultConstraint);
        header_layout->setContentsMargins(12, 12, 12, 12);
        logo = new ClickableLabel(header);
        logo->setObjectName(QStringLiteral("logo"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(logo->sizePolicy().hasHeightForWidth());
        logo->setSizePolicy(sizePolicy);
        logo->setMaximumSize(QSize(100, 24));
        logo->setCursor(QCursor(Qt::PointingHandCursor));
        logo->setTextFormat(Qt::PlainText);
        logo->setPixmap(QPixmap(QString::fromUtf8(":/logo/res/logodark.png")));
        logo->setScaledContents(true);
        logo->setWordWrap(false);

        header_layout->addWidget(logo);

        spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        header_layout->addItem(spacer);

        last_synced = new QLabel(header);
        last_synced->setObjectName(QStringLiteral("last_synced"));

        header_layout->addWidget(last_synced);

        network_indicator = new QLabel(header);
        network_indicator->setObjectName(QStringLiteral("network_indicator"));

        header_layout->addWidget(network_indicator);

        sync_now = new ClickableLabel(header);
        sync_now->setObjectName(QStringLiteral("sync_now"));

        header_layout->addWidget(sync_now);


        verticalLayout->addWidget(header);

        tutorial = new QGroupBox(centralwidget);
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

        mainWidget = new QStackedWidget(centralwidget);
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

        Dashboard->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Dashboard);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 760, 22));
        menubar->setDefaultUp(false);
        menuApplication = new QMenu(menubar);
        menuApplication->setObjectName(QStringLiteral("menuApplication"));
        Dashboard->setMenuBar(menubar);

        menubar->addAction(menuApplication->menuAction());
        menuApplication->addAction(actionPreferences);

        retranslateUi(Dashboard);

        QMetaObject::connectSlotsByName(Dashboard);
    } // setupUi

    void retranslateUi(QMainWindow *Dashboard)
    {
        Dashboard->setWindowTitle(QApplication::translate("Dashboard", "Form", Q_NULLPTR));
        actionPreferences->setText(QApplication::translate("Dashboard", "Preferences", Q_NULLPTR));
        actionPreferences->setShortcut(QApplication::translate("Dashboard", "Ctrl+P", Q_NULLPTR));
        actionSomething->setText(QApplication::translate("Dashboard", "Something", Q_NULLPTR));
        logo->setText(QString());
        last_synced->setText(QApplication::translate("Dashboard", "Last synced : Just now", Q_NULLPTR));
        network_indicator->setText(QString());
        sync_now->setText(QApplication::translate("Dashboard", "Sync Now", Q_NULLPTR));
        tutorial->setTitle(QString());
        tutorial_head->setText(QApplication::translate("Dashboard", "New to TurboGrade?", Q_NULLPTR));
        tutorial_text->setText(QApplication::translate("Dashboard", "Take a look at our tutorials on Youtube.", Q_NULLPTR));
        tutorial_btn->setText(QApplication::translate("Dashboard", "WATCH TUTORIALS", Q_NULLPTR));
        menuApplication->setTitle(QApplication::translate("Dashboard", "File", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dashboard: public Ui_Dashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBOARD_H

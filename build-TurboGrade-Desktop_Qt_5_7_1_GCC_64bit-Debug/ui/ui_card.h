/********************************************************************************
** Form generated from reading UI file 'card.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARD_H
#define UI_CARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Card
{
public:
    QGridLayout *gridLayout;
    QGroupBox *card;
    QHBoxLayout *horizontalLayout;
    QLabel *logo;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *title;
    QLabel *info;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *Card)
    {
        if (Card->objectName().isEmpty())
            Card->setObjectName(QStringLiteral("Card"));
        Card->resize(216, 80);
        Card->setStyleSheet(QLatin1String("QWidget#Card {\n"
"	background:transparent;\n"
"}\n"
"#logo {\n"
"	background: #63c46b;\n"
"	border: none;\n"
"	border-radius : 22px;\n"
"	width : 45px;\n"
"	height: 45px;\n"
"	color: white;\n"
"	font-size: 18px;\n"
"	text-align: center;\n"
"	padding: 5px;\n"
"}\n"
"#card {\n"
"	background: white;\n"
"	border-radius: 3px;\n"
"	border: 1px solid lightgray;\n"
"}\n"
"#title {\n"
"	font-weight: bold;\n"
"}\n"
"#info {\n"
"	color: gray;\n"
"}"));
        gridLayout = new QGridLayout(Card);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        card = new QGroupBox(Card);
        card->setObjectName(QStringLiteral("card"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(card->sizePolicy().hasHeightForWidth());
        card->setSizePolicy(sizePolicy);
        card->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        card->setFlat(true);
        horizontalLayout = new QHBoxLayout(card);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        logo = new QLabel(card);
        logo->setObjectName(QStringLiteral("logo"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(logo->sizePolicy().hasHeightForWidth());
        logo->setSizePolicy(sizePolicy1);
        logo->setMinimumSize(QSize(45, 45));
        logo->setMaximumSize(QSize(45, 45));
        logo->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(logo);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, -1, -1, -1);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        title = new QLabel(card);
        title->setObjectName(QStringLiteral("title"));
        sizePolicy1.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy1);
        title->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(title);

        info = new QLabel(card);
        info->setObjectName(QStringLiteral("info"));
        sizePolicy1.setHeightForWidth(info->sizePolicy().hasHeightForWidth());
        info->setSizePolicy(sizePolicy1);
        info->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout->addWidget(info);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addWidget(card, 0, 0, 1, 1);


        retranslateUi(Card);

        QMetaObject::connectSlotsByName(Card);
    } // setupUi

    void retranslateUi(QWidget *Card)
    {
        Card->setWindowTitle(QApplication::translate("Card", "Form", Q_NULLPTR));
        card->setTitle(QString());
        logo->setText(QApplication::translate("Card", "CS", Q_NULLPTR));
        title->setText(QApplication::translate("Card", "CS 105", Q_NULLPTR));
        info->setText(QApplication::translate("Card", "2 Sections", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Card: public Ui_Card {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARD_H

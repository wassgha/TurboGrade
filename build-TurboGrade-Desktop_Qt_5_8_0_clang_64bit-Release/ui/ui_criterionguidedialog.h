/********************************************************************************
** Form generated from reading UI file 'criterionguidedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRITERIONGUIDEDIALOG_H
#define UI_CRITERIONGUIDEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CriterionGuideDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *title;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QLabel *info;
    QSlider *row_count;
    QLabel *score_per_level;
    QTableWidget *guide;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancel_btn;
    QPushButton *ok_btn;

    void setupUi(QWidget *CriterionGuideDialog)
    {
        if (CriterionGuideDialog->objectName().isEmpty())
            CriterionGuideDialog->setObjectName(QStringLiteral("CriterionGuideDialog"));
        CriterionGuideDialog->resize(400, 375);
        CriterionGuideDialog->setStyleSheet(QLatin1String("QWidget#CriterionGuideDialog\n"
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
"        background: #61b4ff;\n"
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
"#warning {"
                        "\n"
"        background: #f39c12;\n"
"}\n"
"\n"
"#info {\n"
"        background: #61b4ff;\n"
"\n"
"}\n"
"\n"
"#guide {\n"
"	border: none;\n"
"	background:transparent;\n"
"    outline: 0; /* Disable focus rect*/\n"
"}\n"
"\n"
"#guide::item {\n"
"	border: 2px solid lightgray;\n"
"	margin-left: 5px;\n"
"	margin-right: 5px;\n"
"	border-radius: 3px;\n"
"	text-align: left;\n"
"}"));
        verticalLayout = new QVBoxLayout(CriterionGuideDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        title = new QLabel(CriterionGuideDialog);
        title->setObjectName(QStringLiteral("title"));

        verticalLayout->addWidget(title);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(20, 20, 20, 20);
        info = new QLabel(CriterionGuideDialog);
        info->setObjectName(QStringLiteral("info"));
        info->setWordWrap(true);

        verticalLayout_2->addWidget(info);

        row_count = new QSlider(CriterionGuideDialog);
        row_count->setObjectName(QStringLiteral("row_count"));
        row_count->setMinimum(2);
        row_count->setMaximum(6);
        row_count->setPageStep(2);
        row_count->setValue(2);
        row_count->setOrientation(Qt::Horizontal);
        row_count->setTickPosition(QSlider::TicksBothSides);
        row_count->setTickInterval(0);

        verticalLayout_2->addWidget(row_count);

        score_per_level = new QLabel(CriterionGuideDialog);
        score_per_level->setObjectName(QStringLiteral("score_per_level"));

        verticalLayout_2->addWidget(score_per_level);

        guide = new QTableWidget(CriterionGuideDialog);
        if (guide->columnCount() < 2)
            guide->setColumnCount(2);
        if (guide->rowCount() < 1)
            guide->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        guide->setItem(0, 0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignLeading|Qt::AlignVCenter);
        __qtablewidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsEditable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        guide->setItem(0, 1, __qtablewidgetitem1);
        guide->setObjectName(QStringLiteral("guide"));
        guide->setFrameShape(QFrame::NoFrame);
        guide->setFrameShadow(QFrame::Plain);
        guide->setLineWidth(0);
        guide->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        guide->setAutoScroll(true);
        guide->setProperty("showDropIndicator", QVariant(false));
        guide->setAlternatingRowColors(false);
        guide->setShowGrid(true);
        guide->setGridStyle(Qt::NoPen);
        guide->setSortingEnabled(false);
        guide->setCornerButtonEnabled(true);
        guide->setRowCount(1);
        guide->setColumnCount(2);
        guide->horizontalHeader()->setVisible(false);
        guide->horizontalHeader()->setCascadingSectionResizes(false);
        guide->horizontalHeader()->setDefaultSectionSize(168);
        guide->horizontalHeader()->setHighlightSections(true);
        guide->horizontalHeader()->setMinimumSectionSize(15);
        guide->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        guide->horizontalHeader()->setStretchLastSection(true);
        guide->verticalHeader()->setVisible(false);
        guide->verticalHeader()->setDefaultSectionSize(35);
        guide->verticalHeader()->setHighlightSections(true);
        guide->verticalHeader()->setMinimumSectionSize(21);
        guide->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        guide->verticalHeader()->setStretchLastSection(true);

        verticalLayout_2->addWidget(guide);


        verticalLayout->addLayout(verticalLayout_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(70, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        cancel_btn = new QPushButton(CriterionGuideDialog);
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

        ok_btn = new QPushButton(CriterionGuideDialog);
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


        retranslateUi(CriterionGuideDialog);

        ok_btn->setDefault(true);


        QMetaObject::connectSlotsByName(CriterionGuideDialog);
    } // setupUi

    void retranslateUi(QWidget *CriterionGuideDialog)
    {
        CriterionGuideDialog->setWindowTitle(QApplication::translate("CriterionGuideDialog", "Form", Q_NULLPTR));
        title->setText(QApplication::translate("CriterionGuideDialog", "Guide for :", Q_NULLPTR));
        info->setText(QApplication::translate("CriterionGuideDialog", "Please set a number of levels and describe the profeciency required at each level", Q_NULLPTR));
        score_per_level->setText(QApplication::translate("CriterionGuideDialog", "Grade per level : ", Q_NULLPTR));

        const bool __sortingEnabled = guide->isSortingEnabled();
        guide->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem = guide->item(0, 0);
        ___qtablewidgetitem->setText(QApplication::translate("CriterionGuideDialog", "Define the expectation from each level", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = guide->item(0, 1);
        ___qtablewidgetitem1->setText(QApplication::translate("CriterionGuideDialog", "Define the expectation from each level", Q_NULLPTR));
        guide->setSortingEnabled(__sortingEnabled);

        cancel_btn->setText(QApplication::translate("CriterionGuideDialog", "Cancel", Q_NULLPTR));
        ok_btn->setText(QApplication::translate("CriterionGuideDialog", " CONFIRM", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CriterionGuideDialog: public Ui_CriterionGuideDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRITERIONGUIDEDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'criterionitem.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRITERIONITEM_H
#define UI_CRITERIONITEM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE

class Ui_CriterionItem
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *criterion;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    ClickableLabel *add_child;
    ClickableLabel *remove;
    ClickableLabel *add_guide;
    QLabel *name;
    QLabel *grade;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *sub_criteria;

    void setupUi(QWidget *CriterionItem)
    {
        if (CriterionItem->objectName().isEmpty())
            CriterionItem->setObjectName(QStringLiteral("CriterionItem"));
        CriterionItem->resize(495, 97);
        CriterionItem->setStyleSheet(QLatin1String("#add_child, #add_guide, #remove {\n"
"	margin-right: 10px;\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(CriterionItem);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        criterion = new QGroupBox(CriterionItem);
        criterion->setObjectName(QStringLiteral("criterion"));
        criterion->setFlat(true);
        verticalLayout_3 = new QVBoxLayout(criterion);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        add_child = new ClickableLabel(criterion);
        add_child->setObjectName(QStringLiteral("add_child"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(add_child->sizePolicy().hasHeightForWidth());
        add_child->setSizePolicy(sizePolicy);
        add_child->setMaximumSize(QSize(26, 16));
        add_child->setCursor(QCursor(Qt::PointingHandCursor));
        add_child->setPixmap(QPixmap(QString::fromUtf8(":/misc/res/add.png")));
        add_child->setScaledContents(true);

        horizontalLayout_4->addWidget(add_child);

        remove = new ClickableLabel(criterion);
        remove->setObjectName(QStringLiteral("remove"));
        remove->setMaximumSize(QSize(26, 16));
        remove->setCursor(QCursor(Qt::PointingHandCursor));
        remove->setPixmap(QPixmap(QString::fromUtf8(":/misc/res/delete.png")));
        remove->setScaledContents(true);

        horizontalLayout_4->addWidget(remove);

        add_guide = new ClickableLabel(criterion);
        add_guide->setObjectName(QStringLiteral("add_guide"));
        add_guide->setMaximumSize(QSize(26, 16));
        add_guide->setPixmap(QPixmap(QString::fromUtf8(":/misc/res/guide.png")));
        add_guide->setScaledContents(true);

        horizontalLayout_4->addWidget(add_guide);

        name = new QLabel(criterion);
        name->setObjectName(QStringLiteral("name"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        name->setFont(font);

        horizontalLayout_4->addWidget(name);

        grade = new QLabel(criterion);
        grade->setObjectName(QStringLiteral("grade"));

        horizontalLayout_4->addWidget(grade);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout_4);

        sub_criteria = new QVBoxLayout();
        sub_criteria->setObjectName(QStringLiteral("sub_criteria"));
        sub_criteria->setContentsMargins(-1, 12, -1, -1);

        verticalLayout_3->addLayout(sub_criteria);


        verticalLayout_2->addWidget(criterion);


        retranslateUi(CriterionItem);

        QMetaObject::connectSlotsByName(CriterionItem);
    } // setupUi

    void retranslateUi(QWidget *CriterionItem)
    {
        CriterionItem->setWindowTitle(QApplication::translate("CriterionItem", "Form", Q_NULLPTR));
        criterion->setTitle(QString());
        add_child->setText(QString());
        remove->setText(QString());
        add_guide->setText(QString());
        name->setText(QApplication::translate("CriterionItem", "Criterion name", Q_NULLPTR));
        grade->setText(QApplication::translate("CriterionItem", "(out of 10)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CriterionItem: public Ui_CriterionItem {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRITERIONITEM_H

/********************************************************************************
** Form generated from reading UI file 'criteriongradecard.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CRITERIONGRADECARD_H
#define UI_CRITERIONGRADECARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CriterionGradeCard
{
public:
    QGridLayout *gridLayout;
    QGroupBox *criterion;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontal_layout_2;
    QLabel *title;
    QSpinBox *grade;
    QLabel *out_of;
    QSpacerItem *spacer;
    QPushButton *show_comments;
    QVBoxLayout *children;
    QWidget *comments_container;
    QVBoxLayout *comments_container_layout;

    void setupUi(QWidget *CriterionGradeCard)
    {
        if (CriterionGradeCard->objectName().isEmpty())
            CriterionGradeCard->setObjectName(QStringLiteral("CriterionGradeCard"));
        CriterionGradeCard->resize(510, 272);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CriterionGradeCard->sizePolicy().hasHeightForWidth());
        CriterionGradeCard->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        CriterionGradeCard->setFont(font);
        CriterionGradeCard->setStyleSheet(QLatin1String("#show_comments {\n"
"	padding: 0px;\n"
"	margin: 0px;\n"
"	font-weight: bold;\n"
"     background: transparent;\n"
"     border: none;\n"
"}\n"
"    \n"
"#out_of {\n"
"	color:gray;\n"
"}\n"
"\n"
"#grade {\n"
"	text-align:center;\n"
"	background:white;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"#comments_container {\n"
"	padding: 10px;\n"
"	background: #232730;\n"
"	border-radius: 3px;\n"
"}\n"
"\n"
"#comments_container>QLabel {\n"
"	color:white;\n"
"	text-align: center;\n"
"}"));
        gridLayout = new QGridLayout(CriterionGradeCard);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        criterion = new QGroupBox(CriterionGradeCard);
        criterion->setObjectName(QStringLiteral("criterion"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(criterion->sizePolicy().hasHeightForWidth());
        criterion->setSizePolicy(sizePolicy1);
        criterion->setMaximumSize(QSize(16777215, 16777215));
        QFont font1;
        font1.setFamily(QStringLiteral("Avenir"));
        font1.setBold(true);
        font1.setWeight(75);
        criterion->setFont(font1);
        criterion->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        criterion->setFlat(true);
        verticalLayout = new QVBoxLayout(criterion);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontal_layout_2 = new QHBoxLayout();
        horizontal_layout_2->setObjectName(QStringLiteral("horizontal_layout_2"));
        title = new QLabel(criterion);
        title->setObjectName(QStringLiteral("title"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy2);
        title->setFont(font);

        horizontal_layout_2->addWidget(title);

        grade = new QSpinBox(criterion);
        grade->setObjectName(QStringLiteral("grade"));
        grade->setEnabled(false);
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(grade->sizePolicy().hasHeightForWidth());
        grade->setSizePolicy(sizePolicy3);
        grade->setWrapping(false);
        grade->setFrame(false);
        grade->setAlignment(Qt::AlignCenter);
        grade->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        grade->setAccelerated(false);
        grade->setProperty("showGroupSeparator", QVariant(false));
        grade->setValue(0);

        horizontal_layout_2->addWidget(grade);

        out_of = new QLabel(criterion);
        out_of->setObjectName(QStringLiteral("out_of"));
        sizePolicy2.setHeightForWidth(out_of->sizePolicy().hasHeightForWidth());
        out_of->setSizePolicy(sizePolicy2);

        horizontal_layout_2->addWidget(out_of);

        spacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontal_layout_2->addItem(spacer);

        show_comments = new QPushButton(criterion);
        show_comments->setObjectName(QStringLiteral("show_comments"));
        QFont font2;
        font2.setPointSize(13);
        font2.setBold(true);
        font2.setWeight(75);
        show_comments->setFont(font2);
        show_comments->setCursor(QCursor(Qt::PointingHandCursor));

        horizontal_layout_2->addWidget(show_comments);


        verticalLayout->addLayout(horizontal_layout_2);

        children = new QVBoxLayout();
        children->setObjectName(QStringLiteral("children"));

        verticalLayout->addLayout(children);

        comments_container = new QWidget(criterion);
        comments_container->setObjectName(QStringLiteral("comments_container"));
        sizePolicy.setHeightForWidth(comments_container->sizePolicy().hasHeightForWidth());
        comments_container->setSizePolicy(sizePolicy);
        comments_container_layout = new QVBoxLayout(comments_container);
        comments_container_layout->setObjectName(QStringLiteral("comments_container_layout"));
        comments_container_layout->setContentsMargins(12, 12, 12, 12);

        verticalLayout->addWidget(comments_container);


        gridLayout->addWidget(criterion, 0, 0, 1, 1);


        retranslateUi(CriterionGradeCard);

        QMetaObject::connectSlotsByName(CriterionGradeCard);
    } // setupUi

    void retranslateUi(QWidget *CriterionGradeCard)
    {
        CriterionGradeCard->setWindowTitle(QApplication::translate("CriterionGradeCard", "Form", Q_NULLPTR));
        criterion->setTitle(QString());
        title->setText(QApplication::translate("CriterionGradeCard", "COMPLETENESS", Q_NULLPTR));
        out_of->setText(QApplication::translate("CriterionGradeCard", "/ 12", Q_NULLPTR));
        show_comments->setText(QApplication::translate("CriterionGradeCard", "SHOW COMMENTS", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CriterionGradeCard: public Ui_CriterionGradeCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CRITERIONGRADECARD_H

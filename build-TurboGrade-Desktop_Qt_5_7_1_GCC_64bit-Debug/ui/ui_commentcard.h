/********************************************************************************
** Form generated from reading UI file 'commentcard.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMENTCARD_H
#define UI_COMMENTCARD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommentCard
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *info_container;
    QHBoxLayout *info;
    QLabel *adjust_grade;
    QLabel *rubric;
    QLabel *comment;
    QWidget *controls;
    QHBoxLayout *controls_layout;
    QSpacerItem *horizontalSpacer;
    QPushButton *edit_btn;
    QPushButton *delete_btn;

    void setupUi(QWidget *CommentCard)
    {
        if (CommentCard->objectName().isEmpty())
            CommentCard->setObjectName(QStringLiteral("CommentCard"));
        CommentCard->resize(387, 128);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CommentCard->sizePolicy().hasHeightForWidth());
        CommentCard->setSizePolicy(sizePolicy);
        CommentCard->setMinimumSize(QSize(0, 0));
        CommentCard->setMaximumSize(QSize(16777215, 16777215));
        CommentCard->setStyleSheet(QLatin1String("QWidget#CommentCard {\n"
"	/*background: rgb(255, 242, 160);*/\n"
"	background: #ffea8d;\n"
"	border-radius: 3px;\n"
"}"));
        verticalLayout = new QVBoxLayout(CommentCard);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        info_container = new QWidget(CommentCard);
        info_container->setObjectName(QStringLiteral("info_container"));
        sizePolicy.setHeightForWidth(info_container->sizePolicy().hasHeightForWidth());
        info_container->setSizePolicy(sizePolicy);
        info = new QHBoxLayout(info_container);
        info->setObjectName(QStringLiteral("info"));
        info->setContentsMargins(0, 0, 0, 0);
        adjust_grade = new QLabel(info_container);
        adjust_grade->setObjectName(QStringLiteral("adjust_grade"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(adjust_grade->sizePolicy().hasHeightForWidth());
        adjust_grade->setSizePolicy(sizePolicy1);
        adjust_grade->setStyleSheet(QStringLiteral(""));
        adjust_grade->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        info->addWidget(adjust_grade);

        rubric = new QLabel(info_container);
        rubric->setObjectName(QStringLiteral("rubric"));
        rubric->setStyleSheet(QLatin1String("#rubric {\n"
"	background: transparent;\n"
"	color: rgb(107, 100, 51);\n"
"}"));

        info->addWidget(rubric);


        verticalLayout->addWidget(info_container);

        comment = new QLabel(CommentCard);
        comment->setObjectName(QStringLiteral("comment"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comment->sizePolicy().hasHeightForWidth());
        comment->setSizePolicy(sizePolicy2);
        comment->setStyleSheet(QLatin1String("#comment {\n"
"	background: transparent;\n"
"	color: rgb(107, 100, 51);\n"
"}"));
        comment->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        comment->setWordWrap(true);

        verticalLayout->addWidget(comment);

        controls = new QWidget(CommentCard);
        controls->setObjectName(QStringLiteral("controls"));
        controls_layout = new QHBoxLayout(controls);
        controls_layout->setObjectName(QStringLiteral("controls_layout"));
        controls_layout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        controls_layout->addItem(horizontalSpacer);

        edit_btn = new QPushButton(controls);
        edit_btn->setObjectName(QStringLiteral("edit_btn"));
        edit_btn->setStyleSheet(QLatin1String("#edit_btn {\n"
"	background: transparent;\n"
"	text-transform: uppercase;\n"
"	color: rgb(107, 100, 51);\n"
"	font-weight: bold;\n"
"	padding: 0px;\n"
"}"));
        edit_btn->setFlat(true);

        controls_layout->addWidget(edit_btn);

        delete_btn = new QPushButton(controls);
        delete_btn->setObjectName(QStringLiteral("delete_btn"));
        delete_btn->setStyleSheet(QLatin1String("#delete_btn {\n"
"	background: transparent;\n"
"	text-transform: uppercase;\n"
"	color: rgb(204, 0, 0);\n"
"	font-weight: bold;\n"
"	padding: 0px;\n"
"}"));
        delete_btn->setFlat(true);

        controls_layout->addWidget(delete_btn);


        verticalLayout->addWidget(controls);


        retranslateUi(CommentCard);

        QMetaObject::connectSlotsByName(CommentCard);
    } // setupUi

    void retranslateUi(QWidget *CommentCard)
    {
        CommentCard->setWindowTitle(QApplication::translate("CommentCard", "Form", Q_NULLPTR));
        adjust_grade->setText(QApplication::translate("CommentCard", "(-2)", Q_NULLPTR));
        rubric->setText(QApplication::translate("CommentCard", "On rubric \"Completeness\"", Q_NULLPTR));
        comment->setText(QApplication::translate("CommentCard", "TextLabel", Q_NULLPTR));
        edit_btn->setText(QApplication::translate("CommentCard", "EDIT", Q_NULLPTR));
        delete_btn->setText(QApplication::translate("CommentCard", "DELETE", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CommentCard: public Ui_CommentCard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENTCARD_H

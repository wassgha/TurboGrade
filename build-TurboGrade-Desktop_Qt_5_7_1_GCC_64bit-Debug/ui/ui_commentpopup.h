/********************************************************************************
** Form generated from reading UI file 'commentpopup.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMENTPOPUP_H
#define UI_COMMENTPOPUP_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommentPopup
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *comment;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *adjust_grade_label;
    QSpinBox *adjust_grade;
    QSpacerItem *horizontalSpacer_2;
    QLabel *criterion_label;
    QComboBox *criterion;
    QSpacerItem *horizontalSpacer;
    QPushButton *add_btn;

    void setupUi(QWidget *CommentPopup)
    {
        if (CommentPopup->objectName().isEmpty())
            CommentPopup->setObjectName(QStringLiteral("CommentPopup"));
        CommentPopup->resize(513, 154);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CommentPopup->sizePolicy().hasHeightForWidth());
        CommentPopup->setSizePolicy(sizePolicy);
        CommentPopup->setStyleSheet(QLatin1String("QWidget#CommentPopup {\n"
"	/*background: rgb(255, 242, 160);*/\n"
"	background: #ffea8d;\n"
"	border-radius: 3px;\n"
"}\n"
"#comment {\n"
"\n"
"	background: transparent;\n"
"/*	border-radius: 3px;\n"
"	border: 1px solid rgb(127, 120, 71);*/\n"
"}\n"
"#add_btn {\n"
"	background: transparent;\n"
"	text-transform: uppercase;\n"
"	color: rgb(107, 100, 51);\n"
"	font-weight: bold;\n"
"	padding: 0px;\n"
"}"));
        verticalLayout = new QVBoxLayout(CommentPopup);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        comment = new QLineEdit(CommentPopup);
        comment->setObjectName(QStringLiteral("comment"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(comment->sizePolicy().hasHeightForWidth());
        comment->setSizePolicy(sizePolicy1);
        comment->setAutoFillBackground(false);
        comment->setFrame(false);
        comment->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        comment->setClearButtonEnabled(false);

        verticalLayout->addWidget(comment);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        adjust_grade_label = new QLabel(CommentPopup);
        adjust_grade_label->setObjectName(QStringLiteral("adjust_grade_label"));

        horizontalLayout->addWidget(adjust_grade_label);

        adjust_grade = new QSpinBox(CommentPopup);
        adjust_grade->setObjectName(QStringLiteral("adjust_grade"));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        adjust_grade->setFont(font);
        adjust_grade->setStyleSheet(QStringLiteral(""));
        adjust_grade->setWrapping(false);
        adjust_grade->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        adjust_grade->setMinimum(-5);
        adjust_grade->setMaximum(5);

        horizontalLayout->addWidget(adjust_grade);

        horizontalSpacer_2 = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        criterion_label = new QLabel(CommentPopup);
        criterion_label->setObjectName(QStringLiteral("criterion_label"));

        horizontalLayout->addWidget(criterion_label);

        criterion = new QComboBox(CommentPopup);
        criterion->setObjectName(QStringLiteral("criterion"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(criterion->sizePolicy().hasHeightForWidth());
        criterion->setSizePolicy(sizePolicy2);
        criterion->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(criterion);


        horizontalLayout_2->addLayout(horizontalLayout);

        horizontalSpacer = new QSpacerItem(0, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        add_btn = new QPushButton(CommentPopup);
        add_btn->setObjectName(QStringLiteral("add_btn"));
        add_btn->setStyleSheet(QStringLiteral(""));
        add_btn->setFlat(true);

        horizontalLayout_2->addWidget(add_btn);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(CommentPopup);

        QMetaObject::connectSlotsByName(CommentPopup);
    } // setupUi

    void retranslateUi(QWidget *CommentPopup)
    {
        CommentPopup->setWindowTitle(QApplication::translate("CommentPopup", "Form", Q_NULLPTR));
        comment->setPlaceholderText(QApplication::translate("CommentPopup", "Type your comment here...", Q_NULLPTR));
        adjust_grade_label->setText(QApplication::translate("CommentPopup", "Points", Q_NULLPTR));
        criterion_label->setText(QApplication::translate("CommentPopup", "Rubric", Q_NULLPTR));
        criterion->clear();
        criterion->insertItems(0, QStringList()
         << QApplication::translate("CommentPopup", "Completeness", Q_NULLPTR)
         << QApplication::translate("CommentPopup", "Design", Q_NULLPTR)
         << QApplication::translate("CommentPopup", "Documentation", Q_NULLPTR)
         << QApplication::translate("CommentPopup", "Implementation", Q_NULLPTR)
        );
        add_btn->setText(QApplication::translate("CommentPopup", "Add Comment", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CommentPopup: public Ui_CommentPopup {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMENTPOPUP_H

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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommentPopup
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *adjust_grade_label;
    QSpinBox *adjust_grade;
    QLabel *rubric_label;
    QComboBox *rubric;
    QTextEdit *comment;
    QPushButton *add_btn;

    void setupUi(QWidget *CommentPopup)
    {
        if (CommentPopup->objectName().isEmpty())
            CommentPopup->setObjectName(QStringLiteral("CommentPopup"));
        CommentPopup->resize(370, 177);
        CommentPopup->setStyleSheet(QLatin1String("QWidget#CommentPopup {\n"
"	background: rgb(255, 242, 160);\n"
"}"));
        verticalLayout = new QVBoxLayout(CommentPopup);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(12, -1, -1, -1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        adjust_grade_label = new QLabel(CommentPopup);
        adjust_grade_label->setObjectName(QStringLiteral("adjust_grade_label"));

        horizontalLayout->addWidget(adjust_grade_label);

        adjust_grade = new QSpinBox(CommentPopup);
        adjust_grade->setObjectName(QStringLiteral("adjust_grade"));
        adjust_grade->setStyleSheet(QLatin1String("QSpinBox#spinBox {\n"
"	outline:0;\n"
"	background: white;\n"
"}"));
        adjust_grade->setWrapping(false);
        adjust_grade->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        adjust_grade->setMinimum(-5);
        adjust_grade->setMaximum(5);

        horizontalLayout->addWidget(adjust_grade);

        rubric_label = new QLabel(CommentPopup);
        rubric_label->setObjectName(QStringLiteral("rubric_label"));

        horizontalLayout->addWidget(rubric_label);

        rubric = new QComboBox(CommentPopup);
        rubric->setObjectName(QStringLiteral("rubric"));

        horizontalLayout->addWidget(rubric);


        verticalLayout->addLayout(horizontalLayout);

        comment = new QTextEdit(CommentPopup);
        comment->setObjectName(QStringLiteral("comment"));

        verticalLayout->addWidget(comment);

        add_btn = new QPushButton(CommentPopup);
        add_btn->setObjectName(QStringLiteral("add_btn"));

        verticalLayout->addWidget(add_btn);


        retranslateUi(CommentPopup);

        QMetaObject::connectSlotsByName(CommentPopup);
    } // setupUi

    void retranslateUi(QWidget *CommentPopup)
    {
        CommentPopup->setWindowTitle(QApplication::translate("CommentPopup", "Form", Q_NULLPTR));
        adjust_grade_label->setText(QApplication::translate("CommentPopup", "Adjust grade : ", Q_NULLPTR));
        rubric_label->setText(QApplication::translate("CommentPopup", "Rubric:", Q_NULLPTR));
        rubric->clear();
        rubric->insertItems(0, QStringList()
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

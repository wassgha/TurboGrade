/********************************************************************************
** Form generated from reading UI file 'gradeview.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRADEVIEW_H
#define UI_GRADEVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GradeView
{
public:
    QVBoxLayout *verticalLayout_5;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpinBox *spinBox_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_11;
    QSpinBox *spinBox_6;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer_4;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_13;
    QSpinBox *spinBox_7;
    QLabel *label_14;
    QSpacerItem *horizontalSpacer_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_15;
    QSpinBox *spinBox_8;
    QLabel *label_16;
    QSpacerItem *horizontalSpacer_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_17;
    QSpinBox *spinBox_9;
    QLabel *label_18;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *spinBox;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *level1;
    QTextBrowser *level2;
    QTextBrowser *level3;
    QTextBrowser *level4;
    QPushButton *pushButton;
    QLabel *total_grade;
    QHBoxLayout *horizontalLayout_6;
    QSpacerItem *spacer;
    QPushButton *export_pdf;
    QPushButton *finalize;

    void setupUi(QWidget *GradeView)
    {
        if (GradeView->objectName().isEmpty())
            GradeView->setObjectName(QStringLiteral("GradeView"));
        GradeView->resize(659, 767);
        GradeView->setAutoFillBackground(false);
        GradeView->setStyleSheet(QLatin1String("#export_pdf, #finalize {\n"
"	color: white;\n"
"	padding: 10px;\n"
"}\n"
"\n"
"\n"
"#total_grade {\n"
"color:white;\n"
"}\n"
"\n"
"#level1 {\n"
"	color: darkgray;\n"
"	/* border: rgb(185, 0, 57); */\n"
"	background-color: white;\n"
"	border-radius: 6px;\n"
"	padding: 10px;\n"
"	border: 1px solid rgb(236, 239, 239);\n"
"}\n"
"\n"
"#level2 {\n"
"	color: darkgray;\n"
"	/* background: rgb(253, 117, 66); */\n"
"	background-color: white;\n"
"	border-radius: 6px;\n"
"	padding: 10px;\n"
"	border: 1px solid rgb(236, 239, 239);\n"
"}\n"
"#level3 {\n"
"	color: black;\n"
"	background-color: white;\n"
"	border: 3px solid rgb(230, 212, 0);\n"
"	border-radius: 6px;\n"
"	padding: 10px;\n"
"}\n"
"#level4 {\n"
"	color: darkgray;\n"
"	/* background: rgb(90, 175, 40); */\n"
"	background-color: white;\n"
"	border-radius: 6px;\n"
"	padding: 10px;\n"
"	border: 1px solid rgb(236, 239, 239);\n"
"}\n"
"\n"
"\n"
"#scrollArea   {\n"
"	background-color:rgb(83, 86, 99);\n"
"	border-radius:3px;\n"
"}\n"
"QAbstractScrollArea #scrollAreaWidge"
                        "tContents  {\n"
" background-color:transparent;\n"
"}\n"
"QGroupBox {\n"
"    background-color: white;\n"
"	border-radius:6px;\n"
"	padding-top: 3ex;\n"
"	border: 1px solid rgb(236, 239, 239);\n"
"}\n"
"QGroupBox::title {\n"
"	font-family:Montserrat;\n"
"	font-size:18px;\n"
"	margin-top: 10px;\n"
"	margin-left: 10px;\n"
"	background:transparent;\n"
"	font-weight: bold;\n"
"}"));
        verticalLayout_5 = new QVBoxLayout(GradeView);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(GradeView);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setStyleSheet(QStringLiteral(""));
        scrollArea->setFrameShadow(QFrame::Plain);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 659, 666));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents->setSizePolicy(sizePolicy1);
        scrollAreaWidgetContents->setMaximumSize(QSize(960, 16777215));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy2);
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Avenir"));
        font.setBold(true);
        font.setWeight(75);
        groupBox_2->setFont(font);
        groupBox_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        groupBox_2->setFlat(true);
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_3->addWidget(label_3);

        spinBox_2 = new QSpinBox(groupBox_2);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setEnabled(false);
        spinBox_2->setValue(10);

        horizontalLayout_3->addWidget(spinBox_2);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        groupBox_3 = new QGroupBox(groupBox_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        QFont font1;
        font1.setFamily(QStringLiteral("Avenir"));
        font1.setPointSize(13);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox_3->setFont(font1);
        groupBox_3->setFlat(false);
        verticalLayout_4 = new QVBoxLayout(groupBox_3);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_7->addWidget(label_11);

        spinBox_6 = new QSpinBox(groupBox_3);
        spinBox_6->setObjectName(QStringLiteral("spinBox_6"));
        spinBox_6->setEnabled(true);
        spinBox_6->setValue(3);

        horizontalLayout_7->addWidget(spinBox_6);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_7->addWidget(label_12);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_8->addWidget(label_13);

        spinBox_7 = new QSpinBox(groupBox_3);
        spinBox_7->setObjectName(QStringLiteral("spinBox_7"));
        spinBox_7->setEnabled(true);
        spinBox_7->setStyleSheet(QStringLiteral(""));
        spinBox_7->setValue(2);

        horizontalLayout_8->addWidget(spinBox_7);

        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_8->addWidget(label_14);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_5);


        verticalLayout_4->addLayout(horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_9->addWidget(label_15);

        spinBox_8 = new QSpinBox(groupBox_3);
        spinBox_8->setObjectName(QStringLiteral("spinBox_8"));
        spinBox_8->setEnabled(true);
        spinBox_8->setValue(4);

        horizontalLayout_9->addWidget(spinBox_8);

        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QStringLiteral("label_16"));

        horizontalLayout_9->addWidget(label_16);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_6);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QStringLiteral("label_17"));

        horizontalLayout_10->addWidget(label_17);

        spinBox_9 = new QSpinBox(groupBox_3);
        spinBox_9->setObjectName(QStringLiteral("spinBox_9"));
        spinBox_9->setEnabled(true);
        spinBox_9->setValue(2);

        horizontalLayout_10->addWidget(spinBox_9);

        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QStringLiteral("label_18"));

        horizontalLayout_10->addWidget(label_18);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_7);


        verticalLayout_4->addLayout(horizontalLayout_10);


        verticalLayout_2->addWidget(groupBox_3);

        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setFlat(true);

        verticalLayout_2->addWidget(pushButton_2);


        verticalLayout_3->addWidget(groupBox_2);

        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy3);
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        groupBox->setFlat(true);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(12, -1, -1, -1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_2->addWidget(label);

        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setValue(2);

        horizontalLayout_2->addWidget(spinBox);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        level1 = new QTextBrowser(groupBox);
        level1->setObjectName(QStringLiteral("level1"));
        sizePolicy.setHeightForWidth(level1->sizePolicy().hasHeightForWidth());
        level1->setSizePolicy(sizePolicy);
        level1->setFrameShape(QFrame::StyledPanel);
        level1->setFrameShadow(QFrame::Plain);
        level1->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        level1->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        level1->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        level1->setLineWrapMode(QTextEdit::WidgetWidth);
        level1->setAcceptRichText(true);

        horizontalLayout->addWidget(level1);

        level2 = new QTextBrowser(groupBox);
        level2->setObjectName(QStringLiteral("level2"));
        sizePolicy.setHeightForWidth(level2->sizePolicy().hasHeightForWidth());
        level2->setSizePolicy(sizePolicy);
        level2->setFrameShape(QFrame::StyledPanel);
        level2->setFrameShadow(QFrame::Plain);
        level2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        level2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        level2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        level2->setLineWrapMode(QTextEdit::WidgetWidth);
        level2->setAcceptRichText(true);

        horizontalLayout->addWidget(level2);

        level3 = new QTextBrowser(groupBox);
        level3->setObjectName(QStringLiteral("level3"));
        sizePolicy.setHeightForWidth(level3->sizePolicy().hasHeightForWidth());
        level3->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QStringLiteral("Avenir"));
        level3->setFont(font2);
        level3->setFrameShape(QFrame::StyledPanel);
        level3->setFrameShadow(QFrame::Plain);
        level3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        level3->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        level3->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        level3->setLineWrapMode(QTextEdit::WidgetWidth);
        level3->setAcceptRichText(true);

        horizontalLayout->addWidget(level3);

        level4 = new QTextBrowser(groupBox);
        level4->setObjectName(QStringLiteral("level4"));
        sizePolicy.setHeightForWidth(level4->sizePolicy().hasHeightForWidth());
        level4->setSizePolicy(sizePolicy);
        level4->setFont(font2);
        level4->setFrameShape(QFrame::StyledPanel);
        level4->setFrameShadow(QFrame::Plain);
        level4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        level4->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        level4->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        level4->setLineWrapMode(QTextEdit::WidgetWidth);
        level4->setAcceptRichText(true);

        horizontalLayout->addWidget(level4);


        verticalLayout->addLayout(horizontalLayout);

        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setFlat(true);

        verticalLayout->addWidget(pushButton);


        verticalLayout_3->addWidget(groupBox);

        total_grade = new QLabel(scrollAreaWidgetContents);
        total_grade->setObjectName(QStringLiteral("total_grade"));
        QFont font3;
        font3.setFamily(QStringLiteral("Open Sans"));
        font3.setPointSize(16);
        font3.setBold(false);
        font3.setWeight(50);
        font3.setKerning(false);
        total_grade->setFont(font3);
        total_grade->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        verticalLayout_3->addWidget(total_grade);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        spacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(spacer);

        export_pdf = new QPushButton(scrollAreaWidgetContents);
        export_pdf->setObjectName(QStringLiteral("export_pdf"));
        QFont font4;
        font4.setFamily(QStringLiteral("Open Sans"));
        font4.setBold(true);
        font4.setWeight(75);
        export_pdf->setFont(font4);
        export_pdf->setCursor(QCursor(Qt::PointingHandCursor));
        export_pdf->setFlat(true);

        horizontalLayout_6->addWidget(export_pdf);

        finalize = new QPushButton(scrollAreaWidgetContents);
        finalize->setObjectName(QStringLiteral("finalize"));
        QFont font5;
        font5.setFamily(QStringLiteral("Open Sans"));
        font5.setBold(true);
        font5.setWeight(75);
        font5.setKerning(true);
        finalize->setFont(font5);
        finalize->setCursor(QCursor(Qt::PointingHandCursor));
        finalize->setFlat(true);

        horizontalLayout_6->addWidget(finalize);


        verticalLayout_3->addLayout(horizontalLayout_6);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_5->addWidget(scrollArea);


        retranslateUi(GradeView);

        export_pdf->setDefault(true);
        finalize->setDefault(true);


        QMetaObject::connectSlotsByName(GradeView);
    } // setupUi

    void retranslateUi(QWidget *GradeView)
    {
        GradeView->setWindowTitle(QApplication::translate("GradeView", "Form", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("GradeView", "COMPLETENESS", Q_NULLPTR));
        label_3->setText(QApplication::translate("GradeView", "Grade :", Q_NULLPTR));
        label_4->setText(QApplication::translate("GradeView", " (out of 12)", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("GradeView", "SUB-CRITERIA", Q_NULLPTR));
        label_11->setText(QApplication::translate("GradeView", "Text parsing", Q_NULLPTR));
        label_12->setText(QApplication::translate("GradeView", " (out of 3)", Q_NULLPTR));
        label_13->setText(QApplication::translate("GradeView", "Visualization methods", Q_NULLPTR));
        label_14->setText(QApplication::translate("GradeView", " (out of 3)", Q_NULLPTR));
        label_15->setText(QApplication::translate("GradeView", "Insight from data", Q_NULLPTR));
        label_16->setText(QApplication::translate("GradeView", " (out of 4)", Q_NULLPTR));
        label_17->setText(QApplication::translate("GradeView", "Clear class hierarchy", Q_NULLPTR));
        label_18->setText(QApplication::translate("GradeView", " (out of 2)", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("GradeView", "Show comments on this criteria (Point adjustment: -1)", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("GradeView", "DOCUMENTATION", Q_NULLPTR));
        label->setText(QApplication::translate("GradeView", "Grade :", Q_NULLPTR));
        label_2->setText(QApplication::translate("GradeView", " (out of 3)", Q_NULLPTR));
        level1->setHtml(QApplication::translate("GradeView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">No comments</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">No JavaDoc</p></body></html>", Q_NULLPTR));
        level2->setHtml(QApplication::translate("GradeView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'.SF NS Text'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Few comments</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Not Javadoc compliant</p></body></html>", Q_NULLPTR));
        level3->setHtml(QApplication::translate("GradeView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Avenir'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text';\">Mostly commented</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text';\">Missing comments inside methods</span></p></body></html>", Q_NULLPTR));
        level4->setHtml(QApplication::translate("GradeView", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Avenir'; font-size:13pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text';\">Clearly documented</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text';\">JavaDoc compliant</span></p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("GradeView", "Show comments on this criteria (Point adjustment: 0)", Q_NULLPTR));
        total_grade->setText(QApplication::translate("GradeView", "Total Grade: 12 out of 15 (80%)", Q_NULLPTR));
        export_pdf->setText(QApplication::translate("GradeView", "Export to PDF", Q_NULLPTR));
        finalize->setText(QApplication::translate("GradeView", "Finalize Grade", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GradeView: public Ui_GradeView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRADEVIEW_H

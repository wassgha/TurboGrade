/********************************************************************************
** Form generated from reading UI file 'pdfwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PDFWINDOW_H
#define UI_PDFWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PDFWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PDFWindow)
    {
        if (PDFWindow->objectName().isEmpty())
            PDFWindow->setObjectName(QStringLiteral("PDFWindow"));
        PDFWindow->resize(800, 600);
        centralwidget = new QWidget(PDFWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        PDFWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PDFWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        PDFWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(PDFWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        PDFWindow->setStatusBar(statusbar);

        retranslateUi(PDFWindow);

        QMetaObject::connectSlotsByName(PDFWindow);
    } // setupUi

    void retranslateUi(QMainWindow *PDFWindow)
    {
        PDFWindow->setWindowTitle(QApplication::translate("PDFWindow", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class PDFWindow: public Ui_PDFWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PDFWINDOW_H

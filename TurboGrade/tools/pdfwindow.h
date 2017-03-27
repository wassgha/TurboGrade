#ifndef PDFWINDOW_H
#define PDFWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QLayout>
#include <QPdfWriter>
#include <QPagedPaintDevice>
#include <iostream>5
namespace Ui {
class PDFWindow;
}

class PDFWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit PDFWindow(QWidget *parent = 0);
    ~PDFWindow();

private:
    Ui::PDFWindow *ui;
    void paintEvent(QPaintEvent *);
};

#endif // PDFWINDOW_H

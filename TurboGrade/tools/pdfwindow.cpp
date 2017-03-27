#include "pdfwindow.h"
#include "ui_pdfwindow.h"

PDFWindow::PDFWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PDFWindow)
{
    ui->setupUi(this);
    resize(512,512);
}

PDFWindow::~PDFWindow()
{
    delete ui;
}

void PDFWindow::paintEvent(QPaintEvent *){
    QPainter painter;
    painter.begin(this);
    int coordX = 10;
    int coordY = 100;
    painter.drawText(coordX, coordY, QString("Writing Some text"));
    painter.end();

    QPdfWriter writer("pdftest");
    QPainter pdfpainter(&writer);
    writer.setPageSize(QPagedPaintDevice::Letter);
    float scalingX = writer.logicalDpiX() * 8.5 / this->size().width();
    float scalingY = writer.logicalDpiY() * 11 / this->size().height();
    std::cout << scalingX << std::endl;
    std::cout << scalingY << std::endl;
    pdfpainter.drawText(coordX * scalingX, coordY * scalingY,
                        QString("Writing Some text"));
    pdfpainter.end();
}

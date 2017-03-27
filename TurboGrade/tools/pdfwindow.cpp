#include "pdfwindow.h"
#include "ui_pdfwindow.h"

PDFWindow::PDFWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::PDFWindow)
{
    ui->setupUi(this);
    resize(1024,1024);
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

    int coordImageX = 10;
    int coordImageY = 200;
    QDir dir(".");
    std::cout << dir.absolutePath().toStdString() << std::endl;
    QImage erik("../../TurboGrade/images/erik.jpg");
    Q_ASSERT(!erik.isNull());
    painter.drawImage(coordImageX, coordImageY, erik);
    painter.end();

    QPdfWriter writer("pdftest.pdf");
    QPainter pdfpainter(&writer);
    writer.setPageSize(QPagedPaintDevice::Letter);
    float scalingX = writer.logicalDpiX() * 8.5 / this->size().width();
    float scalingY = writer.logicalDpiY() * 11 / this->size().height();
    std::cout << scalingX << std::endl;
    std::cout << scalingY << std::endl;
    pdfpainter.drawText(coordX * scalingX, coordY * scalingY,
                        QString("Writing Some text"));
    pdfpainter.drawImage(coordImageX * scalingX, coordImageY * scalingY,
                         erik.scaled(erik.width() * scalingX,
                                     erik.height() * scalingY,
                                     Qt::KeepAspectRatio));
    pdfpainter.end();
}

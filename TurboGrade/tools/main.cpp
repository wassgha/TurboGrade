#include <iostream>
#include "pdfwindow.h"
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PDFWindow w;
    w.show();
    a.exec();
    cout << "Hello World!" << endl;
    return 0;
}

#include <iostream>
#include <QApplication>
#include "htmltopdf.h"
#include "macadress.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HTMLToPDF w;
    w.show();
    a.exec();
    cout << "Hello World!" << endl;

    MacAdress m;
    return 0;
}

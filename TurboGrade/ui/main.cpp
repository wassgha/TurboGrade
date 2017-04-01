#include "dashboard.h"
#include "rubricview.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dashboard w;
    w.show();
    RubricView r;
    r.show();
    return a.exec();
}

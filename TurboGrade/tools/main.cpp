#include <iostream>
#include <QApplication>
#include "htmltopdf.h"
#include "macadress.h"
#include "../engine/controller.h"
#include "csvgenerator.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HTMLToPDF w;
    w.show();
    a.exec();
    cout << "Hello World!" << endl;

    MacAdress m;
    Controller *_controller;

    // Use new Controller(true) to drop tables
    _controller = new Controller();
    Course *course = _controller->get_course("CS 105");
    Section *section = course->get_section("02");
    Assignment* assignment = section->get_assignment("Binary Search Tree");
    CSVGenerator g;
    g.printProfessor(section,assignment,"test.txt");
    return 0;
}

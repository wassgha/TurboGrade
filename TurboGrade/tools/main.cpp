#include <iostream>
#include <QApplication>
#include "htmltopdf.h"
#include "macadress.h"
#include "../engine/controller.h"
#include "csvgenerator.h"
#include "studentdeliverable.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //cout << "Hello World!" << endl;

    //MacAdress m;
    Controller *_controller;

    // Use new Controller(true) to drop tables
    _controller = new Controller();
    Course *course = _controller->get_course("CS 105");
    Section *section = course->get_section("01");
    Assignment* assignment = section->get_assignment("Binary Search Tree");
    CSVGenerator g;
    g.printProfessor(section,assignment,"test.txt");

    StudentDeliverable s;
    QString html =  s.placeParameters(section->get_student("Wassim Gharbi")->get_submission(assignment));
    HTMLToPDF w(nullptr,html);
    //HTMLToPDF w(nullptr, 0);
    w.show();
    a.exec();

    return 0;
}

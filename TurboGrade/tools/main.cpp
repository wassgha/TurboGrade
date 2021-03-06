#include <iostream>
#include <QApplication>
#include "htmltopdf.h"
#include "macadress.h"
#include "../engine/controller.h"
#include "csvgenerator.h"
#include "studentdeliverable.h"
#include "dumptool.h"
#include "gitmodule.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //cout << "Hello World!" << endl;

    //MacAdress m;
    Controller *_controller;

//    // Use new Controller(true) to drop tables
//    _controller = new Controller(true, "tools.sql");


//    Course* cs105 = _controller->add_course("CS 105", "Fall 2017");
//    _controller->add_course("CS 150", "Fall 2017");
//    Course* cs150 = _controller->get_courses()->at(1);
//    cs150->add_section("01");
//    cs105->add_section("01");
//    Section * cs150_02 = cs105->add_section("02");
//    cs150_02->add_student("Wassim Gharbi");
//    cs150_02->add_student("Darren Norton");
//    cs105->add_section("03");
//    _controller->add_assignment("Binary Search Tree", "Implement a binary search tree with polymorphism");
//    Assignment *bst_assignment = _controller->get_assignments()->at(0);
//    cs150_02->add_assignment(bst_assignment);
//    Section* cs105_01 = cs105->_sections->at(0);
//    cs105_01->add_assignment(bst_assignment);


//    bst_assignment->_rubric->add_criterion("Correctness", NULL, 10);
//    bst_assignment->_rubric->add_criterion("Design", NULL, 5);
//    Criterion* comments = bst_assignment->_rubric->add_criterion("Comments", NULL, 2);
//    bst_assignment->_rubric->add_criterion("JavaDoc", comments, 2);

//    Student * gharbiw = cs150_02->get_student("Wassim Gharbi");
//    Submission* gharbiw_01 = gharbiw->add_submission(bst_assignment);
//    gharbiw_01->add_comment("main.java", bst_assignment->_rubric->get_criterion("Correctness"),
//                        "You screwed up bro", -2, 20, 150);
//    gharbiw_01->add_grade(bst_assignment->_rubric->get_criterion("Correctness"), 4);
//    gharbiw_01->add_grade(bst_assignment->_rubric->get_criterion("Design"), 3);
//    gharbiw_01->add_grade(bst_assignment->_rubric->get_criterion("JavaDoc"), 2);



//    Course *course = _controller->get_course("CS 105", "Fall 2017");
//    Section *section = course->get_section("02");
//    Assignment* assignment = section->get_assignment("Binary Search Tree");
////    CSVGenerator g;
////    g.printProfessor(section,assignment,"test.txt");

//    StudentDeliverable s;
//    QString html = s.placeParameters(section->get_student("Wassim Gharbi")->get_submission(assignment));
//    HTMLToPDF w(html, "output3.pdf");
//    w.show();
//    a.exec();

//    DumpTool d;
//    d.run_process("scp ../ui/turbograde.sqlite turbograde.sqlite");
//    d.dump("turbograde.sqlite", "dump.sqlite");
//    d.restore("turbograde2.sqlite", "dump.sqlite");
//    d.dump("turbograde2.sqlite", "dump2.sqlite");
//    // you will see that this prints nothing
//    d.run_process("diff dump.sqlite dump2.sqlite");

    GitModule git("sync", "ssh://spr2017_l1g4@139.147.9.185/home/spr2017_l1g4/sync.git", "637492638");
    git.clone();
    git.pull();
//    git.add("dump.sqlite");
//    git.commit("Committing dump");
//    git.push();

    return 0;
}


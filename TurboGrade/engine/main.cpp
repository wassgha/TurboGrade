#include <iostream>
#include "controller.h"

using namespace std;

int main(int argc, char *argv[])
{

    Controller* controller = new Controller();

//    controller->add_course("CS 105");
//    controller->add_course("CS 150");
//    controller->add_section("CS 105", "01");
//    controller->add_section("CS 105", "02");
//    controller->add_student("CS 105", "01", "Wassim Gharbi", "gharbiw");
//    controller->add_student("CS 105", "02", "Darren Norton", "nortondj");
//    controller->add_section("CS 150", "01");
//    controller->add_student("CS 150", "01", "Sam Cutrone", "cutrones");
//    controller->add_assignment("Binary Search Tree", "Implement a binary search tree with polymorphism");
//    controller->link_assignment("CS 105", "01", "Binary Search Tree", "/Users/wassgha/Downloads/CS105_01");
//    controller->link_assignment("CS 105", "02", "Binary Search Tree", "/Users/wassgha/Downloads/CS105_02");
//    controller->add_assignment("Red Black Tree", "Implement a red black tree");
//    controller->link_assignment("CS 150", "01", "Red Black Tree", "/Users/wassgha/Downloads/CS150_01");
//    controller->add_submission("CS 105", "02", "Darren Norton", "nortondj", "Binary Search Tree");

    controller->show_courses();

//    controller->add_criterion("Binary Search Tree", "Correctness", NULL, 10);
//    controller->add_criterion("Binary Search Tree", "Design", NULL, 5);
//    controller->add_criterion("Binary Search Tree", "Comments", NULL, 2);
//    controller->add_criterion("Binary Search Tree", "JavaDoc", "Comments", 1);

    controller->show_rubrics();
    return 0;
}

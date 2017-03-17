#include <iostream>
#include "coursecontroller.h"
#include "assignmentcontroller.h"

using namespace std;

int main(int argc, char *argv[])
{
    CourseController* courseController = new CourseController();
    AssignmentController* assignmentController = new AssignmentController(courseController);

//    courseController->add_course("CS 105");
//    courseController->add_course("CS 150");
//    courseController->add_section("CS 105", "01");
//    courseController->add_section("CS 105", "02");
//    courseController->add_student("CS 105", "01", "Wassim Gharbi", "gharbiw");
//    courseController->add_student("CS 105", "02", "Darren Norton", "nortondj");
//    courseController->add_section("CS 150", "01");
//    courseController->add_student("CS 150", "01", "Sam Cutrone", "cutrones");
//    assignmentController->add_assignment("Binary Search Tree", "Implement a binary search tree with polymorphism");
//    assignmentController->link_assignment("CS 105", "01", "Binary Search Tree", "/Users/wassgha/Downloads/CS105_01");
//    assignmentController->link_assignment("CS 105", "02", "Binary Search Tree", "/Users/wassgha/Downloads/CS105_02");
//    assignmentController->add_assignment("Red Black Tree", "Implement a red black tree");
//    assignmentController->link_assignment("CS 150", "01", "Red Black Tree", "/Users/wassgha/Downloads/CS150_01");
//    assignmentController->add_submission("CS 105", "02", "Darren Norton", "nortondj", "Binary Search Tree");

    courseController->show_courses();

//    assignmentController->add_criterion("Binary Search Tree", "Correctness", NULL, 10);
//    assignmentController->add_criterion("Binary Search Tree", "Design", NULL, 5);
//    assignmentController->add_criterion("Binary Search Tree", "Comments", NULL, 2);
//    assignmentController->add_criterion("Binary Search Tree", "JavaDoc", "Comments", 1);

    assignmentController->show_rubrics();
    return 0;
}

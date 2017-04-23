#include <iostream>
#include "../tools/objectidentifier.h"
#include "controller.h"
#include "assignment.h"
#include "student.h"
#include "section.h"
#include "criterion.h"
#include "submission.h"
#include "rubric.h"

using namespace std;

int main(int argc, char *argv[])
{

    QCoreApplication a(argc, argv);
    Controller *_controller;

    // Use new Controller(true) to drop tables
    _controller = new Controller(true, "../ui/turbograde.sqlite");

    /**************************************************
     *     Populate the database with dummy objects   *
     **************************************************/

    // Create courses, sections and students
    Course* cs105 = _controller->add_course("CS 105", "Fall 2017");
    _controller->add_course("CS 150", "Fall 2017");
    Course* cs150 = _controller->get_courses()->at(1);
    cs150->add_section("01");
    cs105->add_section("01");
    Section * cs150_02 = cs105->add_section("02");
    cs150_02->add_student("Wassim Gharbi");
    cs150_02->add_student("Darren Norton");
    cs105->add_section("03");

    // Create assignments
    _controller->add_assignment("Binary Search Tree", "Implement a binary search tree with polymorphism");
    Assignment *bst_assignment = _controller->get_assignments()->at(0);
    cs150_02->add_assignment(bst_assignment, "/Users/wassgha/Downloads/CS150_02");
    Section* cs105_01 = cs105->_sections->at(0);
    cs105_01->add_assignment(bst_assignment, "/Users/wassgha/Downloads/CS105_01");
    Section* cs105_02 = cs105->_sections->at(1);
    cs105_02->add_assignment(bst_assignment, "/Users/wassgha/Downloads/CS105_02");

    // Create a rubric
    bst_assignment->_rubric->add_criterion("Correctness", nullptr, 10);
    bst_assignment->_rubric->add_criterion("Design", nullptr, 5);
    Criterion* criterion = bst_assignment->_rubric->add_criterion("Comments", nullptr, 2);
    bst_assignment->_rubric->add_criterion("JavaDoc", criterion, 2);

    // Create a submission and grade it
    Student * gharbiw = cs105_02->get_student("Wassim Gharbi");
    Submission* gharbiw_01 = gharbiw->add_submission(bst_assignment);
    gharbiw_01->add_comment("main.java", bst_assignment->_rubric->get_criterion("Correctness"),
                            "You screwed up bro", -2, 20, 150);
    gharbiw_01->add_grade(bst_assignment->_rubric->get_criterion("Correctness"), 4);
    gharbiw_01->add_grade(bst_assignment->_rubric->get_criterion("Design"), 3);
    gharbiw_01->add_grade(bst_assignment->_rubric->get_criterion("JavaDoc"), 2);

    // Create a comment and erase it
    gharbiw_01->add_comment("main.java", bst_assignment->_rubric->get_criterion("Correctness"),
                                               "This comment was meant to be erased", -1, 10, 20);
    std::vector<Comment *> * comments = gharbiw_01->_comments;
    gharbiw_01->erase_comment(comments->at(comments->size() - 1));

    // Show the courses and rubrics
    _controller->show_courses();
    _controller->show_rubrics();

    std::cout<<"<Warning> Please compile and run the ui/ sub-project to run the GUI."<<endl;
    return 0;
}

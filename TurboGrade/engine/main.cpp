#include <iostream>
#include "../db/coursedb.h"

using namespace std;

int main(int argc, char *argv[])
{
    CourseController courseController;
//    courseController.add_course("CS 105");
//    courseController.add_course("CS 150");
//    courseController.add_section("CS 105", "01");
//    courseController.add_section("CS 105", "02");
//    courseController.add_student("CS 105", "01", "Wassim Gharbi");
//    courseController.add_student("CS 105", "02", "Darren Norton");
    courseController.show_courses();
    return 0;
}

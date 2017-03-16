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
    courseController.show_courses();
//    classdb.add("CS 150");
//    cout << "CS 150 has ID " << coursedb.select("CS 150") << endl;
    return 0;
}

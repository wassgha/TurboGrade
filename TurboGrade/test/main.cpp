#include "gtest/gtest.h"
#include <iostream>
//#include "../db/dbengine.h"
//#include "../db/coursedb.h"
//#include "../db/sectiondb.h"
//#include "../db/studentdb.h"
//#include "../db/assignmentdb.h"
//#include "../db/submissiondb.h"
//#include "../db/rubricdb.h"
//#include "../db/commentdb.h"
//#include "../db/gradedb.h"
//#include "../engine/course.h"
//#include "../engine/section.h"
//#include "../engine/student.h"
//#include "../engine/submission.h"
//#include "../engine/assignment.h"
//#include "../engine/rubric.h"
//#include "../engine/criterion.h"
//#include "../engine/controller.h"
//#include "../engine/comment.h"

using namespace std;

class EngineTest : public ::testing::Test{
protected:

    EngineTest()
    {

    }
    virtual ~EngineTest()
    {

    }
    virtual void SetUp() {
      // Code here will be called immediately after the constructor (right
      // before each test).
    }

    virtual void TearDown() {
      // Code here will be called immediately after each test (right
      // before the destructor).
    }

};

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


TEST(general,CONTROLLERBUILD) {
    //Controller testControl;



  ASSERT_EQ(1,1);
//  ASSERT_EQ(w1.get_headx(), 4) << w1.get_headx() << w1.get_heady();
//  ASSERT_EQ(w1.get_heady(), 4) << "Check head starts 4,4";
//  w1.move_up();
//  ASSERT_EQ(w1.get_headx(), 4);
//  ASSERT_EQ(w1.get_heady(), 5) << "Check head moves to 4,5";

}

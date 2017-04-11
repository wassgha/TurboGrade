#include "gtest/gtest.h"
#include <iostream>
#include "../db/dbengine.h"
#include "../db/coursedb.h"
#include "../db/sectiondb.h"
#include "../db/studentdb.h"
#include "../db/assignmentdb.h"
#include "../db/submissiondb.h"
#include "../db/rubricdb.h"
#include "../db/commentdb.h"
#include "../db/gradedb.h"
#include "../engine/course.h"
#include "../engine/section.h"
#include "../engine/student.h"
#include "../engine/submission.h"
#include "../engine/assignment.h"
#include "../engine/rubric.h"
#include "../engine/criterion.h"
#include "../engine/controller.h"
#include "../engine/comment.h"

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
    Controller testControl;
    testControl.add_course(0,"testCourse");
    vector<Course*>* courseList = testControl.get_courses();
    int x = courseList->size();
    ASSERT_EQ(x,1);
    testControl.add_course(1,"test2");
    courseList = testControl.get_courses();
    int x2 = courseList->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(x2,2);
}

TEST(general,CONTROLLERBReplaceKeep) {
    Controller* testControl = new Controller(false,"test.sql");
    testControl->add_course(-1,"testCourse");
    testControl->add_course(-1,"Course2");
    delete testControl;
    Controller* newControl = new Controller(false,"test.sql");
    vector<Course*>* courseList = newControl->get_courses();
    int x = courseList->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(x,2);
}

TEST(general,CONTROLLERBReplaceLose) {
    Controller* testControl = new Controller(false,"test.sql");
    testControl->add_course(-1,"testCourse");
    testControl->add_course(-1,"Course2");
    delete testControl;
    Controller* newControl = new Controller(true,"test.sql");
    vector<Course*>* courseList = newControl->get_courses();
    int x = courseList->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(x,0);
}

TEST(general,2CONTROLLERBUILD) {
    Controller testControl;
    testControl.add_course(0,"testCourse");
    vector<Course*>* courseList = testControl.get_courses();
    int x = courseList->size();
    ASSERT_EQ(x,1);
    testControl.add_course(1,"test2");
    courseList = testControl.get_courses();
    int x2 = courseList->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(x2,2);
}

TEST(general,2CONTROLLERBReplaceKeep) {
    Controller* testControl = new Controller(false,"test.sql");
    testControl->add_course(-1,"testCourse");
    testControl->add_course(-1,"Course2");
    delete testControl;
    Controller* newControl = new Controller(false,"test.sql");
    vector<Course*>* courseList = newControl->get_courses();
    int x = courseList->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(x,2);
}

TEST(general,2CONTROLLERBReplaceLose) {
    Controller* testControl = new Controller(false,"test.sql");
    testControl->add_course(-1,"testCourse");
    testControl->add_course(-1,"Course2");
    delete testControl;
    Controller* newControl = new Controller(true,"test.sql");
    vector<Course*>* courseList = newControl->get_courses();
    int x = courseList->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(x,0);
}

TEST(general,3CONTROLLERBUILD) {
    Controller testControl;
    testControl.add_course(0,"testCourse");
    vector<Course*>* courseList = testControl.get_courses();
    int x = courseList->size();
    ASSERT_EQ(x,1);
    testControl.add_course(1,"test2");
    courseList = testControl.get_courses();
    int x2 = courseList->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(x2,2);
}

TEST(general,3CONTROLLERBReplaceKeep) {
    Controller* testControl = new Controller(false,"test.sql");
    testControl->add_course(-1,"testCourse");
    testControl->add_course(-1,"Course2");
    delete testControl;
    Controller* newControl = new Controller(false,"test.sql");
    vector<Course*>* courseList = newControl->get_courses();
    int x = courseList->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(x,2);
}

TEST(general,3CONTROLLERBReplaceLose) {
    Controller* testControl = new Controller(false,"test.sql");
    testControl->add_course(-1,"testCourse");
    testControl->add_course(-1,"Course2");
    delete testControl;
    Controller* newControl = new Controller(true,"test.sql");
    vector<Course*>* courseList = newControl->get_courses();
    int x = courseList->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(x,0);
}

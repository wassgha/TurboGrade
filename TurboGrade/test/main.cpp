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

//course addition/not

TEST(general,CONTROLLERBUILD) {
    Controller testControl(true,"test.sql");
    testControl.add_course(-1,"testCourse");
    vector<Course*>* courseList = testControl.get_courses();
    int x = courseList->size();
    ASSERT_EQ(x,1);
    testControl.add_course(-1,"test2");
    courseList = testControl.get_courses();
    int x2 = courseList->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(x2,2);
}

TEST(general,CONTROLLERBReplaceKeep) {
    Controller* testControl = new Controller(true,"test.sql");
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
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course(-1,"testCourse");
    testControl->add_course(-1,"Course2");
    delete testControl;
    Controller* newControl = new Controller(true,"test.sql");
    vector<Course*>* courseList = newControl->get_courses();
    int x = courseList->size();
    ASSERT_EQ(x,0);
}

//section addition/not

TEST(general,2CONTROLLERBUILD) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course(-1,"testCourse");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section(-1,"testSection");
    vector<Section*>* sectionList = testCourse->get_sections();
    int x = sectionList->size();
    ASSERT_EQ(x,1);
    testCourse->add_section(-1,"testSection2");
    courseList = testControl->get_courses();
    testCourse = courseList->at(0);
    vector<Section*>* sectionList2 = testCourse->get_sections();
    int y = sectionList2->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(y,2);
}

TEST(general,2CONTROLLERBReplaceKeep) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course(-1,"testCourse");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section(-1,"testSection");
    testCourse->add_section(-1,"testSection2");
    delete testControl;
    Controller* newControl = new Controller(false,"test.sql");
    vector<Course*>* newCourseList = newControl->get_courses();
    Course* newTestCourse = newCourseList->at(0);
    vector<Section*>* sectionList = newTestCourse->get_sections();
    int x = sectionList->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(x,2);
}

TEST(general,2CONTROLLERBReplaceLose) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course(-1,"testCourse");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section(-1,"testSection");
    testCourse->add_section(-1,"testSection2");
    delete testControl;
    Controller* newControl = new Controller(true,"test.sql");
    newControl->add_course(-1,"testCourse");
    vector<Course*>* newCourseList = newControl->get_courses();
    Course* newTestCourse = newCourseList->at(0);
    vector<Section*>* sectionList = newTestCourse->get_sections();
    int x = sectionList->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(x,0);
}

//assignment addition/not

TEST(general,3CONTROLLERBUILD) {
    Controller testControl(true,"test.sql");
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
    Controller* testControl = new Controller(true,"test.sql");
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

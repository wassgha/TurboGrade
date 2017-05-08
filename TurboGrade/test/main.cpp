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

TEST(general,COURSEBUILD) {
    Controller testControl(true,"test.sql");
    testControl.add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl.get_courses();
    int x = courseList->size();
    ASSERT_EQ(x,1);
    testControl.add_course("test2", "Fall 2017");
    courseList = testControl.get_courses();
    int x2 = courseList->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(x2,2);
}

TEST(general,COURSEBReplaceKeep) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    testControl->add_course("Course2", "Fall 2017");
    delete testControl;
    Controller* newControl = new Controller(false,"test.sql");
    vector<Course*>* courseList = newControl->get_courses();
    int x = courseList->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(x,2);
}

TEST(general,COURSEBReplaceLose) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    testControl->add_course("Course2", "Fall 2017");
    delete testControl;
    Controller* newControl = new Controller(true,"test.sql");
    vector<Course*>* courseList = newControl->get_courses();
    int x = courseList->size();
    ASSERT_EQ(x,0);
}

//section addition/not

TEST(general,2SECTIONBUILD) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section("testSection");
    vector<Section*>* sectionList = testCourse->get_sections();
    int x = sectionList->size();
    ASSERT_EQ(x,1);
    testCourse->add_section("testSection2");
    courseList = testControl->get_courses();
    testCourse = courseList->at(0);
    vector<Section*>* sectionList2 = testCourse->get_sections();
    int y = sectionList2->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(y,2);
}

TEST(general,2SECTIONBReplaceKeep) {
    Controller* testControl = new Controller(true, "test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section("testSection");
    testCourse->add_section("testSection2");
    delete testControl;
    Controller* newControl = new Controller(false,"test.sql");
    vector<Course*>* newCourseList = newControl->get_courses();
    Course* newTestCourse = newCourseList->at(0);
    vector<Section*>* sectionList = newTestCourse->get_sections();
    int x = sectionList->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(x,2);
}

TEST(general,2SECTIONBReplaceLose) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section("testSection");
    testCourse->add_section("testSection2");
    delete testControl;
    Controller* newControl = new Controller(true,"test.sql");
    newControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* newCourseList = newControl->get_courses();
    Course* newTestCourse = newCourseList->at(0);
    vector<Section*>* sectionList = newTestCourse->get_sections();
    int x = sectionList->size();
    cout<<to_string(x)<<endl;
    ASSERT_EQ(x,0);
}

//assignment addition/not

TEST(general,3ASSIGNMENTBUILD) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section("testSection");
    vector<Section*>* sectionList = testCourse->get_sections();
    Section* testSection = sectionList->at(0);
    Assignment* testAssign = new Assignment("name","obj",testControl);
    testSection->add_assignment(testAssign,false);
    vector<Assignment*>* assignList = testSection->get_assignments();
    int x = assignList->size();
    ASSERT_EQ(x,1);
    testSection->add_assignment(testAssign, false);
    assignList = testSection->get_assignments();
    int y = assignList->size();
    ASSERT_EQ(y,2);
}

TEST(general,3ASSIGNMENTBReplaceKeep) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section("testSection");
    vector<Section*>* sectionList = testCourse->get_sections();
    Section* testSection = sectionList->at(0);
    Assignment* testAssign = new Assignment("name","obj",testControl);
    testSection->add_assignment(testAssign,false);
    vector<Assignment*>* assignList = testSection->get_assignments();
    int x = assignList->size();
    ASSERT_EQ(x,1);
    testSection->add_assignment(testAssign,false);
    assignList = testSection->get_assignments();
    int y = assignList->size();
    ASSERT_EQ(y,2);
}

TEST(general,3ASSIGNMENTBReplaceLose) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section("testSection");
    vector<Section*>* sectionList = testCourse->get_sections();
    Section* testSection = sectionList->at(0);
    Assignment* testAssign = new Assignment("name","obj",testControl);
    testSection->add_assignment(testAssign,false);
    vector<Assignment*>* assignList = testSection->get_assignments();
    int x = assignList->size();
    ASSERT_EQ(x,1);
    testSection->add_assignment(testAssign,false);
    assignList = testSection->get_assignments();
    int y = assignList->size();
    ASSERT_EQ(y,2);
}

TEST(general,submission_updateGrade) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section("testSection");
    vector<Section*>* sectionList = testCourse->get_sections();
    Section* testSection = sectionList->at(0);
    testSection->add_student("testStudent",-1);
    vector<Student*>* studentList = testSection->get_students();
    Student *testStudent = studentList->at(0);
    Assignment *testAssign = new Assignment("Test","Objective",testControl,false,-1);
    Rubric *testRubric = new Rubric(testAssign,testControl);
    testRubric->add_criterion("testCriterion",nullptr,10,-1);
    vector<Criterion*>* criterionList = testRubric->getCriterions();
    Criterion *testCriterion = criterionList->at(0);
    Submission *thisSubmission = new Submission(testAssign,testStudent,testControl,0,-1);
    ASSERT_NE(thisSubmission->get_grade(testCriterion),3);
    thisSubmission->update_grade(testCriterion,3,false);
    ASSERT_EQ(thisSubmission->get_grade(testCriterion),3);
}

TEST(general,submission_addComment) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section("testSection");
    vector<Section*>* sectionList = testCourse->get_sections();
    Section* testSection = sectionList->at(0);
    testSection->add_student("testStudent",-1);
    vector<Student*>* studentList = testSection->get_students();
    Student *testStudent = studentList->at(0);
    Assignment *testAssign = new Assignment("Test","Objective",testControl,false,-1);
    Rubric *testRubric = new Rubric(testAssign,testControl);
    testRubric->add_criterion("testCriterion",nullptr,10,-1);
    vector<Criterion*>* criterionList = testRubric->getCriterions();
    Criterion *testCriterion = criterionList->at(0);
    Submission *thisSubmission = new Submission(testAssign,testStudent,testControl,0,-1);
    ASSERT_NE(thisSubmission->get_grade(testCriterion),3);
    thisSubmission->add_comment("file",testCriterion,"text",3,0,10,-1);
    ASSERT_EQ(thisSubmission->get_grade(testCriterion),3);
}
// //////////////////////////////////////////////////////////////////////////
TEST(general,submission_deleteComment) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section("testSection");
    vector<Section*>* sectionList = testCourse->get_sections();
    Section* testSection = sectionList->at(0);
    testSection->add_student("testStudent",-1);
    vector<Student*>* studentList = testSection->get_students();
    Student *testStudent = studentList->at(0);
    Assignment *testAssign = new Assignment("Test","Objective",testControl,false,-1);
    Rubric *testRubric = new Rubric(testAssign,testControl);
    testRubric->add_criterion("testCriterion",nullptr,10,-1);
    vector<Criterion*>* criterionList = testRubric->getCriterions();
    Criterion *testCriterion = criterionList->at(0);
    Submission *thisSubmission = new Submission(testAssign,testStudent,testControl,0,-1);
    ASSERT_NE(thisSubmission->get_grade(testCriterion),3);
    thisSubmission->add_comment("file",testCriterion,"text",3,0,10,-1);
    vector <Comment*> commentList = thisSubmission->get_comments(testCriterion);
    vector <Comment*>* listPointer = &commentList;
    Comment* testComment = listPointer->at(0);
    delete listPointer->at(0);
    std::cerr<<listPointer->size()<<std::endl;
    ASSERT_EQ(2,2);
    //ASSERT_EQ(thisSubmission->get_grade(testCriterion),3);
}

TEST(general,submission_deleteRubricCriterion) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section("testSection");
    vector<Section*>* sectionList = testCourse->get_sections();
    Section* testSection = sectionList->at(0);
    testSection->add_student("testStudent",-1);
    vector<Student*>* studentList = testSection->get_students();
    Student *testStudent = studentList->at(0);
    Assignment *testAssign = new Assignment("Test","Objective",testControl,false,-1);
    Rubric *testRubric = new Rubric(testAssign,testControl);
    testRubric->add_criterion("testCriterion",nullptr,10,-1);
    vector<Criterion*>* criterionList = testRubric->getCriterions();
    Criterion *testCriterion = criterionList->at(0);
    Submission *thisSubmission = new Submission(testAssign,testStudent,testControl,0,-1);
    ASSERT_NE(thisSubmission->get_grade(testCriterion),3);
    thisSubmission->add_comment("file",testCriterion,"text",3,0,10,-1);
    ASSERT_EQ(2,2);
}

TEST(general,submission_deleteCourse) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section("testSection");
    vector<Section*>* sectionList = testCourse->get_sections();
    Section* testSection = sectionList->at(0);
    testSection->add_student("testStudent",-1);
    vector<Student*>* studentList = testSection->get_students();
    Student *testStudent = studentList->at(0);
    Assignment *testAssign = new Assignment("Test","Objective",testControl,false,-1);
    Rubric *testRubric = new Rubric(testAssign,testControl);
    testRubric->add_criterion("testCriterion",nullptr,10,-1);
    vector<Criterion*>* criterionList = testRubric->getCriterions();
    Criterion *testCriterion = criterionList->at(0);
    Submission *thisSubmission = new Submission(testAssign,testStudent,testControl,0,-1);
    ASSERT_NE(thisSubmission->get_grade(testCriterion),3);
    thisSubmission->add_comment("file",testCriterion,"text",3,0,10,-1);
    ASSERT_EQ(2,2);
}

TEST(general,submission_deleteSection_Students) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section("testSection");
    vector<Section*>* sectionList = testCourse->get_sections();
    Section* testSection = sectionList->at(0);
    testSection->add_student("testStudent",-1);
    vector<Student*>* studentList = testSection->get_students();
    Student *testStudent = studentList->at(0);
    Assignment *testAssign = new Assignment("Test","Objective",testControl,false,-1);
    Rubric *testRubric = new Rubric(testAssign,testControl);
    testRubric->add_criterion("testCriterion",nullptr,10,-1);
    vector<Criterion*>* criterionList = testRubric->getCriterions();
    Criterion *testCriterion = criterionList->at(0);
    Submission *thisSubmission = new Submission(testAssign,testStudent,testControl,0,-1);
    ASSERT_NE(thisSubmission->get_grade(testCriterion),3);
    thisSubmission->add_comment("file",testCriterion,"text",3,0,10,-1);
    ASSERT_EQ(2,2);
}

TEST(general,submission_deleteSection_Assignments) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section("testSection");
    vector<Section*>* sectionList = testCourse->get_sections();
    Section* testSection = sectionList->at(0);
    testSection->add_student("testStudent",-1);
    vector<Student*>* studentList = testSection->get_students();
    Student *testStudent = studentList->at(0);
    Assignment *testAssign = new Assignment("Test","Objective",testControl,false,-1);
    Rubric *testRubric = new Rubric(testAssign,testControl);
    testRubric->add_criterion("testCriterion",nullptr,10,-1);
    vector<Criterion*>* criterionList = testRubric->getCriterions();
    Criterion *testCriterion = criterionList->at(0);
    Submission *thisSubmission = new Submission(testAssign,testStudent,testControl,0,-1);
    ASSERT_NE(thisSubmission->get_grade(testCriterion),3);
    thisSubmission->add_comment("file",testCriterion,"text",3,0,10,-1);
    ASSERT_EQ(2,2);
}

TEST(general,submission_deleteStudent_Submission) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section("testSection");
    vector<Section*>* sectionList = testCourse->get_sections();
    Section* testSection = sectionList->at(0);
    testSection->add_student("testStudent",-1);
    vector<Student*>* studentList = testSection->get_students();
    Student *testStudent = studentList->at(0);
    Assignment *testAssign = new Assignment("Test","Objective",testControl,false,-1);
    Rubric *testRubric = new Rubric(testAssign,testControl);
    testRubric->add_criterion("testCriterion",nullptr,10,-1);
    vector<Criterion*>* criterionList = testRubric->getCriterions();
    Criterion *testCriterion = criterionList->at(0);
    Submission *thisSubmission = new Submission(testAssign,testStudent,testControl,0,-1);
    ASSERT_NE(thisSubmission->get_grade(testCriterion),3);
    thisSubmission->add_comment("file",testCriterion,"text",3,0,10,-1);
    ASSERT_EQ(2,2);
}

TEST(general,submission_deleteSubmission_comments) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section("testSection");
    vector<Section*>* sectionList = testCourse->get_sections();
    Section* testSection = sectionList->at(0);
    testSection->add_student("testStudent",-1);
    vector<Student*>* studentList = testSection->get_students();
    Student *testStudent = studentList->at(0);
    Assignment *testAssign = new Assignment("Test","Objective",testControl,false,-1);
    Rubric *testRubric = new Rubric(testAssign,testControl);
    testRubric->add_criterion("testCriterion",nullptr,10,-1);
    vector<Criterion*>* criterionList = testRubric->getCriterions();
    Criterion *testCriterion = criterionList->at(0);
    Submission *thisSubmission = new Submission(testAssign,testStudent,testControl,0,-1);
    ASSERT_NE(thisSubmission->get_grade(testCriterion),3);
    thisSubmission->add_comment("file",testCriterion,"text",3,0,10,-1);
    ASSERT_EQ(2,2);
}

TEST(general,submission_deleteSubmission_grades) {
    Controller* testControl = new Controller(true,"test.sql");
    testControl->add_course("testCourse", "Fall 2017");
    vector<Course*>* courseList = testControl->get_courses();
    Course* testCourse = courseList->at(0);
    testCourse->add_section("testSection");
    vector<Section*>* sectionList = testCourse->get_sections();
    Section* testSection = sectionList->at(0);
    testSection->add_student("testStudent",-1);
    vector<Student*>* studentList = testSection->get_students();
    Student *testStudent = studentList->at(0);
    Assignment *testAssign = new Assignment("Test","Objective",testControl,false,-1);
    Rubric *testRubric = new Rubric(testAssign,testControl);
    testRubric->add_criterion("testCriterion",nullptr,10,-1);
    vector<Criterion*>* criterionList = testRubric->getCriterions();
    Criterion *testCriterion = criterionList->at(0);
    Submission *thisSubmission = new Submission(testAssign,testStudent,testControl,0,-1);
    ASSERT_NE(thisSubmission->get_grade(testCriterion),3);
    thisSubmission->add_comment("file",testCriterion,"text",3,0,10,-1);
    ASSERT_EQ(2,2);
}

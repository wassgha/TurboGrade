#include "updatetests.h"

UpdateTests::UpdateTests(){

}

UpdateTests::~UpdateTests(){

}

void UpdateTests::SetUp(){
    testControl = new Controller(true,"test.sql");
    testCourse = testControl->add_course("testCourse", "Fall 2017");
    testSection = testCourse->add_section("testSection");
    testStudent = testSection->add_student("testStudent",-1);
    testAssignment = new Assignment("Test","Objective",testControl,false,-1);
    testSection->add_assignment(testAssignment);
    testRubric = testAssignment->_rubric;
    testCriterion = testRubric->add_criterion("testCriterion",nullptr,10,-1);
    testSubmission = testStudent->add_submission(testAssignment);
    testComment = testSubmission->add_comment("file",testCriterion,"text",3,0,10,-1);
}

void UpdateTests::TearDown(){
    delete testControl;
}

TEST_F(UpdateTests, UpdateCommentText){
    testComment->update("File", testCriterion, "New Text", 3, 0, 10);
    ASSERT_EQ(0, testComment->_text.compare("New Text"));
}

TEST_F(UpdateTests, UpdateCommentCriterion){
    Criterion *newCrit = testRubric->add_criterion("NewCrit", nullptr, 5);
    testComment->update("File", newCrit, "text", 3, 0, 10);
    ASSERT_EQ(newCrit, testComment->_criterion);
}

TEST_F(UpdateTests, UpdateCommentFile){
    testComment->update("New File", testCriterion, "text", 3, 0, 10);
    ASSERT_EQ(0, testComment->_filename.compare("New File"));
}

TEST_F(UpdateTests, UpdateCommentGrade){
    testComment->update("File", testCriterion, "text", 1, 0, 10);
    ASSERT_EQ(1, testComment->_grade);
}

TEST_F(UpdateTests, UpdateCommentStartPos){
    testComment->update("File", testCriterion, "text", 3, 5, 10);
    ASSERT_EQ(5, testComment->_start_pos);
}

TEST_F(UpdateTests, UpdateCommentEndPost){
    testComment->update("File", testCriterion, "text", 3, 0, 15);
    ASSERT_EQ(15, testComment->_end_pos);
}

TEST_F(UpdateTests, UpdateCommentCriterionRemovesFromOldCriterion){
    Criterion *newCrit = testRubric->add_criterion("NewCrit", nullptr, 5);
    testComment->update("File", newCrit, "text", 3, 0, 10);
    ASSERT_TRUE(testSubmission->get_comments(testCriterion).empty());
}

TEST_F(UpdateTests, UpdateCommentCriterionAddsToNewCriterion){
    Criterion *newCrit = testRubric->add_criterion("NewCrit", nullptr, 5);
    testComment->update("File", newCrit, "text", 3, 0, 10);
    ASSERT_EQ(1, testSubmission->get_comments(newCrit).size());
}

TEST_F(UpdateTests, UpdateCommentCriterionAdjustsGradeOldCriterion){
    Criterion *newCrit = testRubric->add_criterion("NewCrit", nullptr, 5);
    testComment->update("File", newCrit, "text", 3, 0, 10);
    ASSERT_EQ(0, testSubmission->get_grade(testCriterion));
}

TEST_F(UpdateTests, UpdateCommentCriterionAdjustsGradeNewCriterion){
    Criterion *newCrit = testRubric->add_criterion("NewCrit", nullptr, 5);
    testComment->update("File", newCrit, "text", 3, 0, 10);
    ASSERT_EQ(3, testSubmission->get_grade(newCrit));
}

TEST_F(UpdateTests, UpdateCriterionName){
    testCriterion->update("New Criterion",10);
    ASSERT_EQ(0, testCriterion->_name.compare("New Criterion"));
}

TEST_F(UpdateTests, UpdateCriterionNameSearch){
    testCriterion->update("New Criterion",10);
    ASSERT_EQ(testCriterion, testRubric->get_criterion("New Criterion"));
}

TEST_F(UpdateTests, UpdateCriterionOutOf){
    testCriterion->update("testCriterion", 5);
    ASSERT_EQ(5, testCriterion->_out_of);
}

TEST_F(UpdateTests, UpdateCriterionOutOfUpdatesGradesInSubmission){
    testCriterion->update("testCriterion", 5);
    ASSERT_EQ(3, testSubmission->get_grade(testCriterion));
}

TEST_F(UpdateTests, UpdateCriterionOutOfUpdatesGradesInSubmissionFG){
    testAssignment->_full_grade = true;
    testCriterion->update("testCriterion", 5);
    ASSERT_EQ(-2, testSubmission->get_grade(testCriterion));
}

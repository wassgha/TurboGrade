#include "deletiontests.h"
DeletionTests::DeletionTests()
{

}


DeletionTests::~DeletionTests(){

}

void DeletionTests::SetUp(){
    testControl = new Controller(true,"test.sql");
    testCourse = testControl->add_course("testCourse", "Fall 2017");
    testSection = testCourse->add_section("testSection");
    testStudent = testSection->add_student("testStudent",-1);
    testAssignment = new Assignment("Test","Objective",testControl,false,-1);
    testSection->add_assignment(testAssignment);
    testRubric = new Rubric(testAssignment,testControl);
    testCriterion = testRubric->add_criterion("testCriterion",nullptr,10,-1);
    testSubmission = testStudent->add_submission(testAssignment);
    testComment = testSubmission->add_comment("file",testCriterion,"text",3,0,10,-1);
}

void DeletionTests::TearDown(){
    delete testControl;
}

TEST_F(DeletionTests, RemoveCommentRemovesFromFile){
    testSubmission->remove_comment(testComment);
    std::vector<Comment*> comments = testSubmission->get_comment("file");
    ASSERT_FALSE(std::find(comments.begin(), comments.end(), testComment) != comments.end());
}

TEST_F(DeletionTests, RemoveCommentRemovesFromSubmission){
    testSubmission->remove_comment(testComment);
    std::vector<Comment*> comments = *testSubmission->get_comments();
    ASSERT_FALSE(std::find(comments.begin(), comments.end(), testComment) != comments.end());
}

TEST_F(DeletionTests, RemoveCommentAdjustsSubmissionGrade){
    testSubmission->remove_comment(testComment);
    ASSERT_EQ(0, testSubmission->get_grade());
}

TEST_F(DeletionTests, RemoveCommentAdjustsSubmissionCriterionGrade){
    testSubmission->remove_comment(testComment);
    ASSERT_EQ(0, testSubmission->get_grade(testCriterion));
}

TEST_F(DeletionTests, RemoveCommentAdjustsCriterionGrade){
    testSubmission->remove_comment(testComment);
    ASSERT_EQ(0, testSubmission->get_grade(testCriterion));
}

TEST_F(DeletionTests, RemoveCriterionRemovesFromRubric){
    testRubric->remove_criterion(testCriterion);
    ASSERT_EQ(testRubric->get_criterion("testCriterion"), nullptr);
}

TEST_F(DeletionTests, RemoveCriterionRemovesFromRubricObject){
    testRubric->remove_criterion(testCriterion);
    std::vector<Criterion*> criteria = *testRubric->getCriterions();
    ASSERT_FALSE(std::find(criteria.begin(), criteria.end(), testCriterion) != criteria.end());
}

TEST_F(DeletionTests, RemoveCriterionRemovesComments1){
    testRubric->remove_criterion(testCriterion);
    std::vector<Comment *> comments = testSubmission->get_comments(testCriterion);
    ASSERT_FALSE(std::find(comments.begin(), comments.end(), testComment) != comments.end());
}

TEST_F(DeletionTests, RemoveCriterionRemovesComments2){
    testRubric->remove_criterion(testCriterion);
    std::vector<Comment*> comments = *testSubmission->_comments;
    ASSERT_TRUE(comments.empty());
}



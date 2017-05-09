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
    testRubric = testAssignment->_rubric;
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

TEST_F(DeletionTests, RemoveCriterionUpdatesSubmissionGrade){
    testRubric->remove_criterion(testCriterion);
    ASSERT_EQ(testSubmission->get_grade(), 0);
}

TEST_F(DeletionTests, RemoveCriterionUpdatesRubricGrade){
    testRubric->remove_criterion(testCriterion);
    ASSERT_EQ(testRubric->total_grade(), 0);
}

TEST_F(DeletionTests, RemoveParentCriterionRemovesFromRubric){
    Criterion* subCrit = testRubric->add_criterion("SubCrit1",testCriterion,2);
    testSubmission->add_comment("File", subCrit, "nice", -1, 0, 0);
    testRubric->remove_criterion(testCriterion);
    ASSERT_EQ(testRubric->get_criterion("SubCrit1"), nullptr);
}

TEST_F(DeletionTests, RemoveParentCriterionRemovesFromRubricObject){
    Criterion* subCrit = testRubric->add_criterion("SubCrit1",testCriterion,2);
    testSubmission->add_comment("File", subCrit, "nice", -1, 0, 0);
    testRubric->remove_criterion(testCriterion);
    std::vector<Criterion*> criteria = *testRubric->getCriterions();
    ASSERT_FALSE(std::find(criteria.begin(), criteria.end(), subCrit) != criteria.end());
}

TEST_F(DeletionTests, RemoveParentCriterionRemovesComments1){
    Criterion* subCrit = testRubric->add_criterion("SubCrit1",testCriterion,2);
    testSubmission->add_comment("File", subCrit, "nice", -1, 0, 0);
    testRubric->remove_criterion(testCriterion);
    std::vector<Comment *> comments = testSubmission->get_comments(subCrit);
    ASSERT_FALSE(std::find(comments.begin(), comments.end(), testComment) != comments.end());
}

TEST_F(DeletionTests, RemoveParentCriterionRemovesComments2){
    Criterion* subCrit = testRubric->add_criterion("SubCrit1",testCriterion,2);
    testSubmission->add_comment("File", subCrit, "nice", -1, 0, 0);
    testRubric->remove_criterion(testCriterion);
    std::vector<Comment*> comments = *testSubmission->_comments;
    ASSERT_TRUE(comments.empty());
}

TEST_F(DeletionTests, RemoveParentCriterionUpdatesSubmissionGrade){
    Criterion* subCrit = testRubric->add_criterion("SubCrit1",testCriterion,2);
    testSubmission->add_comment("File", subCrit, "nice", -1, 0, 0);
    testRubric->remove_criterion(testCriterion);
    ASSERT_EQ(testSubmission->get_grade(), 0);
}

TEST_F(DeletionTests, RemoveParentCriterionUpdatesRubricGrade){
    Criterion* subCrit = testRubric->add_criterion("SubCrit1",testCriterion,2);
    testSubmission->add_comment("File", subCrit, "nice", -1, 0, 0);
    testRubric->remove_criterion(testCriterion);
    ASSERT_EQ(testRubric->total_grade(), 0);
}

TEST_F(DeletionTests, RemoveSubCriterionRemovesFromRubric){
    Criterion* subCrit = testRubric->add_criterion("SubCrit1",testCriterion,2);
    testSubmission->add_comment("File", subCrit, "nice", -1, 0, 0);
    testRubric->remove_criterion(subCrit);
    ASSERT_EQ(testRubric->get_criterion("SubCrit1"), nullptr);
}

TEST_F(DeletionTests, RemoveSubCriterionRemovesFromRubricObject){
    Criterion* subCrit = testRubric->add_criterion("SubCrit1",testCriterion,2);
    testSubmission->add_comment("File", subCrit, "nice", -1, 0, 0);
    testRubric->remove_criterion(subCrit);
    std::vector<Criterion*> criteria = *testRubric->getCriterions();
    ASSERT_FALSE(std::find(criteria.begin(), criteria.end(), subCrit) != criteria.end());
}

TEST_F(DeletionTests, RemoveSubCriterionRemovesComments1){
    Criterion* subCrit = testRubric->add_criterion("SubCrit1",testCriterion,2);
    Comment* subComment = testSubmission->add_comment("File", subCrit, "nice", -1, 0, 0);
    testRubric->remove_criterion(subCrit);
    std::vector<Comment *> comments = testSubmission->get_comments(subCrit);
    ASSERT_FALSE(std::find(comments.begin(), comments.end(), subComment) != comments.end());
}

TEST_F(DeletionTests, RemoveSubCriterionRemovesOnlyCommentsFromSub){
    Criterion* subCrit = testRubric->add_criterion("SubCrit1",testCriterion,2);
    testSubmission->add_comment("File", subCrit, "nice", -1, 0, 0);
    testRubric->remove_criterion(subCrit);
    std::vector<Comment*> comments = *testSubmission->_comments;
    ASSERT_EQ(comments.size(), 1);
}

TEST_F(DeletionTests, RemoveSubCriterionUpdatesSubmissionGrade){
    Criterion* subCrit = testRubric->add_criterion("SubCrit1",testCriterion,2);
    testSubmission->add_comment("File", subCrit, "nice", 1,0,0);
    //parent's grade is overriden since it has children, expect 1
    ASSERT_EQ(testSubmission->get_grade(testCriterion), 1);
    testRubric->remove_criterion(subCrit);
    //once the sub is remove, the grade should go back to the parent's
    ASSERT_EQ(testSubmission->get_grade(testCriterion), 3);
}

TEST_F(DeletionTests, RemoveSubCriterionUpdatesRubricGrade){
    Criterion* subCrit = testRubric->add_criterion("SubCrit1",testCriterion,2);
    testSubmission->add_comment("File", subCrit, "nice", -1, 0, 0);
    testRubric->remove_criterion(subCrit);
    ASSERT_EQ(testRubric->total_grade(), 10);
}

TEST_F(DeletionTests, RemoveSubmissionRemovesFromStudentGetSubmission){
    testStudent->remove_submission(testSubmission);
    ASSERT_EQ(nullptr, testStudent->get_submission(testAssignment));
}

TEST_F(DeletionTests, RemoveSubmissionRemovesFromStudent){
    testStudent->remove_submission(testSubmission);
    ASSERT_TRUE(testStudent->get_submissions()->empty());
}

TEST_F(DeletionTests, RemoveStudentFromSectionSearch){
    testSection->remove_student(testStudent);
    ASSERT_EQ(nullptr, testSection->get_student("testStudent"));
}

TEST_F(DeletionTests, RemoveStudentFromSectionList){
    testSection->remove_student(testStudent);
    ASSERT_TRUE(testSection->get_students()->empty());
}

TEST_F(DeletionTests, RemoveAssignmentFromSectionSearch){
    testSection->remove_assignment(testAssignment);
    ASSERT_EQ(nullptr, testSection->get_assignment("Test"));
}

TEST_F(DeletionTests, RemoveAssignmentFromSectionList){
    testSection->remove_assignment(testAssignment);
    ASSERT_TRUE(testSection->get_assignments()->empty());
}

TEST_F(DeletionTests, RemoveSectionFromCourseSearch){
    testCourse->remove_section(testSection);
    ASSERT_EQ(nullptr, testCourse->get_section("testSection"));
}

TEST_F(DeletionTests, RemoveSectionFromCourseList){
    testCourse->remove_section(testSection);
    ASSERT_TRUE(testCourse->get_sections()->empty());
}

TEST_F(DeletionTests, RemoveCourseFromControllerSearch){
    testControl->remove_course(testCourse);
    ASSERT_EQ(nullptr, testControl->get_course("testCourse", "Fall 2017"));
}

TEST_F(DeletionTests, RemoveCourseFromControllerList){
    testControl->remove_course(testCourse);
    ASSERT_TRUE(testControl->get_courses()->empty());
}

TEST_F(DeletionTests, RemoveAssignmentFromControllerSearch){
    testControl->remove_assignment(testAssignment);
    ASSERT_EQ(nullptr, testControl->get_assignment("Test"));
}

TEST_F(DeletionTests, RemoveAssignmentFromControllerList){
    testControl->remove_assignment(testAssignment);
    ASSERT_TRUE(testControl->get_assignments()->empty());
}

TEST_F(DeletionTests, RemoveAssignmentFromControllerAffectsSectionSearch){
    testControl->remove_assignment(testAssignment);
    ASSERT_EQ(nullptr, testSection->get_assignment("Test"));
}

TEST_F(DeletionTests,RemoveAssignmentFromControllerAffectsSectionList){
    testControl->remove_assignment(testAssignment);
    ASSERT_TRUE(testSection->get_assignments()->empty());
}

TEST_F(DeletionTests, RemoveAssignmentFromSectionAffectsControllerSearch){
    testSection->remove_assignment(testAssignment);
    ASSERT_EQ(nullptr, testControl->get_assignment("Test"));
}

TEST_F(DeletionTests, RemoveAssignmentFromSectionAffectsControllerList){
    testSection->remove_assignment(testAssignment);
    ASSERT_TRUE(testControl->get_assignments()->empty());
}






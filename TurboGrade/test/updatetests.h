#ifndef UPDATETESTS_H
#define UPDATETESTS_H

#include "gtest/gtest.h"
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

class UpdateTests : public ::testing::Test
{
protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    virtual ~UpdateTests();
    // You can do clean-up work that doesn't throw exceptions here.

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp();
    // Code here will be called immediately after the constructor (right
    // before each test).

    virtual void TearDown();
    // Code here will be called immediately after each test (right
    // before the destructor).

public:
    UpdateTests();

protected:
    Controller* testControl;
    Course* testCourse;
    Section* testSection;
    Assignment* testAssignment;
    Criterion* testCriterion;
    Student* testStudent;
    Rubric* testRubric;
    Submission* testSubmission;
    Comment* testComment;
};
#endif // UPDATETESTS_H

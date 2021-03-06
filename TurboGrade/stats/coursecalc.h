#ifndef COURSECALC_H
#define COURSECALC_H

#include "../db/gradedb.h"
#include "../db/rubricdb.h"
#include "../db/commentdb.h"
#include "../db/assignmentdb.h"
#include "../db/submissiondb.h"
#include "../db/sectiondb.h"
#include "../db/studentdb.h"
#include "../db/coursedb.h"
#include "../db/dbengine.h"

class CourseCalc
{
public:
    CourseCalc(Course *a);
    ~CourseCalc();
    Course *current;
    float getTotMean();
    float getTotal();
    float getNumber();
    float getAssignMean(Assignment *assign);
};

#endif // COURSECALC_H

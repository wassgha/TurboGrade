#ifndef CLASSCALC_H
#define CLASSCALC_H

#include "../db/gradedb.h"
#include "../db/rubricdb.h"
#include "../db/commentdb.h"
#include "../db/assignmentdb.h"
#include "../db/submissiondb.h"
#include "../db/sectiondb.h"
#include "../db/studentdb.h"
#include "../db/coursedb.h"
#include "../db/dbengine.h"

class ClassCalc
{
public:
    ClassCalc();
    ~ClassCalc();
    int getTotal(GradeDB x);
};

#endif // CLASSCALC_H

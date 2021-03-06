#ifndef SECTIONCALC_H
#define SECTIONCALC_H

#include "../db/gradedb.h"
#include "../db/rubricdb.h"
#include "../db/commentdb.h"
#include "../db/assignmentdb.h"
#include "../db/submissiondb.h"
#include "../db/sectiondb.h"
#include "../db/studentdb.h"
#include "../db/coursedb.h"
#include "../db/dbengine.h"

class SectionCalc
{
public:
    SectionCalc(Section *a);
    ~SectionCalc();
    Section *current;
    float getTotMean();
    float getTotal();
    float getNumber();
    float getAssignMean(Assignment *assign);
};

#endif // SECTIONCALC_H

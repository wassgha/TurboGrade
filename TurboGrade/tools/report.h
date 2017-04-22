#ifndef REPORT_H
#define REPORT_H

#include "jtemplate.h"
#include "../engine/controller.h"

class Report
{
public:
    Report();
    QString gen(Submission *submission);
};

#endif // REPORT_H

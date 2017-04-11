#ifndef STUDENTDELIVERABLE_H
#define STUDENTDELIVERABLE_H
#include "objectidentifier.h"
#include "../engine/controller.h"
#include <QString>
class StudentDeliverable : public ObjectIdentifier
{
public:
    StudentDeliverable();
    QString placeParameters(Submission *submission);
    void add_header(Submission *submission, QString& htmlString);
    void add_names(Submission *submission, QString& htmlString);
    void add_total_grade(Submission *submission, QString& htmlString);
    void add_comments(Submission *submission, QString& htmlString);
};

#endif // STUDENTDELIVERABLE_H

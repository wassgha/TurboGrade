#ifndef STUDENTDELIVERABLE_H
#define STUDENTDELIVERABLE_H
#include "objectidentifier.h"
#include "../engine/controller.h"
class StudentDeliverable : public ObjectIdentifier
{
public:
    StudentDeliverable();
    QString placeParameters(Submission *submission);
};

#endif // STUDENTDELIVERABLE_H

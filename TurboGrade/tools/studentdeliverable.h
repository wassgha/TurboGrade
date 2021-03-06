#ifndef STUDENTDELIVERABLE_H
#define STUDENTDELIVERABLE_H
#include "objectidentifier.h"
#include "../engine/controller.h"
#include <QString>
#include <QFile>
#include <iostream>

class StudentDeliverable : public ObjectIdentifier
{
public:
    StudentDeliverable();
    QString placeParameters(Submission *submission);
    void add_header(Submission *submission, QString& htmlString);
    void add_style(Submission *submission, QString& htmlString);
    void add_names(Submission *submission, QString& htmlString);
    void add_total_grade_sticker(Submission *submission, QString& htmlString);
    void add_total_grade(Submission *submission, QString& htmlString);
    void add_student_name(Submission *submission, QString& htmlString);
    void add_assignment_info(Submission *submission, QString& htmlString);
    void add_general_comments(Submission *submission, QString& htmlString);
    void add_grade_summary(Submission *submission, QString& htmlString);
    void add_detailed_remarks(Submission *submission, QString& htmlString);
    void add_code_lines(Submission *submission, Comment* comment, QString& htmlString, int linesBefore, int linesAfter);

    void add_comments(Submission *submission, QString& htmlString);
    void add_grades(Submission *submission, QString& htmlString);
    void add_image(Submission *submission, QString& htmlString);
};

#endif // STUDENTDELIVERABLE_H

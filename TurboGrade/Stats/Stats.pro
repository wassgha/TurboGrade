TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
QT += sql widgets printsupport

SOURCES += main.cpp \
    assignmentcalc.cpp \
    studentcalc.cpp \
    sectioncalc.cpp \
    classcalc.cpp

HEADERS += \
    assignmentcalc.h \
    studentcalc.h \
    sectioncalc.h \
    classcalc.h

SOURCES     += \
            "../tools/objectidentifier.cpp" \
            "../engine/controller.cpp" \
            "../engine/course.cpp" \
            "../engine/section.cpp" \
            "../engine/student.cpp" \
            "../engine/assignment.cpp" \
            "../engine/submission.cpp" \
            "../engine/rubric.cpp" \
            "../engine/criterion.cpp" \
            "../engine/comment.cpp" \
            "../db/dbengine.cpp" \
            "../db/coursedb.cpp" \
            "../db/sectiondb.cpp" \
            "../db/studentdb.cpp" \
            "../db/assignmentdb.cpp" \
            "../db/submissiondb.cpp" \
            "../db/rubricdb.cpp" \
            "../db/commentdb.cpp" \
            "../db/gradedb.cpp"

HEADERS     += \
            "../tools/macro.h" \
            "../tools/objectidentifier.h" \
            "../engine/controller.h" \
            "../engine/course.h" \
            "../engine/section.h" \
            "../engine/student.h" \
            "../engine/assignment.h" \
            "../engine/submission.h" \
            "../engine/rubric.h" \
            "../engine/criterion.h" \
            "../engine/comment.h" \
            "../db/dbengine.h" \
            "../db/coursedb.h" \
            "../db/sectiondb.h" \
            "../db/studentdb.h" \
            "../db/assignmentdb.h" \
            "../db/submissiondb.h" \
            "../db/rubricdb.h" \
            "../db/commentdb.h" \
            "../db/gradedb.h"

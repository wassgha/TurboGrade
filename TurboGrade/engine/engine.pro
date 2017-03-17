TEMPLATE    = app
CONFIG      += console c++11
CONFIG      -= app_bundle
QT          += sql widgets

SOURCES     += \
            "../db/dbengine.cpp" \
            "../db/coursedb.cpp" \
            "../db/sectiondb.cpp" \
            "../db/studentdb.cpp" \
            "../db/assignmentdb.cpp" \
            "../db/submissiondb.cpp" \
            "../db/rubricdb.cpp" \
            main.cpp \
            course.cpp \
            coursecontroller.cpp \
            section.cpp \
            student.cpp \
            assignmentcontroller.cpp \
            submission.cpp \
            assignment.cpp \
            rubric.cpp \
            criterion.cpp

HEADERS     += \
            "../db/dbengine.h" \
            "../db/coursedb.h" \
            "../db/sectiondb.h" \
            "../db/studentdb.h" \
            "../db/assignmentdb.h" \
            "../db/submissiondb.h" \
            "../db/rubricdb.h" \
            course.h \
            coursecontroller.h \
            section.h \
            student.h \
            assignmentcontroller.h \
            submission.h \
            assignment.h \
            rubric.h \
            criterion.h

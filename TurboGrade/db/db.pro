TEMPLATE    = app
CONFIG      += console c++11
CONFIG      -= app_bundle
QT          += sql widgets

SOURCES     += \
            main.cpp \
            dbengine.cpp \
            "../engine/controller.cpp" \
            "../engine/course.cpp" \
            "../engine/section.cpp" \
            "../engine/student.cpp" \
            "../engine/assignment.cpp" \
            "../engine/submission.cpp" \
            "../engine/rubric.cpp" \
            "../engine/criterion.cpp" \
            coursedb.cpp \
            sectiondb.cpp \
            studentdb.cpp \
            assignmentdb.cpp \
            submissiondb.cpp \
            rubricdb.cpp

HEADERS     += \
            dbengine.h \
            "../engine/controller.h" \
            "../engine/course.h" \
            "../engine/section.h" \
            "../engine/student.h" \
            "../engine/assignment.h" \
            "../engine/submission.h" \
            "../engine/rubric.h" \
            "../engine/criterion.h" \
            coursedb.h \
            sectiondb.h \
            studentdb.h \
            assignmentdb.h \
            submissiondb.h \
            rubricdb.h

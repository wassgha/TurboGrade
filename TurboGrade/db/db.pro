TEMPLATE    = app
CONFIG      += console c++11
CONFIG      -= app_bundle
QT          += sql widgets

SOURCES     += \
            main.cpp \
            dbengine.cpp \
            "../engine/coursecontroller.cpp" \
            "../engine/course.cpp" \
            "../engine/section.cpp" \
            "../engine/student.cpp" \
            "../engine/assignmentcontroller.cpp" \
            "../engine/assignment.cpp" \
            "../engine/submission.cpp" \
            coursedb.cpp \
            sectiondb.cpp \
            studentdb.cpp \
    assignmentdb.cpp \
    submissiondb.cpp

HEADERS     += \
            dbengine.h \
            "../engine/coursecontroller.h" \
            "../engine/course.h" \
            "../engine/section.h" \
            "../engine/student.h" \
            "../engine/assignmentcontroller.h" \
            "../engine/assignment.h" \
            "../engine/submission.h" \
            coursedb.h \
            sectiondb.h \
            studentdb.h \
    assignmentdb.h \
    submissiondb.h

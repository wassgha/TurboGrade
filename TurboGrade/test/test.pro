TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QT          += sql widgets printsupport

LIBS += -pthread

SOURCES += main.cpp                                        \
        ../tools/gtest/googletest/src/gtest-all.cc \
    testingtemplate.cpp \
    filewritertest.cpp  \
    ../tools/objectidentifier.cpp \
    ../tools/filewriter.cpp \

INCLUDEPATH +=  ../tools/gtest                             \
                ../tools/gtest/googletest                  \
                ../tools/gtest/googletest/include          \
                ../tools/gtest/googletest/include/gtest

HEADERS += \
    testingtemplate.h \
    filewritertest.h \
    ../tools/objectidentifier.h \
    ../tools/filewriter.h \

SOURCES     += \
            "../db/dbengine.cpp" \
            "../db/coursedb.cpp" \
            "../db/sectiondb.cpp" \
            "../db/studentdb.cpp" \
            "../db/assignmentdb.cpp" \
            "../db/submissiondb.cpp" \
            "../db/rubricdb.cpp" \
            "../db/commentdb.cpp" \
            "../db/gradedb.cpp" \
            "../engine/course.cpp" \
            "../engine/section.cpp" \
            "../engine/student.cpp" \
            "../engine/submission.cpp" \
            "../engine/assignment.cpp" \
            "../engine/rubric.cpp" \
            "../engine/criterion.cpp" \
            "../engine/controller.cpp" \
            "../engine/comment.cpp"

HEADERS     += \
            "../tools/macro.h" \
            "../db/dbengine.h" \
            "../db/coursedb.h" \
            "../db/sectiondb.h" \
            "../db/studentdb.h" \
            "../db/assignmentdb.h" \
            "../db/submissiondb.h" \
            "../db/rubricdb.h" \
            "../db/commentdb.h" \
            "../db/gradedb.h" \
            "../engine/course.h" \
            "../engine/section.h" \
            "../engine/student.h" \
            "../engine/submission.h" \
            "../engine/assignment.h" \
            "../engine/rubric.h" \
            "../engine/criterion.h" \
            "../engine/controller.h" \
            "../engine/comment.h"

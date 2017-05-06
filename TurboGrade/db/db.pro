TEMPLATE    = app
CONFIG      += console c++11
CONFIG      -= app_bundle
QT          += sql widgets printsupport script

unix:!ios {
    QT += webenginewidgets
}

SOURCES     += \
            "../tools/objectidentifier.cpp" \
            "../tools/gitmodule.cpp" \
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
            "../engine/comment.cpp" \
            coursedb.cpp \
            sectiondb.cpp \
            studentdb.cpp \
            assignmentdb.cpp \
            submissiondb.cpp \
            rubricdb.cpp \
            commentdb.cpp \
            gradedb.cpp

HEADERS     += \
            "../tools/macro.h" \
            "../tools/objectidentifier.h" \
            "../tools/gitmodule.h" \
            dbengine.h \
            "../engine/controller.h" \
            "../engine/course.h" \
            "../engine/section.h" \
            "../engine/student.h" \
            "../engine/assignment.h" \
            "../engine/submission.h" \
            "../engine/rubric.h" \
            "../engine/criterion.h" \
            "../engine/comment.h" \
            coursedb.h \
            sectiondb.h \
            studentdb.h \
            assignmentdb.h \
            submissiondb.h \
            rubricdb.h \
            commentdb.h \
            gradedb.h

TEMPLATE    = app
CONFIG      += console c++11
CONFIG      -= app_bundle
QT          += sql widgets printsupport script

unix:!ios {
    QT += webenginewidgets
}

SOURCES     += \
            "../tools/objectidentifier.cpp" \
            "../db/dbengine.cpp" \
            "../db/coursedb.cpp" \
            "../db/sectiondb.cpp" \
            "../db/studentdb.cpp" \
            "../db/assignmentdb.cpp" \
            "../db/submissiondb.cpp" \
            "../db/rubricdb.cpp" \
            "../db/commentdb.cpp" \
            "../db/gradedb.cpp" \
            "../tools/dirtools.cpp" \
            "../tools/gitmodule.cpp" \
            main.cpp \
            course.cpp \
            section.cpp \
            student.cpp \
            submission.cpp \
            assignment.cpp \
            rubric.cpp \
            criterion.cpp \
            controller.cpp \
            comment.cpp

HEADERS     += \
            "../tools/macro.h" \
            "../tools/objectidentifier.h" \
            "../tools/dirtools.h" \
            "../tools/gitmodule.h" \
            "../db/dbengine.h" \
            "../db/coursedb.h" \
            "../db/sectiondb.h" \
            "../db/studentdb.h" \
            "../db/assignmentdb.h" \
            "../db/submissiondb.h" \
            "../db/rubricdb.h" \
            "../db/commentdb.h" \
            "../db/gradedb.h" \
            course.h \
            section.h \
            student.h \
            submission.h \
            assignment.h \
            rubric.h \
            criterion.h \
            controller.h \
            comment.h

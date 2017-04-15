TEMPLATE    = app
CONFIG      += console c++11
CONFIG      -= app_bundle
QT          += sql widgets printsupport network webenginewidgets

SOURCES     +=  main.cpp \
                syntaxhighlight.cpp \
                codeeditor.cpp \
                objectidentifier.cpp \
                filewriter.cpp \
    htmltopdf.cpp \
    dirtools.cpp \
    macadress.cpp \
    csvgenerator.cpp \
            "../db/dbengine.cpp" \
            "../db/coursedb.cpp" \
            "../db/sectiondb.cpp" \
            "../db/studentdb.cpp" \
            "../db/assignmentdb.cpp" \
            "../db/submissiondb.cpp" \
            "../db/rubricdb.cpp" \
            "../db/commentdb.cpp" \
            "../db/gradedb.cpp" \
            "../engine/controller.cpp" \
            "../engine/course.cpp" \
            "../engine/section.cpp" \
            "../engine/student.cpp" \
            "../engine/assignment.cpp" \
            "../engine/submission.cpp" \
            "../engine/rubric.cpp" \
            "../engine/criterion.cpp" \
            "../engine/comment.cpp" \
            studentdeliverable.cpp


HEADERS     += \
                syntaxhighlight.h \
                codeeditor.h \
                objectidentifier.h \
                macro.h \
                filewriter.h \
    htmltopdf.h \
    dirtools.h \
    macadress.h \
    csvgenerator.h \
            "../engine/controller.h" \
            "../engine/course.h" \
            "../engine/section.h" \
            "../engine/student.h" \
            "../engine/assignment.h" \
            "../engine/submission.h" \
            "../engine/rubric.h" \
            "../engine/criterion.h" \
            "../engine/comment.h" \
            studentdeliverable.h

FORMS +=

DISTFILES +=

RESOURCES += \
    report.qrc

#-------------------------------------------------
#
# Project created by QtCreator 2017-03-13T14:22:13
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ui
TEMPLATE = app
CONFIG      += console c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
            "../tools/objectidentifier.cpp" \
        "../tools/syntaxhighlight.cpp"\
        "../tools/codeeditor.cpp" \
            "../db/dbengine.cpp" \
            "../db/coursedb.cpp" \
            "../db/sectiondb.cpp" \
            "../db/studentdb.cpp" \
            "../db/assignmentdb.cpp" \
            "../db/submissiondb.cpp" \
            "../db/rubricdb.cpp" \
            "../db/commentdb.cpp" \
            "../engine/controller.cpp" \
            "../engine/course.cpp" \
            "../engine/section.cpp" \
            "../engine/student.cpp" \
            "../engine/assignment.cpp" \
            "../engine/submission.cpp" \
            "../engine/rubric.cpp" \
            "../engine/criterion.cpp" \
            "../engine/comment.cpp" \
    commentpopup.cpp \
    gradesubmission.cpp \
    codeview.cpp \
    gradeview.cpp \
    dashboard.cpp \
    card.cpp \
    cardsview.cpp \
    adddialog.cpp \
    clickablelabel.cpp

HEADERS  +=\
        "../tools/syntaxhighlight.h"\
        "../tools/codeeditor.h" \
            "../tools/macro.h" \
            "../tools/objectidentifier.h" \
            "../db/dbengine.h" \
            "../db/coursedb.h" \
            "../db/sectiondb.h" \
            "../db/studentdb.h" \
            "../db/assignmentdb.h" \
            "../db/submissiondb.h" \
            "../db/rubricdb.h" \
            "../db/commentdb.h" \
            "../engine/controller.h" \
            "../engine/course.h" \
            "../engine/section.h" \
            "../engine/student.h" \
            "../engine/assignment.h" \
            "../engine/submission.h" \
            "../engine/rubric.h" \
            "../engine/criterion.h" \
            "../engine/comment.h" \
    commentpopup.h \
    gradesubmission.h \
    codeview.h \
    gradeview.h \
    dashboard.h \
    card.h \
    cardsview.h \
    adddialog.h \
    courseview.h \
    sectionview.h \
    assignmentview.h \
    clickablelabel.h

FORMS    += \
    commentpopup.ui \
    gradesubmission.ui \
    codeview.ui \
    gradeview.ui \
    dashboard.ui \
    card.ui \
    cardsview.ui \
    adddialog.ui

RESOURCES += \
    resources.qrc

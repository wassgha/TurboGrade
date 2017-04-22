#-------------------------------------------------
#
# Project created by QtCreator 2017-03-13T14:22:13
#
#-------------------------------------------------

QT       += core gui sql printsupport script
QT          += sql widgets printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TurboGrade
VERSION = 1.0.0
TEMPLATE = app
CONFIG      += console c++11

ICON = turbograde.icns

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
        "../tools/dirtools.cpp" \
        "../tools/csvgenerator.cpp" \
        "../tools/filewriter.cpp" \
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
    commentpopup.cpp \
    gradesubmission.cpp \
    codeview.cpp \
    gradeview.cpp \
    dashboard.cpp \
    card.cpp \
    cardsview.cpp \
    clickablelabel.cpp \
    breadcrumb.cpp \
    courseview.cpp \
    sectionview.cpp \
    assignmentview.cpp \
    listview.cpp \
    studentview.cpp \
    switcher.cpp \
    formdialog.cpp \
    rubricview.cpp \
    submissionview.cpp \
    commentcard.cpp \
    criterionitem.cpp \
    criteriongradecard.cpp \
    criteriondialog.cpp \
    criterionguidedialog.cpp

HEADERS  +=\
            "../tools/syntaxhighlight.h"\
            "../tools/codeeditor.h" \
            "../tools/macro.h" \
            "../tools/objectidentifier.h" \
            "../tools/dirtools.h" \
            "../tools/csvgenerator.h" \
            "../tools/filewriter.h" \
            "../db/dbengine.h" \
            "../db/coursedb.h" \
            "../db/sectiondb.h" \
            "../db/studentdb.h" \
            "../db/assignmentdb.h" \
            "../db/submissiondb.h" \
            "../db/rubricdb.h" \
            "../db/commentdb.h" \
            "../db/gradedb.h" \
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
    courseview.h \
    sectionview.h \
    assignmentview.h \
    clickablelabel.h \
    breadcrumb.h \
    listview.h \
    studentview.h \
    switcher.h \
    formdialog.h \
    rubricview.h \
    submissionview.h \
    commentcard.h \
    criterionitem.h \
    criteriongradecard.h \
    criteriondialog.h \
    criterionguidedialog.h

FORMS    += \
    commentpopup.ui \
    gradesubmission.ui \
    codeview.ui \
    gradeview.ui \
    dashboard.ui \
    card.ui \
    cardsview.ui \
    breadcrumb.ui \
    listview.ui \
    formdialog.ui \
    rubricview.ui \
    commentcard.ui \
    criterionitem.ui \
    criteriongradecard.ui \
    criteriondialog.ui \
    criterionguidedialog.ui

RESOURCES += \
    resources.qrc

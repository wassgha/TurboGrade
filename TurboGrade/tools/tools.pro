TEMPLATE    = app
CONFIG      += console c++11
CONFIG      -= app_bundle
QT          += widgets printsupport

SOURCES     +=  main.cpp \
                syntaxhighlight.cpp \
                codeeditor.cpp \
                objectidentifier.cpp \
                filewriter.cpp \
    pdfwindow.cpp \
    htmltopdf.cpp

HEADERS     += \
                syntaxhighlight.h \
                codeeditor.h \
                objectidentifier.h \
                macro.h \
                filewriter.h \
    pdfwindow.h \
    htmltopdf.h

FORMS += \
    pdfwindow.ui

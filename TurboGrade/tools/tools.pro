TEMPLATE    = app
CONFIG      += console c++11
CONFIG      -= app_bundle
QT          += widgets

SOURCES     +=  main.cpp \
                syntaxhighlight.cpp \
                codeeditor.cpp \
    objectidentifier.cpp

HEADERS     += \
               syntaxhighlight.h \
               codeeditor.h \
    objectidentifier.h \
    macro.h

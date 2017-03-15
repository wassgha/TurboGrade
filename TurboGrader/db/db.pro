TEMPLATE    = app
CONFIG      += console c++11
CONFIG      -= app_bundle
QT          += sql widgets

SOURCES += main.cpp \
    classdb.cpp \
    dbengine.cpp

HEADERS += \
    classdb.h \
    dbengine.h

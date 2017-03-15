TEMPLATE    = app
CONFIG      += console c++11
CONFIG      -= app_bundle
QT          += sql widgets

SOURCES += main.cpp \
    "../db/dbengine.cpp" \
    submission.cpp

HEADERS += \
    "../db/dbengine.h" \
    submission.h

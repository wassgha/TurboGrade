TEMPLATE    = app
CONFIG      += console c++11
CONFIG      -= app_bundle
QT          += sql widgets

SOURCES += \
    "../db/dbengine.cpp" \
    "../db/classdb.cpp" \
    main.cpp \
    submission.cpp

HEADERS += \
    "../db/dbengine.h" \
    "../db/classdb.h" \
    submission.h

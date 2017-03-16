TEMPLATE    = app
CONFIG      += console c++11
CONFIG      -= app_bundle
QT          += sql widgets

SOURCES += \
    "../db/dbengine.cpp" \
    "../db/coursedb.cpp" \
    "../db/sectiondb.cpp" \
    main.cpp \
    course.cpp \
    coursecontroller.cpp \
    section.cpp

HEADERS += \
    "../db/dbengine.h" \
    "../db/coursedb.h" \
    "../db/sectiondb.h" \
    course.h \
    coursecontroller.h \
    section.h

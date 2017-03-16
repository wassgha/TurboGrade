TEMPLATE    = app
CONFIG      += console c++11
CONFIG      -= app_bundle
QT          += sql widgets

SOURCES += \
    main.cpp \
    dbengine.cpp \
    "../engine/coursecontroller.cpp" \
    "../engine/course.cpp" \
    "../engine/section.cpp" \
    coursedb.cpp \
    sectiondb.cpp

HEADERS += \
    dbengine.h \
    "../engine/coursecontroller.h" \
    "../engine/course.h" \
    "../engine/section.h" \
    coursedb.h \
    sectiondb.h

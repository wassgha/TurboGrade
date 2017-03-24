TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -pthread

SOURCES += main.cpp                                        \
        ../tools/gtest/googletest/src/gtest-all.cc \
    testingtemplate.cpp \
    filewritertest.cpp  \
    ../tools/objectidentifier.cpp \
    ../tools/filewriter.cpp \

INCLUDEPATH +=  ../tools/gtest                             \
                ../tools/gtest/googletest                  \
                ../tools/gtest/googletest/include          \
                ../tools/gtest/googletest/include/gtest

HEADERS += \
    testingtemplate.h \
    filewritertest.h \
    ../tools/objectidentifier.h \
    ../tools/filewriter.h \

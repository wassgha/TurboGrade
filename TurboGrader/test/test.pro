TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -pthread

SOURCES += main.cpp                                        \
        ../tools/gtest/googletest/src/gtest-all.cc

INCLUDEPATH +=  ../tools/gtest                             \
                ../tools/gtest/googletest                  \
                ../tools/gtest/googletest/include          \
                ../tools/gtest/googletest/include/gtest

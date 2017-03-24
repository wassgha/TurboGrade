#ifndef FILEWRITERTEST_H
#define FILEWRITERTEST_H
#include "gtest/gtest.h"
#include "../tools/filewriter.h"

class FileWriterTest: public ::testing::Test
{
public:
    FileWriterTest();

protected:
    // You can remove any or all of the following functions if its body
    // is empty.
    virtual ~FileWriterTest();
    // You can do clean-up work that doesn't throw exceptions here.

    // If the constructor and destructor are not enough for setting up
    // and cleaning up each test, you can define the following methods:

    virtual void SetUp(){}
    // Code here will be called immediately after the constructor (right
    // before each test).

    virtual void TearDown(){}
    // Code here will be called immediately after each test (right
    // before the destructor).
};

#endif // FILEWRITERTEST_H

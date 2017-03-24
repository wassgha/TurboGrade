#include "filewritertest.h"

FileWriterTest::FileWriterTest()
{

}

FileWriterTest::~FileWriterTest(){

}

TEST_F(FileWriterTest, TestOpens){
    FileWriter out("csvtest1.txt");
    ASSERT_TRUE(out.is_open());
}

TEST_F(FileWriterTest, TestReOpens){
    FileWriter out("csvtest1.txt");
    out.open("csvtest2.txt");
    ASSERT_TRUE(out.is_open());
}

TEST_F(FileWriterTest, TestNotOpenWriteNoThrow){
     FileWriter out("csvtest1.txt");
     out.close();
     ASSERT_NO_THROW (out << "Hello");
     ASSERT_NO_FATAL_FAILURE (out << "Hello2");
}

TEST_F(FileWriterTest, TestWriteInt){
    FileWriter out("csvtest1.txt");
    ASSERT_NO_FATAL_FAILURE(out << 1);
    ASSERT_NO_THROW(out << 1);
}

TEST_F(FileWriterTest, TestWriteDouble){
    FileWriter out("csvtest1.txt");
    ASSERT_NO_FATAL_FAILURE(out << 1.0);
    ASSERT_NO_THROW(out << 1.0);
}


TEST_F(FileWriterTest, TestWriteFloat){
    FileWriter out("csvtest1.txt");
    ASSERT_NO_FATAL_FAILURE(out << 1.0f);
    ASSERT_NO_THROW(out << 1.0f);
}

TEST_F(FileWriterTest, TestWriteBool){
    FileWriter out("csvtest1.txt");
    ASSERT_NO_FATAL_FAILURE(out << true);
    ASSERT_NO_THROW(out << true);
}

TEST_F(FileWriterTest, TestExampleCSV){
    FileWriter out("csvtest2.txt");
    out << "n,f1,f2,f3\n";
    out << 1 << "," << 100 << "," << 10 << "," << 15;
}

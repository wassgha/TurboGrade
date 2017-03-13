#include "testingtemplate.h"

TestingTemplate::TestingTemplate()
{

}

TestingTemplate::~TestingTemplate(){

}

void TestingTemplate::SetUp(){

}

void TestingTemplate::TearDown(){

}

/*TEST_F(TestingTemplate, RemoveLeafLeftD){
    BinaryTree<double> btree;
    btree.insert(5);
    btree.insert(7);
    btree.insert(3);
    btree.remove(3);
    ASSERT_FALSE(btree.empty());
    ASSERT_EQ(2,btree.size());
    ASSERT_TRUE(btree.contains(5));
    ASSERT_TRUE(btree.contains(7));
    ASSERT_FALSE(btree.contains(3));
}*/

#include <iostream>
#include "../db/classdb.h"

using namespace std;

int main(int argc, char *argv[])
{
    ClassDB classdb;
//    classdb.add("CS 105");
//    classdb.add("CS 150");
    cout << "CS 150 has ID " << classdb.select("CS 150") << endl;
    return 0;
}

#include "student.h"

Student::Student()
{
    std::cerr<<"Please provide student name.";
    exit(0);
}

Student::Student(QString name)
{
    _name = name;
}

Student::~Student()
{

}

#include "sectioncalc.h"
#include "studentcalc.h"

SectionCalc::SectionCalc(Section *a)
{
    current = a;
}

SectionCalc::~SectionCalc()
{

}

float SectionCalc::getTotMean()
{
    float total = this->getTotal();
    float number = this->getNumber();
    if(number<1)
    {
        return 0;
    }
    float mean = total/number;
    return mean;
}

float SectionCalc::getTotal()
{
    float total = 0;
    std::vector<Student*> *currentStudents = current->get_students();
    for(int i = 0; i<int(currentStudents->size()); i++)
    {
        Student *studentpoint = currentStudents->at(i);
        StudentCalc thisStudentCalc(studentpoint);
        total = total + thisStudentCalc.getMean();
    }
    return total;
}

float SectionCalc::getNumber()
{
    return current->get_students()->size();
}

float SectionCalc::getAssignMean(Assignment *assign)
{
    return 0;
}

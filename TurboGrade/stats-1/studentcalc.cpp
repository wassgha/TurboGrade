#include "studentcalc.h"

StudentCalc::StudentCalc(Student *a)
{

    current = a;
}

StudentCalc::~StudentCalc()
{

}

float StudentCalc::getMean()
{
    float total = 0;
    float mean = 0;
    std::vector<Submission*> *currentSubs = current->get_submissions();
    for(int i = 0; i<int(currentSubs->size()); i++)
    {
        total = total + currentSubs->at(i)->get_grade();
    }
    if(int(currentSubs->size()) < 0)
    {
        mean = total/currentSubs->size();
    }
    return mean;
}

float StudentCalc::getTotal()
{
    float total = 0;
    std::vector<Submission*> *currentSubs = current->get_submissions();
    for(int i = 0; i<int(currentSubs->size()); i++)
    {
        total = total + currentSubs->at(i)->get_grade();
    }
    return total;
}


#include "coursecalc.h"
#include "sectioncalc.h"

CourseCalc::CourseCalc(Course *a)
{
    current = a;
}

CourseCalc::~CourseCalc()
{

}

float CourseCalc::getTotMean()
{
    float total = 0;
    float mean = 0;
    std::vector<Section*> *currentSections = current->get_sections();
    for(int i = 0; i<int(currentSections->size()); i++)
    {
        Section *sectionpoint = currentSections->at(i);
        SectionCalc thisSectionCalc(sectionpoint);
        total = total + thisSectionCalc.getTotMean();
    }
    if(int(currentSections->size()) < 0)
    {
        mean = total/currentSections->size();
    }
    return mean;
}

float CourseCalc::getAssignMean(Assignment *assign)
{

}



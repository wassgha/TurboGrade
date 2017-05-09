#include "coursecalc.h"
#include "sectioncalc.h"

CourseCalc::CourseCalc(Course *a)
{
    current = a;
}

CourseCalc::~CourseCalc()
{

}

float CourseCalc::getTotal()
{
    float total = 0;
    std::vector<Section*> *currentSections = current->get_sections();
    for(int i = 0; i<int(currentSections->size()); i++)
    {
        Section *sectionpoint = currentSections->at(i);
        SectionCalc thisSectionCalc(sectionpoint);
        total = total + thisSectionCalc.getTotal();
    }
    return total;
}

float CourseCalc::getTotMean()
{
    return (this->getTotal()/this->getNumber());
}

float CourseCalc::getNumber()
{
    float total = 0;
    std::vector<Section*> *currentSections = current->get_sections();
    for(int i = 0; i<int(currentSections->size()); i++)
    {
        Section *sectionpoint = currentSections->at(i);
        SectionCalc thisSectionCalc(sectionpoint);
        total = total + thisSectionCalc.getNumber();
    }
    return total;
}


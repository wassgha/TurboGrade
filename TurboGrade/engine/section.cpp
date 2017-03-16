#include "section.h"

Section::Section()
{
    std::cerr<<"Please provide section name.";
    exit(0);
}

Section::Section(QString name)
{
    _name = name;
}

Section::~Section()
{

}

#ifndef SECTION_H
#define SECTION_H

#include <iostream>
#include <vector>
#include <QString>

class Section
{
public:
    // Constructor
    Section();
    // Parametrized constructor
    Section(QString name);
    // Destructor
    ~Section();
    // Section name
    QString _name;
};

#endif // SECTION_H

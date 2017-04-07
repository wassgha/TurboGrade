#ifndef CSVGENERATOR_H
#define CSVGENERATOR_H
#include "../engine/controller.h"
#include "filewriter.h"
#include <iostream>

class CSVGenerator : public ObjectIdentifier
{
public:
    CSVGenerator();

    static void printProfessor(Section *section, Assignment *assignment,
                               QString filepath);
};

#endif // CSVGENERATOR_H

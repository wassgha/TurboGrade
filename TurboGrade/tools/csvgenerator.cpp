#include "csvgenerator.h"

CSVGenerator::CSVGenerator()
{

}

void CSVGenerator::printProfessor(Section *section, Assignment *assignment, QString filepath){
    FileWriter h(filepath.toStdString());
    std::string criteria ="";
    for(Criterion *crit: *assignment->_rubric->_criteria){
        criteria.append(crit->to_string());
        criteria.append(",");
    }
    std::string header = "Student,";
    header.append(criteria);
    std::cerr << header;
}

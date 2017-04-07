#include "csvgenerator.h"

CSVGenerator::CSVGenerator()
{

}
/**
 * @brief CSVGenerator::printProfessor prints the professor's csv file.
 * The format of the header is :
 * Student, sub1c1, sub2c1, C1, C2, subsub1c3, sub1c3, ... , INSTRUCTOR COMMENTS
 * Where sub1c1 is a subcriteria of C1, subsub1c3 is a sub criteria of the sub
 * criteria of C3...
 * @param section The section to pull the students from
 * @param assignment The assignment to pull the rubric from
 * @param filepath The filepath to print the csv file
 */
void CSVGenerator::printProfessor(Section *section, Assignment *assignment, QString filepath){
    FileWriter h(filepath.toStdString());
    std::string criteria ="";
    for(Criterion *crit: *assignment->_rubric->_criteria){
        criteria.append(crit->in_order_names());
        criteria.append(", ");
    }
    std::string header = "Student, ";
    header.append(criteria);
    header.append("Instructor Comments");
    std::cerr << header;
}

#include "csvgenerator.h"

CSVGenerator::CSVGenerator()
{

}
/**
 * @brief CSVGenerator::printProfessor prints the professor's csv file.
 * The format of the header is :
 * Student, sub1c1, sub2c1, C1, C2, subsub1c3, sub1c3, ... , TOTAL,INSTRUCTOR COMMENTS
 * Where sub1c1 is a subcriteria of C1, subsub1c3 is a sub criteria of the sub
 * criteria of C3...
 * @param section The section to pull the students from
 * @param assignment The assignment to pull the rubric from
 * @param filepath The filepath to print the csv file
 */
void CSVGenerator::printProfessor(Section *section, Assignment *assignment, QString filepath){
    FileWriter h(filepath.toStdString());
    std::string body = "";
    std::string criteria ="";
    for(Criterion *crit: *assignment->_rubric->_criteria){
        criteria.append(crit->in_order_names().toStdString());
        criteria.append(", ");
    }
    std::string header = "Student, ";
    header.append(criteria);
    header.append("Total, ");
    header.append("Instructor Comments");
    std::cout << header;
    body.append(header);
    body.append("\n");
    for(Student *stud : *section->_students){
        std::string line = stud->_name.toStdString();
        std::cout<<"\nAnalyzing student: "<<line<<std::endl;
        line.append(", ");
        Submission *sub = stud->get_submission(assignment);
        for(Criterion *crit: *assignment->_rubric->_criteria){
            std::cout << crit->_name.toStdString();
            for(Criterion *subcriterion: *crit->_sub_criteria){
                std::cout << subcriterion->_name.toStdString();
                if(sub == nullptr){
                    line.append("N/A");
                } else {
                    int grade = sub->get_grade(subcriterion);
                    line.append(std::to_string(grade));
                }
                line.append(", ");
            }
            if(sub == nullptr){
                line.append("N/A");
            } else {
                int grade = sub->get_grade(crit);
                line.append(std::to_string(grade));
            }
            line.append(", ");
        }
        if(sub == nullptr){
            line.append("N/A");
        } else {
            line.append(std::to_string(sub->get_grade()));
            line.append(", ");
        }
        if(sub == nullptr){
        } else {
            std::string commentString = "\"";
            for(Comment *comment : *sub->_comments){
                commentString.append(comment->_text.toStdString());
                if(comment != sub->_comments->back()){
                    commentString.append("\n");
                }
            }
            commentString.append("\"");
            line.append(commentString);
        }
        std::cout << line << std::endl;
        body.append(line);
        body.append("\n");
    }
    h << body;
    h.close();
}


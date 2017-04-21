#include "studentdeliverable.h"

StudentDeliverable::StudentDeliverable()
{

}

QString StudentDeliverable::placeParameters(Submission *submission){
    if(submission == nullptr){
        return "";
    }
    QString htmlString ="";
    htmlString.append("\n<!DOCTYPE html>");
    htmlString.append("\n<html>");
    htmlString.append("\n   <head>");
    htmlString.append("\n   <meta charset=\"utf-8\">");
    add_header(submission, htmlString);
    add_style(submission, htmlString);
    htmlString.append("\n</head>");
    htmlString.append("\n<body>");
    add_names(submission, htmlString);
    add_total_grade_sticker(submission, htmlString);
    add_general_comments(submission, htmlString);
    htmlString.append("\n    <div id = \"container\">");
    add_assignment_obj(submission, htmlString);
    add_grade_summary(submission, htmlString);
    add_detailed_remarks(submission, htmlString);
    add_image(submission, htmlString);
    htmlString.append(                "\n  </div>");
    htmlString.append("\n</body>");
    htmlString.append("\n</html>");
    std::cout << htmlString.toStdString() << "\n";
    return htmlString;
}

void StudentDeliverable::add_image(Submission *submission, QString &htmlString){
    htmlString.append(
                "\n    <div id = \"logo\" >"
                "\n      Powered by <img src = \"qrc:///css/report/logo.png\" />"
                "\n    </div>"
                "\n    <div class=\"clear\"></div>");
}

void StudentDeliverable::add_header(Submission *submission, QString &htmlString){
    htmlString.append("\n   <title>Student report : ");
    htmlString.append(submission->_student->_name);
    htmlString.append("</title>");
}

void StudentDeliverable::add_style(Submission *submission, QString &htmlString){
    htmlString.append("<link href=\"qrc:///css/report/style.css\" rel=\"stylesheet\" type=\"text/css\" />");
}

void StudentDeliverable::add_names(Submission *submission, QString &htmlString){
    htmlString.append(
                "\n  <div id = \"document\">"
                "\n    <div id = \"info\">");
    htmlString.append(submission->_student->_name);
    htmlString.append("<br>"
                      "\n      <div id = \"assignment-name\">"
                      "        Assignment :\"");
    htmlString.append(submission->_assignment->_name);
    htmlString.append(
                "\"      </div>"
                "\n    </div>");
}

void StudentDeliverable::add_total_grade_sticker(Submission *submission, QString &htmlString){
    htmlString.append(
                "\n    <div id = \"grade\">"
                "\n      <div id = \"label\">"
                "\n        TOTAL GRADE"
                "\n      </div>\n      "
                );
    htmlString.append(QString(std::to_string(submission->get_grade()).c_str()));
    htmlString.append(
                "\n    </div>"
                "\n     <div class=\"clear\"></div>"
                );
}

void StudentDeliverable::add_comments(Submission* submission, QString &htmlString){
    htmlString.append(  "\n    <div class=\"clear\"></div>");
    for(Comment *comment:*submission->_comments){
        htmlString.append(
                    "\n    <div class = \"comment\">");
        htmlString.append(
                    "\n      <div class = \"title\">");
        htmlString.append(comment->_criterion->_name);
        htmlString.append("\n</div>"
                          "\n       <p>");
        htmlString.append(comment->_text);
        htmlString.append("\n      </p>"
                          "\n    </div>");
    }
}

void StudentDeliverable::add_assignment_obj(Submission *submission, QString &htmlString){
    htmlString.append(
                "\n        <h2>Assignment Objective</h2>"
                "\n        <p>");
    htmlString.append(submission->_assignment->_objective);
    htmlString.append(
                "\n        </p>");
}

void StudentDeliverable::add_grades(Submission *submission, QString &htmlString){
    for(Criterion *criterion : *submission->_assignment->_rubric->_criteria){
        htmlString.append(
                    "\n        <div class = \"criterion\">"
                    "\n            <div class = \"name\">"
                    "\n                ");
        htmlString.append(criterion->_name);
        htmlString.append("<span class = \"grade\">");
        htmlString.append(QString(std::to_string(submission->get_grade(criterion)).c_str()));
        htmlString.append("</span><span class = \"out-of\">/");
        htmlString.append(QString(std::to_string(criterion->_out_of).c_str()));
        htmlString.append("</span>"
                          "\n            </div>");
        if(criterion->has_children()){
            htmlString.append(
                        "\n            <ul>");
            for(Criterion *subcriterion : criterion->children()){
                htmlString.append("\n                <li>"
                                  "\n                    ");
                htmlString.append(subcriterion->_name);
                htmlString.append(" : <span class = \"grade\">");
                htmlString.append(std::to_string(submission->get_grade(subcriterion)).c_str());
                htmlString.append("</span><span class = \"out-of\"> out of ");
                htmlString.append(std::to_string(subcriterion->_out_of).c_str());
                htmlString.append("</span>"
                                  "\n                </li>");
                htmlString.append(
                            "\n        </div>");
            }
            htmlString.append(
                        "\n            </ul>");
        }
        htmlString.append(
                    "\n        </div>");
    }
}

void StudentDeliverable::add_general_comments(Submission *submission, QString &htmlString){
    htmlString.append(
                "\n    <div class = \"comment\">"
                "\n        <div class = \"title\"> General Comments </div>"
                "\n        <p>"
                "\n         You did well on this assignment, beware of commenting and documentation."
                "\n        </p>"
                "\n    </div>");

}

void StudentDeliverable::add_detailed_remarks(Submission *submission, QString &htmlString){
    htmlString.append("\n      <h2>Detailed remarks</h2>");
    htmlString.append("\n      <div class = \"criterion comments\">");
    for(Criterion *criterion : *submission->_assignment->_rubric->_criteria){
        htmlString.append("\n          <div class = \"name\">");
        htmlString.append(criterion->_name);
        htmlString.append("\n              <span class = \"grade\">");
        htmlString.append(std::to_string(submission->get_grade(criterion)).c_str());
        htmlString.append("</span><span class = \"out-of\">/");
        htmlString.append(std::to_string(criterion->_out_of).c_str());
        htmlString.append("</span>"
                          "\n          </div>");
        std::vector<Comment *> comments = submission->get_comments(criterion);
        if(comments.empty()){
        } else {
            for(Comment *comment : comments){
                add_code_lines(submission, comment, htmlString, 2, 2);
            }
        }
        for(Criterion *sub_criterion: *criterion->_sub_criteria){
            std::vector<Comment *> comments = submission->get_comments(sub_criterion);
            if(comments.empty()){
                continue;
            } else {
                for(Comment *comment : comments){
                    add_code_lines(submission, comment, htmlString, 2, 2);
                }
            }
        }
    }
    htmlString.append("\n      </div>");
    htmlString.append("\n  </div>");
}

void StudentDeliverable::add_grade_summary(Submission *submission, QString &htmlString){
    htmlString.append("\n        <h2>Grade Summary</h2>");
    add_grades(submission, htmlString);
}


void StudentDeliverable::add_code_lines(Submission *submission, Comment *comment, QString &htmlString, int linesBefore, int linesAfter){
    QString fullPath = submission->getPath() + comment->_filename;
    QFile file(fullPath);
    QString errMsg;
    QFileDevice::FileError err = QFileDevice::NoError;
    //    if (!file.open(QIODevice::ReadOnly)) {
    //        errMsg = file.errorString();
    //        err = file.error();
    //    }
    qDebug() << errMsg;
    htmlString += comment->_filename;
    htmlString += "\n            <div class = \"code-container\">";
            if (file.open(QFile::ReadOnly | QFile::Text)){
        QTextStream in(&file);
        int start = comment->_start_pos;
        int end = comment->_end_pos;
        int current = 0;
        int lineCount = 1;
        int lineIndexStart = -1;
        int lineIndexEnd = -1;
        std::vector<QString> allLines;
        while (!in.atEnd()) {
            QString line = in.readLine();
            allLines.push_back(line);
            int size = line.size();
            current += size;
            if(start < current && lineIndexStart == -1){
                lineIndexStart = lineCount-1;
            }
            if (end < current && lineIndexEnd == -1){
                lineIndexEnd = lineCount-1;
            }
            lineCount++;
        }


        QString lineNumbers = "\n                <div class = \"lines\">";
        QString codeLines = "\n                <div class = \"code\">";
        for(int i = lineIndexStart - linesBefore - 1; i < lineIndexEnd + linesAfter - 1 && i < (int)allLines.size(); i++){
            if(i >= 0){
                codeLines.append("\n                   ");
                lineNumbers.append("\n                   ");
                lineNumbers.append(std::to_string(i).c_str());
                lineNumbers.append("<br>");
                codeLines.append(allLines[i]);
                codeLines.append("<br>");
            }
        }
        lineNumbers.append("\n                </div>");
        codeLines.append("\n                </div>");
        htmlString.append(lineNumbers);
        htmlString.append(codeLines);
        file.close();
    }
    htmlString.append("\n                <div class = \"comment\">");
    if(comment->_grade < 0){
        htmlString.append("\n                  <p><span class=\"grade bad\">");
    } else {
        htmlString.append("\n                  <p><span class=\"grade good\">");
    }
    htmlString.append(QString::number(comment->_grade));
    htmlString.append("\n                  </span>");
    htmlString.append("\n                  " + comment->_text + "</p>"
                      "\n                </div>");
    htmlString.append("\n            </div>");
}

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
    add_student_name(submission, htmlString);
    add_assignment_info(submission, htmlString);
    htmlString.append("\n  <div id = \"document\">");
    add_general_comments(submission, htmlString);
    htmlString.append("\n    <div class = \"container\">");
    add_grade_summary(submission, htmlString);
    htmlString.append(                "\n  </div>");
    add_total_grade(submission, htmlString);
    htmlString.append("\n    <div class = \"container\">");
    add_detailed_remarks(submission, htmlString);
    add_image(submission, htmlString);
    htmlString.append("\n       </div>");
    htmlString.append("\n  </div>");
    htmlString.append("<script>SyntaxHighlighter.all();</script>");
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
    htmlString.append("\n <link href=\"qrc:///css/report/shThemeRDark.css\" rel=\"stylesheet\" type=\"text/css\" />"
                      "\n <link href=\"qrc:///css/report/shCore.css\" rel=\"stylesheet\" type=\"text/css\" />"
                      "\n <script src=\"qrc:///css/report/shCore.js\" type=\"text/javascript\"></script>"
                      "\n <script src=\"qrc:///css/report/shBrushJava.js\" type=\"text/javascript\"></script>"
                      "\n <script src=\"qrc:///css/report/shAutoloader.js\" type=\"text/javascript\"></script>");
    htmlString.append("\n <link href=\"qrc:///css/report/style.css\" rel=\"stylesheet\" type=\"text/css\" />");

}

void StudentDeliverable::add_assignment_info(Submission *submission, QString &htmlString){
    htmlString.append("\n <div id = \"info\">");
    htmlString.append("\n <h3 id = \"assignment-name\">Assignment: ");
    htmlString.append(submission->_assignment->_name);
    htmlString.append(" </h3>");
    htmlString.append(" <b>Objective: </b>"
                      "<p>");
    htmlString.append(submission->_assignment->_objective);
    htmlString.append("</p>");
    htmlString.append(" </div>");
}

void StudentDeliverable::add_student_name(Submission *submission, QString &htmlString){
    htmlString.append("\n<div id = \"student\">");
    htmlString.append("\n<span class=\"avatar\" style=\"background:" + submission->_student->_color + "\">");
    if (submission->_student->_name.split(" ").count() > 1) {
        htmlString.append(
            "\n " +
            submission->_student->_name.split(" ").at(0).left(1).toUpper() +
            submission->_student->_name.split(" ").at(1).left(1).toUpper()
        );
    } else {
        htmlString.append("\n " + submission->_student->_name.left(2).toUpper());
    }
    htmlString.append("\n</span>");
    htmlString.append("\n<div class=\"name\">Student<br>");
    htmlString.append("\n<b>" + submission->_student->_name + "</b></div>");
    htmlString.append("\n<div id = \"grade\">"
        "\n <div id = \"label\">"
        "\n   TOTAL GRADE"
        "\n </div>"
        + QString::number(submission->grade_percent()) +
        "\n %</div>"
        "\n <div class=\"clear\"></div>"
        "\n </div>");
}


void StudentDeliverable::add_total_grade(Submission *submission, QString &htmlString){
    htmlString.append(
                "\n <div id = \"total\">"
                "\n Total grade : "
                "   <span class = \"grade\">" + QString::number(submission->get_grade()) + "</span>"
                "   <span class = \"out-of\">/" + QString::number(submission->_assignment->_rubric->total_grade()) + "</span>"
                "   <span class = \"out-of\"> (" + QString::number(submission->grade_percent()) + "% )</span>"
                "\n </div>"
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

void StudentDeliverable::add_grades(Submission *submission, QString &htmlString){
    for(Criterion *criterion : *submission->_assignment->_rubric->_criteria){
        htmlString.append(
                    "\n        <div class = \"criterion\">"
                    "\n            <div class = \"name\"> <span class = \"circle\"></span> "
                    "\n                ");
        htmlString.append(criterion->_name);
        htmlString.append("<span class = \"grade\">");
        htmlString.append(QString::number(submission->get_grade(criterion)));
        htmlString.append("</span><span class = \"out-of\">/");
        htmlString.append(QString::number(criterion->_out_of));
        htmlString.append("</span>"
                          "\n            </div>");
        if(criterion->has_children()){
            htmlString.append(
                        "\n            <ul>");
            for(Criterion *subcriterion : criterion->children()){
                htmlString.append("\n                <li>"
                                  "\n                <span class = \"sub-line\"></span>      ");
                htmlString.append(subcriterion->_name);
                htmlString.append(" : <span class = \"grade\">");
                htmlString.append(std::to_string(submission->get_grade(subcriterion)).c_str());
                htmlString.append("</span><span class = \"out-of\"> out of ");
                htmlString.append(std::to_string(subcriterion->_out_of).c_str());
                htmlString.append("</span>"
                                  "\n                </li>");
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
                "\n         " + submission->general_comment() +
                "\n        </p>"
                "\n    </div>");

}

void StudentDeliverable::add_detailed_remarks(Submission *submission, QString &htmlString){
    htmlString.append("\n      <h2>Detailed remarks</h2>");
    for(Criterion *criterion : *submission->_assignment->_rubric->_criteria){
        htmlString.append("\n      <div class = \"criterion comments\">");
        htmlString.append("\n          <div class = \"name\">  <span class = \"circle\"></span> ");
        htmlString.append(criterion->_name);
        htmlString.append("\n              <span class = \"grade\">");
        htmlString.append(QString::number(submission->get_grade(criterion)));
        htmlString.append("</span><span class = \"out-of\">/");
        htmlString.append(QString::number(criterion->_out_of));
        htmlString.append("</span>"
                          "\n          </div>");
        std::vector<Comment *> comments = submission->get_comments(criterion);
        // Count number of comments in total
        int total_comments = comments.size();
        for(Criterion *sub_criterion: *criterion->_sub_criteria){
            total_comments += submission->get_comments(sub_criterion).size();
        }
        // Display comments
        if(total_comments <= 0){
            htmlString.append("\n <p>No remarks on this criterion.</p>");
        } else {
            htmlString.append("\n <p><b>Remarks:</b></p>");
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
        htmlString.append("\n      </div>");
    }
    htmlString.append("\n  </div>");
}

void StudentDeliverable::add_grade_summary(Submission *submission, QString &htmlString){
    htmlString.append("\n        <h2>Grade Breakdown</h2>");
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
    qDebug() << errMsg<<endl;
    qDebug()<< fullPath;
    htmlString += "\n <div class=\"comment-block\">";
    htmlString += "\n <span class=\"file_name\">On \"" + comment->_filename + "\" for \"" + comment->_criterion->_name + "\" </span>";
    htmlString += "\n            <div class = \"code-container\">";
    if (file.open(QFile::ReadOnly | QFile::Text)){
        QTextStream in(&file);
        int start = comment->_start_pos;
        int end = comment->_end_pos;
        int current = 0;
        int curline = 1;
        bool started = false;
        QString codeLines = "\n";
        while (!in.atEnd()) {
            QString line = in.readLine();
            int size = line.length() + 1;
            line = line.toHtmlEscaped();
            if (end >= current && end <= current + size) {
                codeLines.append(line);
                codeLines.append("\n");
                started = false;
                break;
            }
                else if (start >= current && start <= current + size)
            {
                codeLines.append("<pre class=\"brush: java; first-line: " + QString::number(curline) + "\">");
                codeLines.append(line);
                codeLines.append("\n");
                started = true;
            }
                else if (started)
            {
                codeLines.append(line);
                codeLines.append("\n");
            }
            current += size;
            curline++;
        }
        codeLines.append("\n </pre>");
        qDebug()<<codeLines;
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
    htmlString.append("\n       </div>");
}

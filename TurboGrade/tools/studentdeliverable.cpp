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
    add_assignment_obj(submission, htmlString);
    add_grade_summary(submission, htmlString);
    htmlString.append("\n    <div id = \"container\">");
    add_detailed_remarks(submission, htmlString);

    /*htmlString.append(
      "        <div class = \"criterion\">"
      "            <div class = \"name\">"
      "              Documentation <span class = \"grade\">4</span><span class = \"out-of\">/5</span>"
      "            </div>"
      "            <table class = \"rubric\">"
      "                <tr>"
      "                  <td>No comments<br> No Javadoc</td>"
      "                  <td class = \"selected\">Few comments<br> Not Javadoc Compliant</td>"
      "                  <td>Mostly commented</td>"
      "                  <td>Clearly documented<br> Javadoc compliant</td>"
      "                </tr>"
      "            </table>"
      "        </div>"*/
    /*htmlString.append(

      "            <div class = \"code-container\">"
      "                <div class = \"lines\">"
      "                  1<br>"
      "                  2<br>"
      "                  3<br>"
      "                  4<br>"
      "                  5<br>"
      "                </div>"
      "                <div class = \"code\">"
      "                  setNumOfCommentsPerHour();<br>"
      "                  maxYaksPerHr=maxOfArray(numOfYaksPerHr);<br>"
      "                  maxCommentsPerHr=maxOfArray(numOfCommentsPerHr);<br>"
      "                  maxLikesPerHr=maxOfArray(numOfLikesPerHr);<br>"
      "                  randomSeed=(long)p.random(1000);<br>"
      "                </div>"
      "                <div class = \"comment\">"
      "                  <p><span class=\"grade bad\">-1</span>Please only use allowed libraries</p>"
      "                </div>"
      "            </div>"
      "        </div>"

      "        <h2>Standing stastics</h2>"
      "        <img class = \"chart\" src=\"https://www.smashingmagazine.com/wp-content/uploads/2014/12/css-animation-craziness.gif\" />"
*/
    htmlString.append(
                "\n    </div>"
                "\n    <div id = \"logo\" >"
                "\n      Powered by <img src = \"turbogradelogodark.png\" />"
                "\n    </div>"
                "\n    <div class=\"clear\"></div>"
                "\n  </div>");
    htmlString.append("\n</body>");
    htmlString.append("\n</html>");
    std::cout << htmlString.toStdString() << "\n";
    return htmlString;
}

void StudentDeliverable::add_header(Submission *submission, QString &htmlString){
    htmlString.append("\n   <title>Student report : ");
    htmlString.append(submission->_student->_name);
    htmlString.append("</title>");
}

void StudentDeliverable::add_style(Submission *submission, QString &htmlString){
    htmlString.append(
                "\n   <style type=\"text/css\">"
                "\n       body {"
                "\n          background-color: #232730;"
                // "   font-family:"
                "\n          color: white;"
                "\n          font-family : sans-serif;"
                "\n       }"

                "\n       h2 {"
                "\n          margin-left: 0px;"
                "\n          margin-top: 30px;"
                "\n          margin-bottom: 30px;"
                "\n       }"

                "\n       .clear {"
                "\n          float: none;"
                "\n          clear: both;"
                "\n       }"

                "\n       .criterion {"
                "\n          border-top: 1px solid #EBEBEB;"
                "\n       }"

                "\n       .criterion:first-of-type {"
                "\n          margin-top: 20px;"
                "\n       }"

                "\n       .criterion.comments {"
                "\n          border: none;"
                "\n       }"

                "\n       .criterion > .name {"
                "\n          font-size: 18px;"
                "\n          padding: 20px;"
                "\n          display: block;"
                "\n       }"

                "\n       .criterion > .name > .grade {"
                "\n          font-weight: bold"
                "\n          font-size: 23px;"
                "\n          padding: 5px;"
                "\n       }"

                "\n       .criterion > .name > .out-of {"
                "\n          color: gray;"
                "\n       }"

                "\n       .criterion ul {"
                "\n          list-style: circle;"
                "\n       }"

                "\n       .criterion li {"
                "\n          padding: 10px;"
                "\n       }"

                "\n       .criterion li > .grade {"
                "\n          font-weight: bold;"
                "\n          font-size: 17px;"
                "\n          padding: 5px;"
                "\n       }"

                "\n       .criterion li > .out-of {"
                "\n          color: gray;"
                "\n       }"

                "\n       .rubric {"
                "\n          width: 100%;"
                "\n          min-height: 100px;"
                "\n          margin-top: 10px;"
                "\n          margin-bottom: 10px;"
                "\n          border-spacing: 10px 0px;"
                "\n       }"

                "\n       .rubric td {"
                "\n          color: darkgray;"
                "\n          background-color-color: white;"
                "\n          border: 1px solid rgb(236, 239, 239);"
                "\n          border-radius: 5px;"
                "\n          padding: 10px;"
                "\n       }"

                "\n       .rubric td.selected {"
                "\n          color: black;"
                "\n          background-color-color: white;"
                "\n          border: 3px solid rgb(230, 212, 0);"
                "\n          border-radius: 5px;"
                "\n          padding: 10px;"
                "\n       }"

                "\n       #total {"
                "\n          border-top: 1px solid lightgray;"
                "\n          padding: 20px;"
                "\n          text-align: right;"
                "\n          text-transform: uppercase;"
                "\n          font-weight: bold;"
                "\n          margin-top: 20px;"
                "\n       }"

                "\n       #total > .out-of {"
                "\n          color : gray;"
                "\n          font-weight: normal;"
                "\n       }"

                "\n       #document {"
                "\n          color: white;"
                "\n          padding : 20px;"
                "\n       }"

                "\n       #logo {"
                "\n          float: right;"
                "\n       }"

                "\n       #logo > img {"
                "\n          height: 32px;"
                "\n          vertical-align: middle;"
                "\n       }"

                "\n       #info {"
                "\n          float: left;"
                "\n          padding-top: 20px;"
                "\n       }"

                "\n       #grade {"
                "\n          float: right;"
                "\n          color: green;"
                "\n          border-radius: 5px;"
                "\n          background-color: white;"
                "\n          padding: 20px;"
                "\n          font-size: 28px;"
                "\n          text-align: center;"
                "\n       }"

                "\n       #grade > #label {"
                "\n          font-size: 13px;"
                "\n          text-transform: uppercase;"
                "\n          color: gray;"
                "\n          margin-bottom: 5px;"
                "\n       }"

                "\n       #assignment-name {"
                "\n          font-size: 24px;"
                "\n       }"

                "\n       #container {"
                "\n          color: black;"
                "\n          border-radius: 5px;"
                "\n          background-color: white;"
                "\n          padding: 20px;"
                "\n          margin-top: 20px;"
                "\n          margin-bottom: 20px;"
                "\n       }"

                "\n       .code-container {"
                "\n          background-color: #232730;"
                "\n          color: #EBEBEB;"
                "\n          padding: 20px;"
                "\n          border-radius: 5px;"
                "\n          position: relative;"
                "\n          margin-bottom: 20px;"
                "\n       }"

                "\n       .code {"
                "\n          padding-left: 20px;"
                "\n       }"

                "\n       .code-container > .lines {"
                "\n          color: gray;"
                "\n          font-weight: 200;"
                "\n          position: absolute;"
                "\n       }"

                "\n       .comment {"
                "\n          margin-top: 20px;"
                "\n          background-color: #ffea8d;"
                //"    border-radius: 5px;"
                "\n          padding: 20px;"
                "\n          color: black;"
                "\n       }"
                "\n       .comment > .title {"
                "\n          text-transform: uppercase;"
                "\n          color: rgb(107, 100, 51);"
                "\n          font-weight: bold;"
                "\n          padding: 10px;"

                "\n       }"

                "\n       .comment > p > .grade {"
                "\n          padding : 10px;"
                "\n       }"

                "\n       .comment > p > .grade.bad {"
                "\n          color: red;"
                "\n       }"

                "\n       .comment > p > .grade.good {"
                "\n          color: green;"
                "\n       }"

                "\n       .chart {"
                "\n          border-radius: 5px;"
                "\n          width: 100%;"
                "\n          margin-bottom: 10px;"
                "\n       }"

                "\n   </style>");
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
                "\n    </div>");
}

void StudentDeliverable::add_grade_two(Submission *submission, QString &htmlString){
    htmlString.append(
                "\n        <div id = \"total\">"
                "\n          Total grade : <span class = \"grade\">");
    htmlString.append(submission->get_grade());
    htmlString.append("\n</span><span class = \"out-of\">/");
    htmlString.append(submission->get_out_of());
    htmlString.append("\n</span>"
                      "\n        </div>");

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
        for(Criterion *sub_criterion: *criterion->_sub_criteria){
            std::vector<Comment *> comments = submission->get_comments(sub_criterion);
            if(comments.empty()){
                continue;
            } else {
                for(Comment *comment : comments){
                    add_code_comment(submission, htmlString, comment);
                }
            }
        }
        htmlString.append("\n      </div>");
    }
}

void StudentDeliverable::add_grade_summary(Submission *submission, QString &htmlString){
    htmlString.append("\n        <h2>Grade Summary</h2>");
    add_grades(submission, htmlString);
}

void StudentDeliverable::add_code_comment(Submission *submission, QString &htmlString, Comment *comment){
    htmlString.append(
                "\n            <div class = \"code-container\">"
                "\n                <div class = \"lines\">"
                "\n                  1<br>"
                "\n                  2<br>"
                "\n                  3<br>"
                "\n                  4<br>"
                "\n                  5<br>"
                "\n                </div>"
                "\n                <div class = \"code\">"
                "\n                  setNumOfCommentsPerHour();<br>"
                "\n                  maxYaksPerHr=maxOfArray(numOfYaksPerHr);<br>"
                "\n                  maxCommentsPerHr=maxOfArray(numOfCommentsPerHr);<br>"
                "\n                  maxLikesPerHr=maxOfArray(numOfLikesPerHr);<br>"
                "\n                  randomSeed=(long)p.random(1000);<br>"
                "\n                </div>"
                "\n                <div class = \"comment\">"
                "\n                  <p><span class=\"grade bad\">");
    htmlString.append(std::to_string(comment->_grade).c_str());
    htmlString.append("\n</span>");
    htmlString.append(comment->_text);
    htmlString.append("\n</p>"
                      "\n                </div>");
}

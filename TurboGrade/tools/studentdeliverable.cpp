#include "studentdeliverable.h"

StudentDeliverable::StudentDeliverable()
{

}

QString StudentDeliverable::placeParameters(Submission *submission){
    if(submission == nullptr){
        return "";
    }
    QString htmlString ="<!DOCTYPE html>";
    htmlString.append("\n<html>");
    htmlString.append("\n   <head>");
    htmlString.append("\n<meta charset=\"utf-8\">");
    htmlString.append("\n    <title>Student report : ");
    htmlString.append(submission->_student->_name);
    htmlString.append("</title>"
        "<style type=\"text/css\">"
        "  body {"
        "    background: #232730;"
        "   font-family:"
        "    color: white;"
        "    font-family : sans-serif;"
        "  }"

        "  h2 {"
        "    margin-left: 0px;"
        "    margin-top: 30px;"
        "    margin-bottom: 30px;"
        "  }"

        "  .clear {"
        "    float: none;"
        "    clear: both;"
        "  }"

        "  .criterion {"
        "    border-top: 1px solid #EBEBEB;"
        "  }"

        "  .criterion:first-of-type {"
        "    margin-top: 20px;"
        "  }"

        "  .criterion.comments {"
        "    border: none;"
        "  }"

        "  .criterion > .name {"
        "      font-size: 18px;"
        "      padding: 20px;"
        "      display: block;"
        "  }"

        "  .criterion > .name > .grade {"
        "    font-weight: bold;"
        "    font-size: 23px;"
        "    padding: 5px;"
        "  }"

        "  .criterion > .name > .out-of {"
        "    color: gray;"
        "  }"

        "  .criterion ul {"
        "    list-style: circle;"
        "  }"

        "  .criterion li {"
        "    padding: 10px;"
        "  }"

        "  .criterion li > .grade {"
        "    font-weight: bold;"
        "    font-size: 17px;"
        "    padding: 5px;"
        "  }"

        "  .criterion li > .out-of {"
        "    color: gray;"
        "  }"

        "  .rubric {"
        "    width: 100%;"
        "    min-height: 100px;"
        "    margin-top: 10px;"
        "    margin-bottom: 10px;"
        "    border-spacing: 10px 0px;"
        "  }"

        "  .rubric td {"
        "    color: darkgray;"
        "    background-color: white;"
        "    border: 1px solid rgb(236, 239, 239);"
        "    border-radius: 5px;"
        "    padding: 10px;"
        "  }"

        "  .rubric td.selected {"
        "    color: black;"
        "    background-color: white;"
        "    border: 3px solid rgb(230, 212, 0);"
        "    border-radius: 5px;"
        "    padding: 10px;"
        "  }"

        "  #total {"
        "    border-top: 1px solid lightgray;"
        "    padding: 20px;"
        "    text-align: right;"
        "    text-transform: uppercase;"
        "    font-weight: bold;"
        "    margin-top: 20px;"
        "  }"

        "  #total > .out-of {"
        "    color : gray;"
        "    font-weight: normal;"
        "  }"

        "  #document {"
        "    color: white;"
        "    padding : 20px;"
        "  }"

        "  #logo {"
        "    float: right;"
        "  }"

        "  #logo > img {"
        "    height: 32px;"
        "    vertical-align: middle;"
        "  }"

        "  #info {"
        "    float: left;"
        "    padding-top: 20px;"
        "  }"

        "  #grade {"
        "    float: right;"
        "    color: green;"
        "    border-radius: 5px;"
        "    background: white;"
        "    padding: 20px;"
        "    font-size: 28px;"
        "    text-align: center;"
        "  }"

        "  #grade > #label {"
        "    font-size: 13px;"
        "    text-transform: uppercase;"
        "    color: gray;"
        "    margin-bottom: 5px;"
        "  }"

        "  #assignment-name {"
        "    font-size: 24px;"
        "  }"

        "  #container {"
        "    color: black;"
        "    border-radius: 5px;"
        "    background: white;"
        "    padding: 20px;"
        "    margin-top: 20px;"
        "    margin-bottom: 20px;"
        "  }"

        "  .code-container {"
        "    background: #232730;"
        "    color: #EBEBEB;"
        "    padding: 20px;"
        "    border-radius: 5px;"
        "    position: relative;"
        "    margin-bottom: 20px;"
        "  }"

        "  .code {"
        "    padding-left: 20px;"
        "  }"

        "  .code-container > .lines {"
        "    color: gray;"
        "    font-weight: 200;"
        "    position: absolute;"
        "  }"

        "  .comment {"
        "    margin-top: 20px;"
        "    background: #ffea8d;"
        "    border-radius: 5px;"
        "    padding: 20px;"
        "    color: black;"
        "  }"
        "  .comment > .title {"
        "    text-transform: uppercase;"
        "    color: rgb(107, 100, 51);"
        "    font-weight: bold;"
        "    padding: 10px;"

        "  }"

        "  .comment > p > .grade {"
        "    padding : 10px;"
        "  }"

        "  .comment > p > .grade.bad {"
        "    color: red;"
        "  }"

        "  .comment > p > .grade.good {"
        "    color: green;"
        "  }"

        "  .chart {"
        "    border-radius: 5px;"
        "    width: 100%;"
        "    margin-bottom: 10px;"
        "  });"

        "</style>"
      "</head>"
      "<body>"
      "  <div id = \"document\">"
      "    <div id = \"info\">");
    htmlString.append(submission->_student->_name);
    htmlString.append("<br>"
      "      <div id = \"assignment-name\">"
      "        Assignment :");
    htmlString.append("\"Lab 5 : Binary Search Tree\"");
    htmlString.append(
      "      </div>"
      "    </div>"
      "    <div id = \"grade\">"
      "      <div id = \"label\">"
      "        TOTAL GRADE"
      "      </div>"
                );
    htmlString.append(QString(submission->get_grade()));
    htmlString.append(
    "    </div>"
      "    <div class=\"clear\"></div>"
    );
    for(Comment *comment:*submission->_comments){
        htmlString.append(
                    "    <div class = \"comment\">");
        htmlString.append(
                    "      <div class = \"title\">");
        htmlString.append(comment->_criterion->_name);
        htmlString.append("</div>"
                          "       <p>");
        htmlString.append(comment->_text);
        htmlString.append("      </p>"
                          "    </div>");
    }
    htmlString.append(
      "    <div id = \"container\">"

      "        <h2>Assignment Objective</h2>"

      "        <p>"
      "          This project will help you get familiar with"
      "          <ul>"
      "            <li>Images</li>"
      "            <li>Nested Loops</li>"
      "          </ul>"
      "        </p>"

      "        <h2>Grade Summary</h2>");
      for(Criterion *criterion : *submission->_assignment->_rubric->_criteria){
          htmlString.append(
      "        <div class = \"criterion\">"
      "            <div class = \"name\">");
          htmlString.append(criterion->_name);
          htmlString.append("<span class = \"grade\">");
          htmlString.append(QString(submission->get_grade(criterion)));
                  htmlString.append("</span><span class = \"out-of\">/");
          htmlString.append(QString(criterion->_out_of));
          htmlString.append("</span>"
      "            </div>"
      "            <ul>");
          for(Criterion *subcriterion : criterion->children()){
          htmlString.append("<li>");
          htmlString.append(subcriterion->_name);
          htmlString.append(" : <span class = \"grade\">");
          htmlString.append(submission->get_grade(subcriterion));
          htmlString.append("</span><span class = \"out-of\">out of ");
          htmlString.append(subcriterion->_out_of);
          htmlString.append("</span></li>");
          }
          htmlString.append(
                      "            </ul>"
      "        </div>");
      }
      htmlString.append(
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
      "        </div>"
      "        <div id = \"total\">"
      "          Total grade : <span class = \"grade\">");
      htmlString.append(submission->get_grade());
      htmlString.append("</span><span class = \"out-of\">/");
      htmlString.append(submission->get_out_of());
      htmlString.append("</span>"
      "        </div>"

      "        <h2>Detailed remarks</h2>"

      "        <div class = \"criterion comments\">"
      "            <div class = \"name\">"
      "              Correctness <span class = \"grade\">17</span><span class = \"out-of\">/20</span>"
      "            </div>"
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

      "    </div>"
      "    <div id = \"logo\" >"
      "      Powered by <img src = \"turbogradelogodark.png\" />"
      "    </div>"
      "    <div class=\"clear\"></div>"
      "  </div>"
      "</body>"
    "</html>");
    std::cout << htmlString.toStdString() << "\n";
    return htmlString;
}

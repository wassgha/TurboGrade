#include "report.h"

Report::Report()
{

}

QString Report::gen(Submission *submission) {

    QScriptEngine *engine = new QScriptEngine;

    JTemplate tpl(engine);
    tpl.loadFromFile(":/report-template.html");

    QScriptValue vars = engine->newObject();
    vars.setProperty("student_name", submission->_student->_name);
    vars.setProperty("assignment_name", submission->_assignment->_name);

    return tpl.apply(vars);

}

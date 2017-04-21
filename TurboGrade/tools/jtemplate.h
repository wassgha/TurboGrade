#ifndef JTEMPLATE_H
#define JTEMPLATE_H

/*
 * Template Parser parser
 *
 * Credit: http://vcg.isti.cnr.it/~ponchio
 * Ported to Qt5 by Wassim Gharbi
 *
 */

#include <QWidget>
#include <QScriptEngine>
#include <QScriptValue>
#include <QScriptValueIterator>
#include <QScriptContext>
#include <QFile>

//DEBUG
#include <QMessageBox>

class JTemplate
{
public:

    JTemplate(QScriptEngine *e = NULL): engine(e) {}
    //here e is assumed NOT NULL!
    JTemplate(QScriptEngine *e, QString tpl): engine(e) {
      preprocess(tpl);
    }

    void setEngine(QScriptEngine *e) {
      engine = e;
    }

    void setTemplate(QString tpl) {
      preprocess(tpl);
    }

    bool loadFromFile(QString path) {
      QFile file(path);
      if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
      QString tpl = file.readAll();
      file.close();
      preprocess(tpl);
      return true;
    }
    QString apply(QScriptValue &variables) {

      //pop and push to leave a clean status, not really necessary
      QScriptContext *context = engine->pushContext();
      QScriptValue ret = code.call(variables);

      if(engine->hasUncaughtException()) {
        QString error = engine->uncaughtException().toString() +
                        QString(" At line %1").arg(engine->uncaughtExceptionLineNumber());
        QMessageBox::information(NULL, "Error", error);
      }

      engine->popContext();
      return ret.toString();
    }

protected:
    QScriptEngine *engine;
    QScriptValue code;
    QString js;

    void preprocess(QString tpl) {
      QStringMatcher in("<?");
      QStringMatcher out("?>");
      int position = 0;
      int next = 0;

      QString str = "(function() { with(this) { var s='';\n";

      bool inside = false;
      while(position < tpl.size()) {

        if(!inside) {
          next = in.indexIn(tpl, position);
          if(next == -1) next = tpl.size();
          QString escaped = escape(tpl.mid(position, next-position));
          escaped.replace('\n', ' ');
          if(escaped != "")
            str += "s += '" + escaped + "';\n";
          position = next + 2;
          inside = true;

        } else {
          next = out.indexIn(tpl, position);

          bool shortform = (tpl[position] == '=');
          if(shortform) {
            position++;
            str += "s += " + tpl.mid(position, next - position) + ";\n";
          } else
            str += tpl.mid(position, next - position) + "\n";

          position = next + 2;

          inside = false;
        }
      }
      str += " return s;} })";
      js = str;
      code = engine->evaluate(str);
      if(!code.isFunction()) {
        if(engine->hasUncaughtException()) {
          QString error = engine->uncaughtException().toString() +
                          QString(" At line %1").arg(engine->uncaughtExceptionLineNumber());
          error += "\n" + str;
          QMessageBox::information(NULL, "Error", error);
        }
      }
    }


    QString escape(QString s) {
      s.replace('\\', "\\\\");
      s.replace('\'', "\\\'");
      return s;
    }
};
#endif

#ifndef DUMPTOOL_H
#define DUMPTOOL_H
#include <QString>
#include <QDebug>
#include <QProcess>

class DumpTool
{
public:
    DumpTool();
    void run_process(QString command, QString inputFile = "", QString outputFile = "");
    void dump(QString dbname, QString outputFile);
    void restore(QString dbname, QString inputFile);
};

#endif // DUMPTOOL_H

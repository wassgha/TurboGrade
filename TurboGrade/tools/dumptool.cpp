#include "dumptool.h"

DumpTool::DumpTool()
{

}

void DumpTool::run_process(QString command, QString inputFile = "", QString outputFile = ""){
    qDebug() << "Running : " << command;
    QProcess process;
    if(!inputFile.isEmpty()){
        process.setStandardInputFile(inputFile);
    }
    if(!outputFile.isEmpty()){
        process.setStandardOutputFile(outputFile);
    }
    process.start(command);
    if(process.waitForFinished()){
        QString out = process.readAllStandardOutput();
        QStringList lines = out.split("\n");
        for(QString line : lines){
            qDebug() << line;
        }
    }
    QProcess::ExitStatus Status = process.exitStatus();
    if(Status == 0){
        qDebug() << "Finished ok";
    }
}

void DumpTool::dump(QString dbname, QString outputFile){
    run_process("sqlite3 " + dbname + " .dump", "", outputFile);
}

void DumpTool::restore(QString dbname, QString inputFile){
    run_process("sqlite3 " + dbname, inputFile, "");
}

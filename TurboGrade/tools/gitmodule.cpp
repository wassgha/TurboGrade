#include "gitmodule.h"

GitModule::GitModule()
{

}

/**
 * @brief GitModule::clone clones the repository denoted by repoUrl to the
 * directory designated by the workingDirectory
 * @param workingDirectory the directory the repository will be placed
 * @param repoUrl the repoUrl to clone
 */
void GitModule::clone(QString workingDirectory, QString repoUrl){
    // create process
    QProcess process;
    process.setProcessChannelMode(QProcess::ForwardedChannels);
    // add some arguments
    QStringList arguments;
    process.setWorkingDirectory(workingDirectory);
    // arguments are clone and the repoUrl
    arguments << "clone" << repoUrl;

    qDebug() << "Process trying to run command : git clone " << repoUrl;
    qDebug() << "In : " << process.workingDirectory();

    // start process git with args clone repoUrl
    // git clone repoUrl
    process.start("git", arguments);
    if(process.waitForFinished()){
        // get standard out string
        QString out = process.readAllStandardOutput();
        // get error string
        QString error = process.readAllStandardError();
        if(!out.isEmpty()){
            qDebug() << "Standard Out: ";
            QStringList lines = out.split("\n");
            for(QString line : lines){
                qDebug() << line;
            }
        }
        if(!error.isEmpty()){
            qDebug() << "Errors: ";
            lines = error.split("\n");
            for(QString line : lines){
                qDebug() << line;
            }
        }
    }

    QProcess::ExitStatus Status = process.exitStatus();
    if(Status == 0){
        qDebug() << "Finished ok";
    }
}

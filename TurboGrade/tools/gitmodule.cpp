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

/**
 * @brief GitModule::add adds the fileToAdd to the repository located in working
 * Directory
 * @param workingDirectory the workingDirectory of the repo
 * @param fileToAdd the file/regex to be added
 */
void GitModule::add(QString workingDirectory, QString fileToAdd){
    // create process
    QProcess process;
    process.setProcessChannelMode(QProcess::ForwardedChannels);
    // add some arguments
    QStringList arguments;
    process.setWorkingDirectory(workingDirectory);
    // arguments are add and the fileToAdd
    arguments << "add" << fileToAdd;

    qDebug() << "Process trying to run command : git add " << repoUrl;
    qDebug() << "In : " << process.workingDirectory();

    // start process git with args add fileToAdd
    // git add fileToAdd
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

/**
 * @brief GitModule::commit commits the current revisions to the repo in the
 * workingDirectory, with the message
 * @param workingDirectory the working directory of the repo
 * @param message the commit message
 */
void GitModule::commit(QString workingDirectory, QString message){
    // create process
    QProcess process;
    process.setProcessChannelMode(QProcess::ForwardedChannels);
    // add some arguments
    QStringList arguments;
    process.setWorkingDirectory(workingDirectory);

    // arguments are commit, -m, and the message
    arguments << "commit" << "-m" << message;

    qDebug() << "Process trying to run command : git commit -m " << message;
    qDebug() << "In : " << process.workingDirectory();

    // git commit -m message
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

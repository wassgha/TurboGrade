#include "gitmodule.h"

GitModule::GitModule(QString workingDirectory, QString repoUrl, QString password)
{
    _workingDirectory = QDir(qApp->applicationDirPath()).absoluteFilePath(workingDirectory);
    _repoUrl = repoUrl;
    _password = password;
}

/**
 * @brief GitModule::clone clones the repository denoted by repoUrl to the
 * directory designated by the workingDirectory
 */
void GitModule::clone(){
    // create process
    QProcess process;
    process.setProcessChannelMode(QProcess::ForwardedChannels);
    // add some arguments
    QStringList arguments;
    QDir parent(_workingDirectory);
    parent.cdUp();
    process.setWorkingDirectory(parent.path());
    // arguments are clone and the repoUrl
    arguments << "clone" << _repoUrl;

    qDebug() << "Process trying to run command : git clone " << _repoUrl;
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
            QStringList lines = error.split("\n");
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
 * @brief GitModule::store_credentials asks git
 * to store the credentials on the first clone
 */
void GitModule::store_credentials(){
    // create process
    QProcess process;
    process.setProcessChannelMode(QProcess::ForwardedChannels);
    // add some arguments
    QStringList arguments;
    QDir parent(_workingDirectory);
    parent.cdUp();
    process.setWorkingDirectory(parent.path());

    qDebug() << "Process trying to run command : git config ";
    qDebug() << "In : " << process.workingDirectory();

    process.start("git", QStringList() << "config" << "credential.helper" << "store");


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
            QStringList lines = error.split("\n");
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
 * @param fileToAdd the file/regex to be added
 */
void GitModule::add(QString fileToAdd){
    // create process
    QProcess process;
    process.setProcessChannelMode(QProcess::ForwardedChannels);
    // add some arguments
    QStringList arguments;
    process.setWorkingDirectory(_workingDirectory);
    // arguments are add and the fileToAdd
    arguments << "add" << fileToAdd;

    qDebug() << "Process trying to run command : git add " << fileToAdd;
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
            QStringList lines = error.split("\n");
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
 * @brief GitModule::add_all adds all files to the repository located in working
 * Directory
 */
void GitModule::add_all(){
    // create process
    QProcess process;
    process.setProcessChannelMode(QProcess::ForwardedChannels);
    // add some arguments
    QStringList arguments;
    process.setWorkingDirectory(_workingDirectory);
    // arguments are add and all files
    arguments << "add" << "-A";

    qDebug() << "Process trying to run command : git add -A";
    qDebug() << "In : " << process.workingDirectory();

    // start process git with args add -A
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
            QStringList lines = error.split("\n");
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
 * @param message the commit message
 */
void GitModule::commit(QString message){
    // create process
    QProcess process;
    process.setProcessChannelMode(QProcess::ForwardedChannels);
    // add some arguments
    QStringList arguments;
    process.setWorkingDirectory(_workingDirectory);

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
            QStringList lines = error.split("\n");
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
 * @brief GitModule::push pushes commits to the repository in workingDirectory
 * @param force force push or solve conflicts
 */
void GitModule::push(bool force){
    // create process
    QProcess process;
    process.setProcessChannelMode(QProcess::ForwardedChannels);
    // add some arguments
    QStringList arguments;
    process.setWorkingDirectory(_workingDirectory);

    // arguments are push
    arguments << "push" << _repoUrl;
    if (force)
        arguments << "--force";

    qDebug() << "Process trying to run command : git push";
    qDebug() << "In : " << process.workingDirectory();

    // git add
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
            QStringList lines = error.split("\n");
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
 * @brief GitModule::pull pulls the repo from the origin
 */
void GitModule::pull(){
    // create process
    QProcess process;
    process.setProcessChannelMode(QProcess::ForwardedChannels);
    // add some arguments
    QStringList arguments;
    process.setWorkingDirectory(_workingDirectory);

    // arguments are pull
    arguments << "pull" << _repoUrl;

    qDebug() << "Process trying to run command : git pull";
    qDebug() << "In : " << process.workingDirectory();

    // git pull
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
            QStringList lines = error.split("\n");
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

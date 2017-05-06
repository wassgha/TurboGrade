#ifndef GITMODULE_H
#define GITMODULE_H
#include <QString>
#include <QProcess>
#include <QDebug>
#include <QApplication>
#include "QDir"

class GitModule
{
public:
    GitModule(QString workingDirectory = "", QString repoUrl = "", QString password = "");
    // clone the Git repo to the workingDirectory
    void clone();
    // add the file/directory/regex to the Git Repo in the workingDirectory
    void add(QString fileToAdd);
    // adds every file
    void add_all();
    // commit in the workingDirectory with message
    void commit(QString message);
    // push the repo in the workingDirectory
    void push(bool force);
    // pull from origin
    void pull();
    // Configuration parameters
    QString _workingDirectory;
    QString _repoUrl;
    QString _password;
};

#endif // GITMODULE_H

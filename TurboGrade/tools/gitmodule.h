#ifndef GITMODULE_H
#define GITMODULE_H
#include <QString>
#include <QProcess>
#include <QDebug>

class GitModule
{
public:
    GitModule();
    // clone the Git repo to the workingDirectory
    static void clone(QString workingDirectory, QString repoUrl);
    // add the file/directory/regex to the Git Repo in the workingDirectory
    static void add(QString workingDirectory, QString fileToAdd);
    // commit in the workingDirectory with message
    static void commit(QString workingDirectory, QString message);
    // push the repo in the workingDirectory
    static void push(QString workingDirectory);
    // pull from origin
    static void pull(QString workingDirectory);
};

#endif // GITMODULE_H

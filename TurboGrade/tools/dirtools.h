#ifndef DIRTOOLS_H
#define DIRTOOLS_H


#include "QString"
#include "QFile"
#include "QDir"
#include <QApplication>
#include <QStandardPaths>
#include <QDebug>
#include <QProgressBar>
#include <iostream>


class DirTools
{
public:
    DirTools();
    static bool copy_dir_recursive(QString from_dir, QString to_dir, bool replace_on_conflit = true, QProgressBar* progress_bar = nullptr);
    static QString first_file(QString folder);
};

#endif // DIRTOOLS_H

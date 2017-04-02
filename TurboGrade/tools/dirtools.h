#ifndef DIRTOOLS_H
#define DIRTOOLS_H


#include "QString"
#include "QFile"
#include "QDir"
#include <QDebug>
#include <iostream>


class DirTools
{
public:
    DirTools();
    static bool copy_dir_recursive(QString from_dir, QString to_dir, bool replace_on_conflit = true);
};

#endif // DIRTOOLS_H

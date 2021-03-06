#include "dirtools.h"

bool DirTools::copy_dir_recursive(QString from_dir, QString to_dir, bool replace_on_conflit, QProgressBar* progress_bar)
{
    QDir dir;
    from_dir = QDir(qApp->applicationDirPath()).absoluteFilePath(from_dir);
    to_dir = QDir(qApp->applicationDirPath()).absoluteFilePath(to_dir);
    dir.setPath(from_dir);

    from_dir += QDir::separator();
    to_dir += QDir::separator();

    qDebug()<<"Importing "<< from_dir << " to " << to_dir;
    if(progress_bar)
        progress_bar->setMaximum(progress_bar->maximum() + dir.count());
    QApplication::processEvents();

    foreach (QString copy_file, dir.entryList(QDir::Files))
    {
        QString from = from_dir + copy_file;
        QString to = to_dir + copy_file;

        if (QFile::exists(to))
        {
            if (replace_on_conflit)
            {
                if (QFile::remove(to) == false)
                {
                    return false;
                }
            }
            else
            {
                continue;
            }
        }

        if (QFile::copy(from, to) == false)
        {
            return false;
        }
        if(progress_bar)
            progress_bar->setValue(progress_bar->value() + 1);
        QApplication::processEvents();
    }


    foreach (QString copy_dir, dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot))
    {
        QString from = from_dir + copy_dir;
        QString to = to_dir + copy_dir.left(copy_dir.indexOf("_"));

        if (dir.mkpath(to) == false)
        {
            return false;
        }

        if (copy_dir_recursive(from, to, replace_on_conflit, progress_bar) == false)
        {
            return false;
        }
        if(progress_bar)
            progress_bar->setValue(progress_bar->value() + 1);
        QApplication::processEvents();
    }

    return true;
}

QString DirTools::first_file(QString folder)
{
    QDir dir;
    dir.setPath(folder);
    qDebug()<<"Called for " + folder;
    if (dir.entryList(QDir::Files).size() > 0) {
        qDebug()<<"1";
        return folder + QDir::separator() + dir.entryList(QDir::Files).at(0);
    } else if (dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot).size() > 0) {
        qDebug()<<"2";
        return first_file(folder + QDir::separator() + dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot).at(0));
    } else {
        qDebug()<<"3";
        return folder;
    }
}



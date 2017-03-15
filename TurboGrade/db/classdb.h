#ifndef CLASSDB_H
#define CLASSDB_H

#include "dbengine.h"

class ClassDB : public DBEngine
{
public:
    // Default constructor
    ClassDB();
    // Adds a row to the table
    bool add(const QString name);
    // Gets row id matching name
    int select(const QString name);
};

#endif // CLASSDB_H

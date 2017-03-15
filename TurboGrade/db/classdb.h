#ifndef CLASSDB_H
#define CLASSDB_H

/**
 * @brief ClassDB is the interface for the
 * class database table. It is used to add
 * and retrieve rows from the table.
 */

#include "dbengine.h"

class ClassDB : public DBEngine
{
public:
    // Constructor
    ClassDB();
    // Destructor
    ~ClassDB();
    // Adds a row to the table
    bool add(const QString name);
    // Gets row id matching name
    int select(const QString name);
};

#endif // CLASSDB_H

#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

/**
 * @brief The Assignment class describes a single
 * assignment (that can belong to multiple sections)
 * and holds its rubric.
 */

#include <iostream>
#include <vector>
#include <QString>

#include "../tools/macro.h"
#include "../tools/objectidentifier.h"

#include "controller.h"
#include "assignment.h"
#include "rubric.h"

class Controller;
class Rubric;

class Assignment : public ObjectIdentifier
{
public:

    Assignment() = delete; //don't allow default constructor
    // Parametrized constructor
    Assignment(int id, const QString name, const QString objective, Controller *controller);
    // Destructor
    ~Assignment();

    int _id;
    // Name of the assignment
    QString _name;
    // Brief objective of the assignment
    QString _objective;
    // The rubric corresponding to this Assignment
    Rubric* _rubric;
    // Color (for UI)
    QString _color;
    // Controller
    Controller *_controller;
};

#endif // ASSIGNMENT_H

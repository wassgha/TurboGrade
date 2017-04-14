#ifndef CRITERION_H
#define CRITERION_H

/**
 * @brief The Criterion class describe a single
 * category that belongs to a rubric (and can be
 * extender with children).
 */


#include <iostream>
#include <vector>
#include <QString>
#include <QObject>

#include "../tools/macro.h"
#include "../tools/objectidentifier.h"

#include "controller.h"
#include "rubric.h"

class Controller;
class Rubric;

class Criterion : public ObjectIdentifier, public QObject
{
public:
    Criterion() = delete; //don't allow default constructor
    // Parametrized constructor
    Criterion(const QString name, Criterion* parent, int out_of, Rubric* rubric, Controller * controller, int id = -1);
    // Destructor
    ~Criterion();
    // Add sub-criterion
    Criterion* add_child(const QString name, Criterion* parent, int out_of, int id = -1);
    // Returns whether this criterion has children or not
    bool has_children();
    // Returns this criterion's children
    std::vector<Criterion*> children();
    // Find a criterion within the current hierarchy by name
    Criterion* find_criterion(const QString name);
    // Find a criterion within the current hierarchy by table id
    Criterion* find_criterion(const int id);
    // Get the total maximum score for this criterion
    int total_grade();
    // Show criteria tree
    void show_children();
    // Recursively return in_order of names of sub criteria and this name
    std::string in_order_names();

    // This Criterion's id
    int _id;
    // This criterion's rubric
    Rubric* _rubric = nullptr;
    // Criterion's parent (nullpointer if this is a parent)
    Criterion* _parent = nullptr;
    // Criterion name
    QString _name;
    // Maximum grade for this criterion (0 if extra-credit)
    int _out_of;
    // Sub-criteria
    std::vector<Criterion*> *_sub_criteria;
    // Controller
    Controller *_controller;
};

#endif // CRITERION_H

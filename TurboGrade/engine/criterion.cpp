#include "criterion.h"

Criterion::Criterion()
{
    std::cerr<<"Please provide criterion information.";
    exit(0);
}

Criterion::Criterion(const QString name, Criterion* parent, int out_of, Rubric* rubric)
{
    _name = name;
    _parent = parent;
    _out_of = out_of;
    _rubric = rubric;
}

Criterion::~Criterion()
{

}

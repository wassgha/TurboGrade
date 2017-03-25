#include "objectidentifier.h"

int ObjectIdentifier::id_cnt = 0;

ObjectIdentifier::ObjectIdentifier()
{

    // Uniquely identify the object.
    obj_id = id_cnt;

    // Increment the created object count.
    id_cnt++;

    // Be carefull of the ordering here.
    //SHOW_WHERE;
}


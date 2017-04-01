#ifndef MACRO_H
#define MACRO_H
#include <iostream>

#define DEBUGGING

#ifdef DEBUGGING
    #define SHOW_WHERE std::cout << __PRETTY_FUNCTION__ << " id:" << obj_id << std::endl;
#else
    #define SHOW_WHERE
#endif
#endif // MACRO_H

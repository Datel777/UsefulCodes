#pragma once

#include <iostream>

//define this to remove debug messages
//#define NO_DEBUG


#ifdef NO_DEBUG
    #define DEBUG(a)
#else
    #define DEBUG(a) std::cout << #a << " = " << a << std::endl
#endif

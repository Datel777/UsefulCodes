#pragma once

#include <unordered_map>


class Registrator
{
    static std::unordered_map<int, const char*> _registeredClasses;
    static int _registerNextID;
};

template<class T>
int registeredID()  {return 0;}

int Registrator::_registerNextID = 1;

//#define REGISTRATOR
struct __Registrator__ {__Registrator__() {/*call register function*/}};


//#define REGISTER(ClassName) namespace {ClassName::__Registrator__ r;}
namespace {__Registrator__ r;}


//template<>
//int registeredID<int>()  {return 1;}

#include <iostream>

using namespace std;


#pragma pack(push, 1)

template<class T>
union Data
{
    char data[sizeof(T)];
    T value;
};

template<class T, int size>
union DataArray
{
    char data[sizeof(T)*size];
    T values[size];
};


//if int is 4 bytes
__int32 swapEndian(__int32 i)
{
    union swapper
    {
        __int32 value;
        struct {
            char d1;
            char d2;
            char d3;
            char d4;
        };
    } c{i};

    swapper c2;
    c2.d1 = c.d4;
    c2.d2 = c.d3;
    c2.d3 = c.d2;
    c2.d4 = c.d1;

    return c2.value;
}

#pragma pack(pop)


template<class T, class Return, class ... Args>
inline int functionID(Return (T::*_func)(Args...))
{//not working with constexpr, only runtime
    union convert
    {
        Return (T::*func)(Args...);
        int id;
    };

    return convert{_func}.id;
}


template<class T, class Return, class ... Args>
using FunctionMemberPointer = Return (T::*)(Args...);

template<class T, class Return, class ... Args>
inline FunctionMemberPointer<T, Return, Args...> idFunction(int id)
{//not working with constexpr, only runtime
    union convert
    {
        int id;
        Return (T::*func)(Args...);
    };

    return convert{id}.func;
}



class Test1
{
public:
    int value()   {return 1;}
    int value2()  {return 2;}
    int value3()  {return 3;}
    int value4()  {return 4;}
};

class Test2
{
public:
    int value()  {return 2;}
};

class Test3
{
public:
    int value()  {return 2;}
};


#define D(a)   cout << #a " = " << a << endl

int main()
{
    D(functionID(&Test1::value));
    D(functionID(&Test1::value2));
    D(functionID(&Test1::value3));
    D(functionID(&Test1::value4));
    D(functionID(&Test2::value));
    D(functionID(&Test3::value));

    return 0;
}

#include <iostream>
using namespace std;

#include "../debug.h"

//fastest way to check odd or even
//works with every integral types (int, short, long, char)
template<class T>
constexpr inline bool isEven(T a)
{
    static_assert(is_integral<T>::value, "Argument must be of integral type");
    return !(a & 1); //or !(a % 2) the are the same
}

template<class T>
constexpr inline bool isOdd(T a)
{
    static_assert(is_integral<T>::value, "Argument must be of integral type");
    return a & 1; //or a % 2 the are the same
}



int main()
{

    DEBUG(isEven(0));
    DEBUG(isEven(1));
    DEBUG(isEven(2));
    DEBUG(isEven(5));

    DEBUG(isOdd(0));
    DEBUG(isOdd(1));
    DEBUG(isOdd(2));
    DEBUG(isOdd(5));

    //custom runtime test
    cout << "=========" << endl;
    
    int value;
    cin >> value;
    
    DEBUG(isEven(value));
    
    return 0;
}

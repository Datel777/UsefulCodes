#include <iostream>
using namespace std;

#include "../debug.h"

//works with every integral types (int, short, long, char)
template<class T>
constexpr inline bool isPowerOf2(T val)
{
    static_assert(is_integral<T>::value, "Argument must be of integral type");
    return val && !(val & (val-1));
}


int main()
{
    int a = 0;
    unsigned char b = 1;
    int16_t c = 2;
    long d = 3;
    long long e = 4;

    DEBUG(isPowerOf2(a));
    DEBUG(isPowerOf2(b));
    DEBUG(isPowerOf2(c));
    DEBUG(isPowerOf2(d));
    DEBUG(isPowerOf2(e));

    cout << endl;

    DEBUG(isPowerOf2(5));
    DEBUG(isPowerOf2(6));
    DEBUG(isPowerOf2(7l));
    DEBUG(isPowerOf2(8ll));

    return 0;
}

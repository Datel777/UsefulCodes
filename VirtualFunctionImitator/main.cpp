//this is very rough virtual function imitation, but should work fast

#include <iostream>

using namespace std;

//little helpers
#define VFI_REALISATION(FUNC_NAME)  VFI_##FUNC_NAME##_
#define VFI_POINTER(FUNC_NAME)      VFI___##FUNC_NAME##___
#define VFI_REGISTER(FUNC_NAME)     VFI_POINTER(FUNC_NAME) = & VFI_REALISATION(FUNC_NAME)


class Base
{
public:
    Base(int health) :
        _health(health)
    {}

    //returns is it alive
    inline bool hit(int damage)  {return VFI_POINTER(hit)(this, damage);}

protected:
    int _health;
    bool (*VFI_POINTER(hit))(Base *, int) = nullptr;

    friend class Derived1;
    friend class Derived2;
};


class Derived1 : public Base
{
public:
    Derived1(int health) :
        Base(health)
    {
        VFI_REGISTER(hit);
        //...
    }

private:
    static bool VFI_REALISATION(hit)(Base *obj, int damage)
    {
        int newDamage = damage / 2;

        cout << "you hitted Derived1 by " << damage << " but he is strong and got " << newDamage << endl;
        obj->_health -= newDamage;

        return obj->_health > 0;
    }
};


class Derived2 : public Base
{
public:
    Derived2(int health) :
        Base(health)
    {
        VFI_REGISTER(hit);
        //...
    }

private:
    static bool VFI_REALISATION(hit)(Base *obj, int damage)
    {
        int newDamage = damage * 2;

        cout << "you hitted Derived2 by " << damage << " but he is weak and got " << newDamage << endl;
        obj->_health -= newDamage;

        return obj->_health > 0;
    }
};

//#define D(a)   cout << #a " = " << a << endl

int main()
{
    Derived1 d1(20);
    Derived2 d2(20);


    if (d1.hit(10))
        cout << "and still alive" << endl;
    else
        cout << "and dead" << endl;


    if (d2.hit(10))
        cout << "and still alive" << endl;
    else
        cout << "and dead" << endl;


    return 0;
}

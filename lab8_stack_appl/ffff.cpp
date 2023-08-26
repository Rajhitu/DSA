#include <iostream>
using namespace std;
class Base
{

public:
    virtual void print() const = 0;
};

class DerivedOne : virtual public Base
{

public:
    void print() const

    {
        cout << "ONE" << endl;
    }
};
class DerivedTwo : virtual public Base
{
public:
    void print() const

    {
        cout << "TWO" << endl;
    }
};
class Multiple : public DerivedOne, DerivedTwo
{

public:
    void print() const

    {
        DerivedTwo::print();
    }
};

int main()
{
    Multiple both;

    Base *p;

    p = &both;

    p->print();
    return 0;
}

#include <iostream>
#include "../head/array.hpp"

int main()
{
    Array<int> a(10);
    a.display();

    a[10];
    a.addArray(11);

    a.delArray();
    a.display();
    a.addArray(11);
    a.display();

    Array<float> b(0);
    b.display();
    b.delArray();
    b.display();
    return 0;
}
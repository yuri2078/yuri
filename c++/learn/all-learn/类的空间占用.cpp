#include <iostream>

class Base
{
public:
    int a;
    int b;
    int c;
};
int main()
{
    Base b1;
    std::cout << "Base 类的空间占用 为 " << sizeof(Base) << "\n";
    std::cout << "Base类对象 的空间占用 为 " << sizeof(b1) << "\n";
    b1.a = 666;
    std::cout << "a = " << b1.a << "\n";
    return 0;
}
#include <iostream>

int max(int x, int y)
{
    return x > y ? x : y;
}

void test()
{
    std::cout << "void test \n";
}

int main(int argc, char const *argv[])
{
    int (*pf)(int, int); //定义函数指针
    pf = max;
    std::cout << "max -- " << pf(55, 66) << std::endl;
    void (*pm)() = test; //定义函数指针
    pm();
    return 0;
}
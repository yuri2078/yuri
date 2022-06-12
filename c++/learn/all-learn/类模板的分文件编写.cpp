#include <iostream>
#include "head/cat.hpp" //自己写的头文件需要加引号


int main()
{
    Cat<std::string, int> c("我擦", 666);
    c.display();
    return 0;
}
#include <iostream>
#include <string.h>
int main()
{
    int *p = new int; //建立一个整形指针，指向新分配的整形地址
    std::cin >> *p;
    std::cout << "*p = " << *p << "\n";
    delete p; //释放内存，有一个new 就必须有一个delete
    char *ch = new char[20];
    strcpy(ch, "hello");
    std::cout << ch << sizeof(ch);
    return 0;
}
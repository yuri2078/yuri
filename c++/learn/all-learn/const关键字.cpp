#include <iostream>

int main(int argc, char const *argv[])
{
    int x = 666, b = 666;
    int *p;

    const int *point = &x; //const 在左边表示他指向的值不能修改
    // *point = 666; //不能修改，报错
    point = &b; //可以修改

    int *const point_2 = &x;
    *point_2 = 666;
    // point_2 = &b; //不能修改，报错

    const int temp = 666;

    return 0;
}
#include <iostream>

int fun(int x = 10, int y = 100) //定义函数的默认参数
{
    return x + y;
}
//只有一个int类型表示占位参数 方便以后更改接口
//含有缺省的函数不可以有默认值
int fun1(int x , int y, int = 10000)
{
    return x + y;
}

int main()
{

    //从左往右都必须要有值
    int fun(int x = 100, int y = 100); //以函数声明的地方的默认值为主。
    std::cout << fun() << std::endl; //可以不传参数
    std::cout << fun(1) << std::endl; //可以只传如一个默认参数
    std::cout << fun(1,200) << std::endl; //可以传两个参数
    std::cout << fun1(100,200) << std::endl; //第三个为占位参数不参与运算，仅仅占位
    std::cout << fun1(100,200,2000) << std::endl; //占位参数可以有默认值，但是别的不能有

    return 0;
}
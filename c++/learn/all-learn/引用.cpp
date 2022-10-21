#include <iostream>

int & fun(void)
{
    static int a = 66666;
    //可以返回别名，但是不可以返回静态变量的别名
    return a;
}

void printValue(const int &a) //加上const防止形参误操作
{
    std::cout << "a = " << a << std::endl;
}



int main()
{
	int a = 66;
	
    int &b = a; //定义别名是必须初始化，且不可以改变
    // int c = 666; b = c; 这就是赋值操作，而不是更改b的指向的操作
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    int &d = fun();
    std::cout << "d = " << d << std::endl;
    fun() = 1234; //因为fun返回a的别名，所以是可以当作左值的可以修改
    std::cout << "d = " << d << std::endl; //下面d是fun返回的a的别名，所以打印了a更改后的值

    // int &e = 10; 这是错误的，引用必须是一个实际存在的地址。
    const int & e = 10; //这是可以的因为这样是创建了一个常量，相当于int temp = 10; int &e = temp; 找不到原名，只有别名
    std::cout << "e = " << e << std::endl;
    //e = 666; 报错，这是只读的不可以修改
    int f = 31;
	printValue(f);
	
    return 0;
}
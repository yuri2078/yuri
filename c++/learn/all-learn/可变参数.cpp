#include <iostream>
#include <stdarg.h> //包含头文件
using std::cout;
using std::endl;
using namespace std;


void fun_1(...)
{
    cout << "普通的可变参数函数" << endl;
    cout << "弊端 ： 只能接受不能处理，提取" << endl;
}

// 参数入栈  从右往左依次进入 最后一个参数是 函数下一条语句的地址，让程序知道返回到哪里

void fun_2(const char *temp, ...)
{
    //弊端 float -> double char->int short->int
    va_list start; //初始化列表
    va_start(start, temp); //初始化start 并且告诉他有几个变量，或从指定位置开始
    int arg_int = va_arg(start, int);
    float arg_float = va_arg(start, double); //报错，因为float 传参数的时候是按doube 传的
    double arg_double = va_arg(start, double);
    char *arg_char = va_arg(start, char *);
    cout << "temp --- " << temp << endl;
    cout << "agr_int - " << arg_int << "  " << endl;
    cout << "agr_float - " << arg_float << "  " << endl;
    cout << "agr_double - " << arg_double << "  " << endl;
    cout << "agr_char - " << arg_char << "  " << endl;
}

template <class T>
void print(const T &temp)
{
    cout << temp << endl;
}


template <class T, class ... Args>
//定义两个模版变量 每次将第一个给 T 剩下的给 args
//这样每次解包递归时，解包的第一个总是给 T 直到解包只有最有一个
void print(const T &temp, Args ...args)
{
    cout << temp << " ";
    print(args ...);
    //当参数只有一个的时候，调用重载的函数打印
}



int main()
{
    fun_1(1, 2, 3, 43, 4);
    fun_2("hello", 1, 2.3f, 4.4, "wocao");
    cout << "少参数调用 --- \n";
    fun_2("yuri", "niubi");
    print("333", 3343, 43.3, 'c', "wjfsidfj", 4.4f);
    return 0;
    
}
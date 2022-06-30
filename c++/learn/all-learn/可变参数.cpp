#include <iostream>
#include <stdarg.h> //包含头文件
#include <stdio.h>
using std::cout;
using std::endl;
using namespace std;

#define LOG(temp,...) printf(temp,__VA_ARGS__)



void fun_1(...)
{
    cout << "普通的可变参数函数" << endl;
    cout << "弊端 ： 只能接受不能处理，提取" << endl;
}

// 参数入栈  从右往左依次进入 最后一个参数是 函数下一条语句的地址，让程序知道返回到哪里

void fun_2(const char *temp, ...)
{
    //弊端 float -> double char->int short->int
    va_list start;
    va_start(start, temp); //让 start 指向 temp
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

int main()
{
    fun_1(1, 2, 3, 43, 4);
    fun_2("hello", 1, 2.3f, 4.4, "wocao");
    cout << "少参数调用 --- \n";
    fun_2("yuri", "niubi");
    LOG("hello", 555);
    return 0;
}
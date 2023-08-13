#include <iostream>
#include <yuri.h>

void f(int a, int b, int c = 10);
void f(int a, int b = 6, int c);
void f(int a = 4, int b, int c);
// 打印4 6 10
// 函数默认实参 : 在函数当前作用域内，在此之前，函数形参的右边必须全部有默认参数
// 原文章： https://zhuanlan.zhihu.com/p/588948013
// https://zh.cppreference.com/w/cpp/language/default_arguments
void f(int a, int b, int c) {
  info << a << "-" << b << "-" << c;
}

// 类 默认参数
class C {
public:
  void f(int i = 10);
  void g(int i, int j = 10);
  C();
};

// void C::f(int i 10) {} 错误，非模板类允许类外函数默认参数与类内相结合，这里重复定义了

// 正确 g中定义了j的默认参数，但是没有i的这里可以定义i的
void C::g(int i = 100, int) {
  info << i;
}

// void C::C(int arg = 10) {} 错误因为重新定义问题，这里构造函数重复了



int main() {
  f(2);
  return 0;
}
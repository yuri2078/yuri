#include <iostream>
#include <yuri.h>

class Person {
public:
  void fun(int x) {
    info << "x -> " << x;
  }
};

// 通过成员函数指针调用
void funn(void (Person::*f)(int), Person &p, int x) {
  (p.*f)(x);
}

int main() {
  Person person;
  // 定义成员函数指针
  void (Person::*f)(int) = &Person::fun;

  (person.*f)(666);
  funn(f, person, 5);

  return 0;
}
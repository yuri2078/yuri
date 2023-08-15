#include <iostream>
#include <yuri.h>

class C {
public:
  C() {
    info << "构造函数!";
  }

  ~C() {
    info << "析构函数!";
  }

  C(const C &) {
    info << "拷贝构造函数!";
  }

  C(C &&) {
    info << "移动构造函数!";
  }

  C operator=(const C &) {
    info << "等号构造函数!";
    return *this;
  }
};

C fun() {
  C c;
  return c;
}

int main() {
  C b = fun();
  return 0;
}
#include <iostream>
#include <vector>

class A {
public:
  int i;
public:
  A() {
    std::cout << "构造函数\n";
  }

  A(const A &a) {
    std::cout << a.i << " 拷贝构造函数\n";
  }

  A(A &&a) {
    std::cout << a.i;
    std::cout << " 移动构造函数!\n";
  }

   A &operator=(const A &a)  {
    std::cout << a.i;
    std::cout << " 等号构造函数!\n";
    return *this;
  }

  std::iostream & operator<<(std::iostream &cout) {
    return cout;
  }

};

int main() {
  A a;
  std::vector<A> vec;
  vec.push_back(std::move(a));
  vec.emplace_back(a);

  return 0;
}

#include <thread>
#include <iostream>

class Fun {
public:
  Fun(int a) {
    std::cout << "fun 构造函数!";
  }

  void operator()() {
    std::cout << "重载()\n";
  }
};

int main() {
  std::thread thread = std::thread(Fun(5));

  thread.join();
  return 0;
}
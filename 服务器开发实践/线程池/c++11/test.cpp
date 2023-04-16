#include <functional>
#include <future>
#include <iostream>
#include <utility>

int func(int &x) {
  std::cout << "左值函数!\n";
  return x;
}
class Pter{};

template <typename Fun, typename... Args>
std::future<int> addTask(Fun &&fun, Args &&...args) {
  std::function<int()> new_fun = std::bind(std::forward<Fun>(fun), std::forward<Args>(args)...);
  std::packaged_task<int()> func(new_fun);
  func();

  return func.get_future();
}

int main() {
  int x = 666;
  auto re = addTask(func, x);
  // std::cout << "return -> " << re.get() <<  std::endl;
  return 0;
}

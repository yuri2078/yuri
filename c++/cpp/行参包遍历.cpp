#include <iostream>

template <typename... Args>
void printf(Args &&...args) {

  // 使用括号表达式 打印完了返回0,解包后初始化成初始化列表
  auto _ = {(std::cout << args << " ", 0)...};
  std::endl(std::cout);

  // 使用折叠表达式打印
  ((std::cout << args << " "), ...);
  std::endl(std::cout);

  ((std::cout << ... << args), std::endl(std::cout));

  std::cout << _.size();
  std::endl(std::cout);
}

// 使用函数重载实现打印可变参数
template <typename T> 
void log(T &&val)  {
  std::cout << val << std::endl;
}

template <typename T,typename ...Args>
void log(T &&val, Args &&...args) {
  std::cout << val << " ";
  log(args...);
}

int main() {
  printf(1, 2, 3, "yuri");
  log(1,2,3,4, "yuri");
  return 0;
}
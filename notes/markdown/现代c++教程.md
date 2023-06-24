# 现代c++教程

> 整理各种乱七八糟的知识 c++17 c++20 c++23

## 可变形参包

```c++
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
void log(T &&val) {
  std::cout << val << std::endl;
}

template <typename T,typename ...Args>
void log(T &&val, Args &&...args) {
  std::cout << val << " ";
  log(args...);
}
```



# 容器

## initializer_list

> std::initializer_list 初始化列表,只读并且不可改变。 能够使用auto 推导

```c++
std::initializer_list<int> num = {1, 2, 3, 4, 5};
// auto num = {1,2,3,4,5};
for (const auto x : num) {
  std::cout << x << " ";
}
std::cout << std::endl;
```


#include <functional>
#include <iostream>
#include <future>
#include <thread>

int main() {
  // 将一个返回值为7的 lambda 表达式封装到 task 中
  // std::packaged_task 的模板参数为要封装函数的类型
  std::packaged_task<int()> task([]() { return 7; });
  // 获得 task 的期物
  std::future<int> result = task.get_future(); // 在一个线程中执行 task
  std::thread(std::move(task)).detach();
  std::cout << "waiting...";
  result.wait(); // 在此设置屏障，阻塞到期物的完成
  // 输出执行结果
  std::cout << "done!" << std::endl
            << "future result is "
            << result.get() << std::endl;
  return 0;
}

template <typename F, typename... Args>
auto submit(F &&f, Args &&...args) -> std::future<decltype(f(args...))> {
  std::function<decltype(f(args...))()> func = std::bind(std::forward<F>(f), std::forward<Args>(args)...); // 连接函数和参数定义，特殊函数类型，避免左右值错误
  auto task_ptr = std::make_shared<std::packaged_task<decltype(f(args...))()>>(func);
  std::function<void()> warpper_func = [task_ptr]() {
      (*task_ptr)();
    };

  // 返回先前注册的任务指针
  return task_ptr->get_future();
}
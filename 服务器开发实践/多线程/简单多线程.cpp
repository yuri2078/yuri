#include <pthread.h>
#include <iostream>
#include <sched.h>

void *ptread_fun(void *arg) {
  static int count = 0;
  count++;
  std::cout << "子线程执行\n";
  return &count;
}


int main() {

  pthread_t *ret = new pthread_t; // 新线程id  unsigned long int
  std::cout << "程序 开始执行\n";

  int *return_val = nullptr;

  // 创建线程并开始执行，默认创建的是非分离线程，也就是可连接线程
  pthread_create(ret, nullptr, ptread_fun, nullptr);

  pthread_join(*ret, (void **)&return_val); // 让程序等待子线程执行完毕再释放资源
  // 如果不加这一句子线程还没执行，主线程就结束了

  std::cout << "返回值" << *return_val << "\n";

  delete ret;
  pthread_exit(nullptr); // 表示主线程结束，但是进程不会退出
  return 0;
}


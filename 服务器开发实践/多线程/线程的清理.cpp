#include <pthread.h>
#include <iostream>
#include <sched.h>
#include <unistd.h>

void clean_fun(void *arg) {
  std::cout << "线程的清理函数调用 -> " << *((int *)arg) << "\n";
}

void *ptread_fun_1(void *arg) {
  std::cout << "线程 (1) 开始运行\n";
  int m = 1;
  pthread_cleanup_push(clean_fun, &m); // 两个配套使用
  return nullptr; // 也会引发清理函数
  pthread_cleanup_pop(0); // 0表示不清理，大于0 表示清理
}

void *ptread_fun_2(void *arg) {
  std::cout << "线程 (2) 开始运行\n";
  int m = 2;
  pthread_cleanup_push(clean_fun, &m);
  // 采用堆栈，将清理函数入栈
  pthread_exit(nullptr); // 会引发清理函数
  pthread_cleanup_pop(0);
}

int main() {

  pthread_t *ret_1 = new pthread_t, *ret_2 = new pthread_t;
  std::cout << "程序 开始执行\n";

  // 创建线程并开始执行，默认创建的是非分离线程，也就是可连接线程
  pthread_create(ret_1, nullptr, ptread_fun_1, nullptr);
  pthread_create(ret_2, nullptr, ptread_fun_2, nullptr);

  // 让主线程等在他执行完毕
  pthread_join(*ret_1, nullptr);
  pthread_join(*ret_2, nullptr);

  std::cout << "主线程结束!\n";
  delete ret_1;
  delete ret_2;
  return 0;
}


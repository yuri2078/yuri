#include <pthread.h>
#include <iostream>
#include <sched.h>
#include <unistd.h>
#include <signal.h>

static void on_signal_term(int sig) {
  std::cout << "信号处理函数 sig -> " << sig << "\n";
  pthread_exit(nullptr);
}

void *ptread_fun(void *arg) {
  // 注册线程
  signal(SIGQUIT, on_signal_term);
  for (int i = 1; i; i++) {
    std::cout << "i -> " << i << "\n";
    sleep(1);
  }
  // 线程主动退出
  return nullptr;
}


int main() {

  pthread_t *ret = new pthread_t; // 新线程id  unsigned long int
  std::cout << "程序 开始执行\n";

  // 创建线程并开始执行，默认创建的是非分离线程，也就是可连接线程
  pthread_create(ret, nullptr, ptread_fun, nullptr);
  sleep(5); // 先休息5s
  int return_val = pthread_kill(*ret, 3);
  // 让主线程等在他执行完毕
  pthread_join(*ret, nullptr);
  std::cout << "return_value -> " << return_val << "\n";
  std::cout << "主线程结束!\n";
  delete ret;
  return 0;
}

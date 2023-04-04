#include <pthread.h>
#include <iostream>
#include <sched.h>
#include <unistd.h>

void *ptread_fun(void *arg) {
  for (int i = 1; i; i++) {
    std::cout << "i -> " << i << "\n";
    sleep(1);
    if (i == 5) {
      // 主动退出
      pthread_exit(nullptr);
    }
  }
  // 线程主动退出
  return nullptr;
}


int main() {

  pthread_t *ret = new pthread_t; // 新线程id  unsigned long int
  std::cout << "程序 开始执行\n";

  // 创建线程并开始执行，默认创建的是非分离线程，也就是可连接线程
  pthread_create(ret, nullptr, ptread_fun, nullptr);

  // 让主线程等在他执行完毕
  pthread_join(*ret, nullptr);
  std::cout << "主线程结束!";
  delete ret;
  return 0;
}


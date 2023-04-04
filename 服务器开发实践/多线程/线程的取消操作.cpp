#include <pthread.h>
#include <iostream>
#include <sched.h>
#include <unistd.h>

void *ptread_fun(void *arg) {

  std::cout << "子线程开始执行!\n";
  for (int i = 1; i; i++) {
    // std::cout << "i -> " << i << "\n";
    sleep(1);
    pthread_testcancel();
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
  int return_val = pthread_cancel(*ret);
  pthread_join(*ret, nullptr);
  
  std::cout << "return_value -> " << return_val << "\n";
  std::cout << "主线程结束!\n";
  delete ret;
  return 0;
}

#include <pthread.h>
#include <thread>
#include <iostream>

using std::cout;
using std::thread;

bool ready = false;

void thfun(int &&val) {
  while (!ready) {
    std::this_thread::yield(); //让出自己的时间片
  }
  for (int i = 0; i < 1000000; i++) {
    
  }
  cout << val << std::endl;
}

int main() {
  cout << "主线程开始\n";

  thread thread_[10];
  for (int i = 0; i < 10; i++) {
    thread_[i] = thread (thfun, i);
    
  }

  ready = true;
  for (int i = 0; i < 10; i++) {
    thread_[i].join();
  }
  cout << "主线程结束执行\n";
  return 0;
}

// thread test;  直接定义不会执行线程 默认定义的是可连接线程，需要使用join 等待结束
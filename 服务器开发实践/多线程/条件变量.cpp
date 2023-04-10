#include <pthread.h>
#include <iostream>
#include <unistd.h>

pthread_cond_t cond; // 新建条件变量
pthread_mutex_t mutex; // 新建互斥锁

int arg = 1;

void *th_fun(void *) {
  for (arg = 1; arg <= 20; arg++) {
    pthread_mutex_lock(&mutex);
    if (arg % 3 == 0) {
      pthread_cond_signal(&cond); // 唤醒
    }
    pthread_mutex_unlock(&mutex);
    sleep(1);
  }

  return nullptr;
}

void *th_fun2(void *) {
  while (arg < 20) {
    pthread_mutex_lock(&mutex);
    if (arg % 3 != 0) {
      pthread_cond_wait(&cond, &mutex); // 等待被唤醒
    }
    std::cout << "arg -> " << arg << std::endl;
    pthread_mutex_unlock(&mutex);

    sleep(1);
    arg++;
  }
  return nullptr;
}

int main() {
  pthread_t th1, th2;
  
  cond = PTHREAD_COND_INITIALIZER; // 初始化条件变量
  pthread_mutex_init(&mutex, nullptr); // 初始化互斥锁

  pthread_create(&th1, nullptr, th_fun, nullptr);
  pthread_create(&th2, nullptr, th_fun2, nullptr);
  pthread_join(th1, nullptr);
  pthread_join(th2, nullptr);

  pthread_cond_destroy(&cond);
  pthread_mutex_destroy(&mutex);
  return 0;
}
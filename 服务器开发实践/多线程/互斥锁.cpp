#include <pthread.h>
#include <iostream>

pthread_mutex_t mutex;
int arg = 0;

void *th_fun(void *) {
  for (int i = 0; i < 100000; i++) {
    pthread_mutex_lock(&mutex);
    arg++;
    pthread_mutex_unlock(&mutex);
  }

  return nullptr;
}

void *th_fun2(void *) {
  for (int i = 0; i < 100000; i++) {
    pthread_mutex_lock(&mutex);
    arg++;
    pthread_mutex_unlock(&mutex);
  }
  return nullptr;
}

int main() {
  pthread_t th1, th2;
  pthread_mutex_init(&mutex, nullptr); // 初始化互斥锁
  for (int i = 0; i < 10; i++) {
    pthread_create(&th1, nullptr, th_fun, nullptr);
    pthread_create(&th2, nullptr, th_fun2, nullptr);
    pthread_join(th1, nullptr);
    pthread_join(th2, nullptr);

    std::cout << "arg -> " << arg << std::endl;
    arg = 0;
  }
  pthread_mutex_destroy(&mutex); // 使用完毕后需要销毁互斥锁
  return 0;
}
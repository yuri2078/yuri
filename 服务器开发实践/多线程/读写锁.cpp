#include <pthread.h>

int mian() {
  pthread_rwlock_t mutex; // 新建读写锁
  mutex = PTHREAD_RWLOCK_INITIALIZER; // 初始化读写锁
  pthread_rwlock_init(&mutex, nullptr);

  pthread_rwlock_rdlock(&mutex); // 读模式上锁 会阻塞线程
  pthread_rwlock_tryrdlock(&mutex); // 读模式尝试上锁 不会阻塞线程

  pthread_rwlock_wrlock(&mutex); // 写模式尝试上锁 会阻塞线程
  pthread_rwlock_trywrlock(&mutex); // 写模式尝试上锁 不会阻塞线程

  // 如果读模式上锁 如果锁在别的读模式上,可以直接读取. 如果在写模式上或者将要到写模式上他就会阻塞

  pthread_rwlock_destroy(&mutex); 
  
  return 0;
}
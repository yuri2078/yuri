#include <pthread.h>
#include <iostream>
#include <sched.h>
#include <unordered_map>
#include <string>

std::unordered_map<int, std::string> map;

extern void mapInit();
extern void getPriority();

void *ptread_fun(void *arg) {
  static int count = 0;
  count++;
  std::cout << "子线程执行\n";
  return &count;
}


int main() {
  mapInit();
  getPriority();

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

void mapInit() {
  map[PTHREAD_CREATE_JOINABLE] = "PTHREAD_CREATE_JOINABLE";
  map[PTHREAD_CREATE_DETACHED] = "PTHREAD_CREATE_DETACHED";
}

// 获取调度策略可设置的最低和最高优先级
void getPriority() {
  int sched_other = SCHED_OTHER; // 分时调度策略。非实时调度 给每个线程分配时间，前一个不完成，是不会执行后面的线程的。没有优先级之分
  int sched_fifo = SCHED_FIFO; // 先来服务调度策略。 实时调度 按照线程创建的时间安排顺序，如果有优先级高的先处理优先级高的
  int sched_rr = SCHED_RR; // 时间片轮转策略。 非每个线程分配时间片，用完了就自己排到最后重新分配时间片 但是支持优先级抢占
  std::cout << "SCHED_OTHER"
            << " " << sched_get_priority_min(sched_other) << " - "
            << sched_get_priority_max(sched_other) << "\n";
  std::cout << "SCHED_FIFO"
            << " " << sched_get_priority_min(sched_fifo) << " - "
            << sched_get_priority_max(sched_fifo) << "\n";
  std::cout << "SCHED_RR"
            << " " << sched_get_priority_min(sched_rr) << " - "
            << sched_get_priority_max(sched_rr) << "\n\n";
}


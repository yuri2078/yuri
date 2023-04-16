#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <chrono>
#include <functional>
#include <future>
#include <queue>
#include <pthread.h>
#include <iostream>
#include <thread>
#include <vector>
#include <memory>
class ThreadPool {
public:
  int x;
  bool is_close;
  pthread_mutex_t mutex;
  pthread_cond_t cond;

  std::vector<pthread_t> threds;
  std::queue<std::function<void()>> tasks;

public:
  ThreadPool(int n = 5) {
    x = 6;
    is_close = false;
    threds = std::vector<pthread_t>(5);

    mutex = PTHREAD_MUTEX_INITIALIZER;
    cond = PTHREAD_COND_INITIALIZER;
  }

  ~ThreadPool() {
    
  }

  void init() {
    int size = threds.size();
    for (int i = 0; i < size; i++) {
      // std::this_thread::sleep_for(std::chrono::seconds(1));
      pthread_create(&threds[i], nullptr, thread, this);
    }
  }

  template <typename Fun, typename... Args>
  auto addTask(Fun &&fun, Args &&...args) -> std::future<decltype(std::__invoke(std::forward<Fun>(fun), std::forward<Args>(args)...))> {
    // 获取返回值
    using return_type = decltype(std::__invoke(std::forward<Fun>(fun), std::forward<Args>(args)...));
    // 绑定函数
    std::function<return_type()> func = std::bind(std::forward<Fun>(fun), std::forward<Args>(args)...);
    auto task_ptr = std::make_shared<std::packaged_task<return_type()>>(func);

    pthread_mutex_lock(&mutex);
    tasks.emplace([task_ptr]() {
      (*task_ptr)();
    });
    pthread_mutex_unlock(&mutex);

    pthread_cond_signal(&cond); // 发送信号
    return task_ptr->get_future();
  }

  static void *thread(void *val) {
    ThreadPool *pool = static_cast<ThreadPool *>(val);
    std::function<void()> fun;
    bool get_task = false;
    while (true) {
      pthread_mutex_lock(&pool->mutex);
      while (pool->tasks.empty() && !pool->is_close) {
        pthread_cond_wait(&pool->cond, &pool->mutex);
      }
      get_task = pool->getTask(fun);
      pthread_mutex_unlock(&pool->mutex);
      if (get_task) {
        fun();
      }

      if (pool->is_close) {
        pthread_exit(nullptr);
      }
    }
    return nullptr;
  }

  void shutDown() {
    is_close = true;
    pthread_cond_signal(&cond);
    int size = threds.size();
    for (int i = 0; i < size; i++) {
      pthread_cond_signal(&cond);
      pthread_join(threds[i], nullptr);
    }
  }

private:
  bool getTask(std::function<void()> &fun) {
    if (tasks.empty()) {
      return false;
    }
    fun = tasks.front();
    tasks.pop();
    return true;
  }
};

#endif
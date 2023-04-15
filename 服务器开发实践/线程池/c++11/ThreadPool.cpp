#include <chrono>
#include <condition_variable>
#include <future>
#include <mutex>
#include <functional>
#include <queue>
#include <thread>
#include <iostream>
#include <utility>
#include <vector>

class ThreadPool {
public:
  bool is_close;
  std::mutex mutex;
  std::condition_variable cv;
  std::queue<std::function<void()>> tasks;
  std::vector<std::thread> threads;

  ThreadPool(int n = 10) {
    is_close = false;
    threads = std::vector<std::thread>(n);
    for (int i = 0; i < n; i++) {
      threads[i] = std::thread(Task(this, i + 1));
    }
  }

  ~ThreadPool() {
    is_close = true;
    cv.notify_all();
    for (int i = 0; i < threads.size(); i++) {
      if (threads[i].joinable()) {
        threads[i].join();
      }
    }
  }

  template <typename Fun, typename... Args>
  void addTask(Fun &&fun, Args &&...args) {
    std::function<decltype(fun(args...))()> func = std::bind(std::forward<Fun>(fun), std::forward<Args>(args)...);
    std::packaged_task<decltype(fun(args...))()> packaged(func);
    std::shared_future<decltype(fun(args...))> future = packaged.get_future();
    tasks.emplace([func]() {
      func();
    });

    cv.notify_one();
  }

private:
  class Task {
  private:
    ThreadPool *pool;
    int id;

  public:
    Task(ThreadPool *pool, int id) {
      this->pool = pool;
      this->id = id;
    }

    void operator()() {
      //   std::cout << id << " 启动\n";
      std::function<void()> fun;
      while (!pool->is_close || !pool->tasks.empty()) {
        {
          std::unique_lock<std::mutex> lock(pool->mutex);
          if (pool->tasks.empty()) {
            // std::cout << id << " 休眠!\n";
            pool->cv.wait(lock);
          } else {
            fun = pool->tasks.front();
            pool->tasks.pop();
            std::cout << id << " ";
            fun();
          }
        }
      }
    }
  };
};

void fun(const int i) {
  std::cout << "task -> " << i << std::endl;
}

int main() {
  ThreadPool pool;
  for (int i = 0; i < 10; i++) {
    pool.addTask(fun, i);
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }

  std::cout << "主函数结束!\n";
  return 0;
}

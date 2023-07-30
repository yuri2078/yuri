#ifndef THREADPOOL_H
#define THREADPOOL_H

#include <condition_variable>
#include <future>
#include <memory>
#include <mutex>
#include <functional>
#include <queue>
#include <thread>
#include <iostream>
#include <utility>
#include <vector>

// 线程池类
class ThreadPool {
public:
  bool is_close;                           // 是否关闭线程池
  std::mutex mutex;                        // 互斥锁
  std::condition_variable cv;              // 条件变量
  std::queue<std::function<void()>> tasks; // 存放待执行的任务
  std::vector<std::thread> threads;        // 存放线程

  // 构造函数,默认初始化 5 个线程.此时线程并不会直接启动
  ThreadPool(int n = 5) {
    is_close = false;
    threads = std::vector<std::thread>(n);
  }

  // 禁止任何 移动复制 等号初始化
  //   ThreadPool(const ThreadPool &) = default;
  //   ThreadPool(ThreadPool &&) = default;
  ThreadPool &operator=(const ThreadPool &) = delete;
  ThreadPool &operator=(ThreadPool &&) = delete;

  // 析构函数,调用shutdown 结束所有任务
  ~ThreadPool() {
    shutDown();
  }

  // 启动所有线程
  void init() {
    int size = threads.size();
    for (int i = 0; i < size; i++) {
      threads[i] = std::thread(Task(this, i + 1));
    }
  }

  // 添加任务
  // Fun &&fun 函数模板
  // Args &&...args 可变参数包接受函数参数
  // std::future<decltype(fun(args...)) 后置auto 返回类型推导
  // decltype(fun(args...) 自动推导表达式的值
  // std::__invoke(函数名,函数内容) 执行函数 并且返回函数的返回值
  // decltype(std::__invoke(std::forward<Fun>(fun), std::forward<Args>(args)...) 获取函数的返回值
  // using return_type = decltype(std::__invoke(... 获取返回值类型
  // std::bind(std::forward<Fun>(fun), std::forward<Args>(args)...) 使用std::bind 包装函数,将参数完美转发过去

  // std::shared_ptr<std::packaged_task<decltype(fun(args...))()>> task_ptr 封装一个shard ptr
  // std::packaged_task<decltype(return_type)()> 封装了一个函数task,返回值是 return_type 参数是void
  // std::make_shared<std::packaged_task<decltype(fun(args...))()>> (func) 创建一个shared ptr,参数是之前的函数

  // addTask 函数结束后 task_ptr 的计数不是0 是 1 ,因为之前lambda 中 捕获了一次,所以只有当task 函数被执行才会析构
  // 所以不存 return task_ptr->get_future();后就被析构了问题
  template <typename Fun, typename... Args>
  auto addTask(Fun &&fun, Args &&...args) -> std::future<decltype(std::__invoke(std::forward<Fun>(fun), std::forward<Args>(args)...))> {
    // 获取返回值
    using return_type = decltype(std::__invoke(std::forward<Fun>(fun), std::forward<Args>(args)...));
    // 绑定函数
    std::function<return_type()> func = std::bind(std::forward<Fun>(fun), std::forward<Args>(args)...);
    auto task_ptr = std::make_shared<std::packaged_task<return_type()>>(func);

    {
      std::unique_lock<std::mutex> lock(mutex);
      tasks.emplace([task_ptr]() {
        (*task_ptr)();
      });
    }
    
    cv.notify_one();

    return task_ptr->get_future();
  }

  // 关闭线程池
  void shutDown() {
    is_close = true; // 将关闭标志设置为false 防止线程一直阻塞
    cv.notify_all(); // 唤醒所有线程 处理任务或者结束线程
    // 将所有还没执行完的线程等待执行
    for (unsigned i = 0; i < threads.size(); i++) {
      if (threads[i].joinable()) {
        threads[i].join();
      }
    }
  }

private:
  bool getTask(std::function<void()> &fun) {
    // std::unique_lock<std::mutex> lock(mutex);
    if (tasks.empty()) {
      return false;
    }
    fun = tasks.front();
    tasks.pop();
    return true;
  }

private:
  // 任务类
  class Task {
  private:
    ThreadPool *pool; // 任务所属线程池
    int id;           // 任务id

  public:
    // 构造函数设置线程池,并且
    Task(ThreadPool *pool, int id) {
      this->pool = pool;
      this->id = id;
    }

    // 重载()()
    // 创建线程传入的的Task类,他会一直调用Task()();
    void operator()() {
      std::function<void()> fun;
      bool has_task = false;
      while (!pool->is_close) {
        {
          std::unique_lock<std::mutex> lock(pool->mutex);
          if (pool->tasks.empty()) {
            std::cout << id << " 休眠\n";
            // 等待唤醒,这时会自动解锁
            pool->cv.wait(lock);
          }
          has_task = pool->getTask(fun);
        }

        // 如果获得了任务就进行处理
        if (has_task) {
          std::cout << id << " ";
          fun();
        }
      }
    }
  };
};

#endif
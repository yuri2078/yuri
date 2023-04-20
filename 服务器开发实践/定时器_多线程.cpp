#include <chrono>
#include <iostream>
#include <sys/epoll.h>
#include <functional>
#include <thread>
#include <set>
#include <condition_variable>
#include <mutex>
#include <utility>

using namespace std;

// 定时器节点
class TimerNode {
public:
  uint64_t id;   // 节点id
  uint64_t mesc; // 需要调用定时器的时间

public:
  // 定义回调函数
  using callBack = std::function<void()>;
  callBack fun;

public:
  // 默认构造函数
  TimerNode(uint64_t mesc, uint64_t id, callBack fun) {
    this->mesc = mesc;
    this->fun = fun;
    this->id = id;
  }
};

bool operator<(const TimerNode &x, const TimerNode &y) {
  if (x.mesc == y.mesc) {
    return x.id < y.id;
  }
  return x.mesc < y.mesc;
}

class Timer {
private:
  using int_ = uint64_t;

  static int_ id; // 定时器id

  thread thread_; //定时器线程
  bool is_close; // 是否关闭的定时器
  set<TimerNode> nodes; // 定时器节点
  mutex mutex_; // 互斥锁
  condition_variable cv; // 条件变量

public:
  // 获取当前时间
  static time_t getNowTime() {
    auto sc = chrono::time_point_cast<chrono::milliseconds>(chrono::steady_clock::now());
    auto temp = chrono::duration_cast<chrono::milliseconds>(sc.time_since_epoch());
    return temp.count();
  }

  // 添加节点
  template <typename Fun, typename... Args>
  void addTimerNode(int_ mesc, Fun &&fun, Args &&...args) {
    function<void()> func = bind(std::forward<Fun>(fun), forward<Args>(args)...);
    int_ now = getNowTime();
    {
      unique_lock<mutex> lock(mutex_);
      nodes.insert(TimerNode(now + mesc, ++id, func));
    }
    cv.notify_one();
  }

  Timer() : is_close(false){
    
  }
  // 默认析构函数,释放掉没有执行的定时器任务
  ~Timer() {
    is_close = true;
    cv.notify_one();
    if (thread_.joinable()) {
      thread_.join();
    }
    
  };

  // 多线程函数
  static void threadFun(Timer *timer) {
    if (timer == nullptr) {
      return;
    }
    // 不断循环直到定时器任务为空并且is_close 为true
    while (true) {
      int_ now = getNowTime();
      {
        // 上锁开始价差是否结束
        unique_lock<mutex> lock(timer->mutex_);
        if (timer->nodes.empty()) {
          if (timer->is_close) {
            break;
          }
          timer->cv.wait(lock);
        }

        if (!timer->nodes.empty()) {
          auto node = timer->nodes.begin();
          if (node->mesc > now) {
            this_thread::sleep_for(chrono::milliseconds(node->mesc - now));
          }
          node->fun();
          timer->nodes.erase(node);
        }
      }
    }
  }

  // 启动定时器
  void start() {
    thread_ = thread(Timer::threadFun, this);
  }
};

uint64_t Timer::id = 0;

int main() {
  Timer timer;
  timer.start();
  for (int i = 0; i < 200; i++) {
    timer.addTimerNode(5 * i, [=]() {
      std::cout << "测试 -> " << i << "\n"; 
    });
  }
  

  return 0;
}
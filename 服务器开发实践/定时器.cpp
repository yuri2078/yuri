#include <chrono>
#include <iostream>
#include <sys/epoll.h>
#include <functional>
#include <set>

using namespace std;

// 定时器节点
class TimerNode {
public:
  uint64_t id; // 节点id
  uint64_t mesc; // 需要调用定时器的时间

public:
  // 定义回调函数
  using callBack = std::function<void(TimerNode &timer)>;
  callBack fun;

public:
  // 默认构造函数
  TimerNode(uint64_t mesc, uint64_t id, callBack fun) {
    this->mesc = mesc;
    this->fun = fun;
    this->id = id;
  }
};

class Timer {
private:
  // set 数组比较函数,用来对定时器节点进行比较
  static bool MyCom(const TimerNode *x, const TimerNode *y) {
    if (x->mesc == y->mesc) {
      return x->id < y->id;
    }
    return x->mesc < y->mesc;
  }

  // 静态成员,用来存储定时器id
  static uint64_t id;

  // 用来存放定时器,拥有自定义排序功能
  set<TimerNode *, bool (*)(const TimerNode *, const TimerNode *)> timer{MyCom};

public:
  // 获取当前时间
  static time_t getNowTime() {
    auto sc = chrono::time_point_cast<chrono::milliseconds>(chrono::steady_clock::now());
    auto temp = chrono::duration_cast<chrono::milliseconds>(sc.time_since_epoch());
    return temp.count();
  }

  Timer() = default;
  // 默认析构函数,释放掉没有执行的定时器任务
  ~Timer() {
    for (auto begin = timer.begin(); begin != timer.end(); begin++) {
      delete *begin;
    }
  };

  // 添加定时器任务
  void addTimer(uint64_t mesc, const function<void(TimerNode &node)> &fun) {
    timer.insert(new TimerNode(mesc + getNowTime(), ++id, fun));
  }

  // 返回最快执行定时器到现在的时间
  uint64_t timeToSleep() {
    uint64_t now = getNowTime(); // 获取现在时间
    set<TimerNode *>::iterator begin = timer.begin(); // 获取最小执行时间定时器

    // 如果没找到就返回最大时间
    if (begin == timer.end()) {
      return -1;
    }
    // 返回他们的差值, 不考虑最低时间小于当前时间
    return (*begin)->mesc - now;
  }

  // 检查是否有可以执行的定时器,如果没有就返回false
  bool chechTimer() {
    uint64_t now = getNowTime();// 获取现在的时间
    set<TimerNode *>::iterator begin = timer.begin(); // 获取最小执行时间的定时器
                                                
    // 如果没有末尾,并且已经到执行时间
    if (begin != timer.end() && (*begin)->mesc <= now) {
      
      (*begin)->fun(**begin); // 调用回调函数
      timer.erase(begin); // 删除定时器
      delete *begin; // 析构掉new 的内存
      return true; // 执行成功返回true
    }

    // 没找到或者没有到时间则返回false
    return false;
  }
};

uint64_t Timer::id = 0;

int main() {
  int epfd = epoll_create(1);
  epoll_event ev[64] = {};
  Timer timer;
  for (int i = 1; i < 10; i++) {
    // 添加定时器
    timer.addTimer(1000 * i, [](TimerNode &node) {
      std::cout << "id -> " << node.id << " mesc -> " << node.mesc << endl;
    });
  }

  while (true) {
    uint64_t mesc = timer.chechTimer();
    // 获取最小等待时间
    int n = epoll_wait(epfd, ev, 64, mesc);
    // timeout 的取值
    // 0 立即返回
    // -1 永久阻塞
    // > 0 阻塞 mesc 毫秒
    for (int i = 0; i < n; i++) {
    }

    // 循环处理当前时间节点的定时器任务
    while (timer.timeToSleep()) {
    }
  }

  return 0;
}
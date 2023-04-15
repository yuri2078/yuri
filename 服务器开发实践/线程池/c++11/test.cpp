#include <atomic>
#include <chrono>
#include <iostream>
#include <thread>

class MyThread {
public:
  MyThread() : is_close_(false) {
    thread_ = std::thread(&MyThread::Task, this);
  }

  ~MyThread() {
    is_close_ = true;
    if (thread_.joinable()) {
      thread_.join();
    }
  }

private:
  std::thread thread_;
  std::atomic<bool> is_close_;

  void Task() {
    while (!is_close_) {
      std::cout << "Thread is running!\n";
    //   std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Thread is stopped!\n";
  }
};

int main() {
  {
    MyThread thread;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  std::cout << "Main thread is done!\n";
  return 0;
}

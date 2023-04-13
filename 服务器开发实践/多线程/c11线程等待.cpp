#include <chrono>
#include <ctime>
#include <pthread.h>
#include <thread>
#include <iostream>

using std::cout;
using std::thread;

bool ready = false;

void getNowTime() {
  std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::tm *tm = std::localtime(&time);
  std::cout << tm->tm_hour << " 时 " << tm->tm_min << " 分 " << tm->tm_sec << "秒\n";
}

void thfun(int &val) {
  cout << "子线程开始执行 -> ";
  cout << val << std::endl;
  std::time_t time = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
  std::tm *tm = std::localtime(&time);
  tm->tm_min++;
  tm->tm_sec = 0;
  // 休息到指定时间
  std::this_thread::sleep_until(std::chrono::system_clock::from_time_t(mktime(tm)));
}

void thfun_(std::string &&val) {
  cout << "子线程开始执行 -> ";
  //   休息指定秒数
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

int main() {
  cout << "主线程开始\n";

  getNowTime();
  thread thread_(thfun, 1);
  thread_.join();
  getNowTime();
  cout << "主线程结束执行\n";
  return 0;
}

#include <iostream>
#include <chrono>

class Log {
public:
  Log(bool) {
    std::cout << "\x1b[31m";
    sendMsg();
  }

  Log() {
    sendMsg();
  }

  void sendMsg() {
    std::time_t currentTime_t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm* localTime = std::localtime(&currentTime_t);
    std::cout << "[" << std::put_time(localTime, "%H:%M:%S");
    std::cout << " " << __FILE__ << ":"  <<  __LINE__ << "] ";
  }

  template <typename T>
  Log &operator<<(T &&val) {
    std::cout << val;
    return *this;
  }

  ~Log() {
    std::cout << "\x1b[0m\n";
  }
};

#define info Log()
#define error Log(false)

int main() {
  // Log << 1 << 2;
  error << "信息错误!";
  return 0;
}

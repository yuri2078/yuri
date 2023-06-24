#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <source_location>

class Log {
public:
  Log(std::source_location &&loc, bool) noexcept :loc(loc)  {
    std::cout << "\x1b[31m";
    sendMsg();
  }

  Log(std::source_location &&loc) noexcept: loc(loc) {
    sendMsg();
  }

  template <typename T>
  Log &operator<<(T &&val) {
    std::cout << val;
    return *this;
  }

  ~Log() {
    std::cout << "\x1b[0m\n";
  }

private:
  std::source_location &loc;
  void sendMsg() {
    std::chrono::time_point now = std::chrono::system_clock::now();
    std::time_t t_c = std ::chrono::system_clock::to_time_t(now);
    std::size_t ms = static_cast<std::size_t>(
      (now - std ::chrono ::system_clock::from_time_t(t_c)).count());
    const struct tm tm = *std ::localtime(&t_c);

    // 输出日志信息
    std ::cout << "[" << std::put_time(&tm, "%Y-%m-%d %H:%M:%S") << "."
               << std::setfill('0')
               << std::setw(3)
               << ms << "]"
               << " " << loc.file_name() << ":" << loc.line() << ": ";
  }
};

int main() {
  Log(std::source_location::current()) << "yuri is yes";
  return 0;
}
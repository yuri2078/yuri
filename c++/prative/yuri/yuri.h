//
// Created by yuri on 22-11-10.
//

#ifndef LOG_YURI_H
#define LOG_YURI_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/socket.h>
#include <chrono>

// class MyIterator : public std::iterator<std::random_access_iterator_tag, T t>

namespace yuri

{
class Yuri {
private:
  bool is_single;
  std::string in_file;
  std::string out_file;
  unsigned int col;
  unsigned int row;
  std::unique_ptr<std::vector<std::vector<int>>> data;
  std::unique_ptr<std::vector<int>> data_single;

public:
  Yuri() {
    is_single = false;
    this->in_file = "in.txt";
    this->out_file = "out.txt";
    this->col = 0;
    this->row = 0;
    data = nullptr;
    data_single = nullptr;
  }

  ~Yuri() = default;

  std::vector<std::vector<int>> &getData() {
    std::fstream fst;
    checkFile(fst, in_file, std::ios::in);
    fst >> row >> col;
    data = std::make_unique<std::vector<std::vector<int>>>(
      row, std::vector<int>(col));
    for (size_t i = 0; i < row; i++) {
      for (size_t j = 0; j < col; j++) {
        fst >> (*data)[i][j];
      }
    }
    fst.close();
    return (*data);
  }

  std::vector<int> &getData(bool) {
    this->is_single = true;
    this->row = 1;
    std::fstream fst;
    checkFile(fst, in_file, std::ios::in);
    fst >> col;
    data_single = std::make_unique<std::vector<int>>(col);
    for (size_t i = 0; i < col; i++) {
      fst >> (*data_single)[i];
    }
    fst.close();
    return (*data_single);
  }

  void outData(bool clean_ = false) {
    std::fstream fst;
    if (clean_) {
      checkFile(fst, out_file, std::ios::out);
    } else {
      checkFile(fst, out_file, std::ios::app);
    }

    if (is_single && data_single) {
      for (int x : (*data_single)) {
        fst << x << " ";
      }
      fst << "\n";
    } else if (data) {
      for (auto v : (*data)) {
        for (int x : v) {
          fst << x << " ";
        }
        fst << "\n";
      }
    }
    fst.close();
  }

  template <typename T>
  Yuri &operator<<(T value) {
    std::fstream fst;
    checkFile(fst, out_file, std::ios::app);
    fst << value;
    fst.close();
    return *this;
  }

  void checkFile(std::fstream &fst, std::string &load, std::ios_base::openmode __mode) {
    fst.open(load, __mode);
    if (!fst.is_open()) {
      // 打开失败则新建一个
      if (__mode == std::ios::in) {
        std::cout << "\n\n文件读取 打开错误! 错误位置 " << load << std::endl;
        std::exit(2);
      }
      fst.open(load, std::ios::out);
      if (!fst.is_open()) {
        std::cout << "\n\n文件打开错误! 错误位置 " << load << std::endl;
        std::exit(3);
      }
    }
  }
  void cleanLog() {
    std::fstream fst;
    fst.open(out_file, std::ios::out);
    fst.close();
  }

  template <typename T, typename... Args>
  static clock_t used_time(T cp, Args &&...args) {
    clock_t start, end;
    start = clock();
    cp(args...);
    end = clock();
    return end - start;
  }

  std::string setOutFile(std::string &&out) {
    this->out_file = out;
    return this->out_file;
  }

  std::string setInFile(std::string &&out) {
    this->out_file = out;
    return this->out_file;
  }
};

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
    std::tm *localTime = std::localtime(&currentTime_t);
    std::cout << "[" << std::put_time(localTime, "%H:%M:%S");
    std::cout << " " << __FILE__ << ":" << __LINE__ << "] ";
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

} // namespace yuri

#endif // LOG_YURI_H

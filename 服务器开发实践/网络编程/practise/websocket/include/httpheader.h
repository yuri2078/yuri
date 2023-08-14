#ifndef HTTPHEADER_H
#define HTTPHEADER_H

#include <format>
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>

class HttpHeader {
public:
  HttpHeader(const std::string &header) :
    header(header) {
    splitData();
  }

  std::string readFile(const std::string &filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
      return "";
    }
    std::ostringstream buffer;
    buffer << file.rdbuf();
    file.close();
    return buffer.str();
  }

private:
  std::string header;
  
  void splitData() {
    getData("Host");
    getData("Sec-Fetch-Dest");
    getData("Referer");
    getData("Cookie");
    getData("Origin");
    getData("Host");

    {
      int start = 0;
      while (header[start] != ' ' && header[start]) {
        start++;
      }
      message["request_type"] = header.substr(0, start);
      start++;
      int end = start;
      while (header[end] != ' ' && header[end]) {
        end++;
      }
      message["request_path"] = header.substr(start, end - start);
      start = header.find_last_of("{");
      if (start < header.size()) {
        message["message"] = header.substr(start, header.size() - start);
      } else {
        message["message"] = "none";
      }
    }
  }

public:
  std::unordered_map<std::string, std::string> message;

  void getData(const std::string &msg) {
    int pos = header.find(msg);
    if (pos == std::string::npos) {
      return;
    }
    int start = pos + msg.size() + 2, end = start;
    while (header[end] != '\r' && header[end] != '\n') {
      end++;
    }
    message[msg] = header.substr(start, end - start);
  }

  std::string toString() {
    std::string msg("\n");
    for (auto iter : message) {
      msg.append(std::format("{} : {}\n", iter.first, iter.second));
    }
    return msg;
  }
};

#endif
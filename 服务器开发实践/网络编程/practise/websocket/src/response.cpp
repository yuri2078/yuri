#include "../include/response.h"
#include "httptype.h"

#include <iostream>
#include <sstream>
#include <fstream>

namespace yuri {
Response::Response(const std::string &header, const int client) :
  header(header), status_type(StatusType::OK), root_path(""), client_(client) {
  root_path = "/home/yuri/yuri/服务器开发实践/网络编程/practise/websocket/dist";
  setContent(ContentType::text, 0);
  int start = 0;
  while (header[start] != ' ' && header[start]) {
    start++;
  }
  request_type = header.substr(0, start) == "GET" ? RequestType::GET : RequestType::POST;
  start++;
  int end = start;
  while (header[end] != ' ' && header[end]) {
    end++;
  }
  request_path = header.substr(start, end - start);
  start = header.find_last_of("{");
  if (start < header.size()) {
    message = header.substr(start, header.size() - start);
  } else {
    message = "none";
  }
}

std::string Response::readFile(const std::string &file_name) {
  std::ifstream file(root_path + file_name, std::ios::binary);
  if (!file) {
    return "";
  }
  std::ostringstream buffer;
  buffer << file.rdbuf();
  file.close();
  buffer.str();
  return buffer.str();
}

std::string Response::httpHeader() {
  return Type::getType(status_type) + Type::getType(content_type) + content_length + Type::cross + "Connection: close\r\n\r\n";
}

Response::~Response() {
}

void Response::setStatusType(StatusType value) {
  status_type = value;
}

void Response::setRequestType(RequestType value) {
  request_type = value;
}

void Response::setContent(ContentType type, unsigned length) {
  content_length = "Content-Length: " + std::to_string(length) + "\r\n";
  content_type = type;
}

std::string Response::getRequestPath() const {
  return request_path;
}

int Response::client() const {
  return client_;
}

} // namespace yuri

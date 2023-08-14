#include "../include/response.h"
#include "httptype.h"

#include <sstream>
#include <fstream>

namespace yuri {
Response::Response(const std::string &header) :
  header(header) {
  setStatusType(StatusType::OK);
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
  std::ifstream file(file_name, std::ios::binary);
  if (!file) {
    return "";
  }
  std::ostringstream buffer;
  buffer << file.rdbuf();
  file.close();
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

void Response::setContent(ContentType value, unsigned size) {
  content_length = "Content-Length: " + std::to_string(size) + "\r\n";
  content_type = value;
}

std::string Response::getRequestPath() const {
  return request_path;
}

} // namespace yuri

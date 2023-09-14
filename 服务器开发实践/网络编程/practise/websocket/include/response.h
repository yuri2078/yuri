#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>
#include "type.h"

namespace yuri::web {

class Response {
  
public:
  // 根据函数参数发送响应 默认发送请求的响应
  static std::string response(const ContentType, const unsigned long int lenght, const Status = Status::OK);
  static std::string response(std::string_view file_name, const unsigned long int size, ContentType type);
  static ContentType getContentType(const FileType type);

private:
  static std::string getTypeString(const Status status);
  static std::string getTypeString(const ContentType type);
  static std::string getTypeString(const unsigned long int length);

private:
  Status status;
  ContentType type;
  unsigned lenght;
};

} // namespace yuri::web

#endif

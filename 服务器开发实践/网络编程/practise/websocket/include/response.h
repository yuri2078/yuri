#ifndef RESPONSE_H
#define RESPONSE_H

#include <string>

namespace yuri::web {

class Response {
public:
  enum Status {
    OK = 200,
    Created = 201,
    Accepted = 202,
    NoContent = 204,
    MovedPermanently = 301,
    Found = 302,
    BadRequest = 400,
    Unauthorized = 401,
    Forbidden = 403,
    NotFound = 404,
    InternalServerError = 500
  };

  enum Type {
    html,
    icon,
    css,
    js,
    text,
    picture
  };

public:
  // 根据函数参数发送响应 默认发送请求的响应
  static std::string response(const Type, const unsigned lenght, const Status = Status::OK);

private:
  static std::string getTypeString(const Status status);
  static std::string getTypeString(const Type type);
  static std::string getTypeString(const unsigned length);

  
private:
  Status status;
  Type type;
  unsigned lenght;
};

} // namespace yuri::web

#endif

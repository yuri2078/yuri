#ifndef RESPONSE_H
#define RESPONSE_H
#include "httptype.h"

namespace yuri {

class Response {
public:
  Response(const std::string &header, const int client);
  virtual ~Response();

  std::string readFile(const std::string &file_name);

  std::string httpHeader();

  void setStatusType(StatusType value);
  void setRequestType(RequestType value);
  void setContent(ContentType type, unsigned length);
  
  std::string getRequestPath() const;

  int client() const;

private:
  StatusType status_type;   // 状态码
  RequestType request_type; // 请求类型
  ContentType content_type; // 文件类型

  std::string request_path; // 请求路径
  std::string content_length; // 请求长度
  std::string header;       // 报文头源数据
  std::string cross;        // 跨域头
  std::string message;      // 消息体
  std::string root_path;    // 根路径
  std::string file_name;    // 文件名

private:
  void init();
  int client_;
};

} // namespace yuri

#endif

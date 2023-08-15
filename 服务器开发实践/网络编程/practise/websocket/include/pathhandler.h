#ifndef PATHHANDLER_H
#define PATHHANDLER_H

#include "httptype.h"
#include "response.h"
#include "webserver.h"
#include <memory>

namespace yuri {
class PathHandler {
public:
  PathHandler(WebServer *server, Response *response);
  virtual ~PathHandler();

  // 向指定客户端发送文件
  void sendFile(const std::string &file_name, ContentType type);

private:
  WebServer *server;
  Response *response;
};
}

#endif
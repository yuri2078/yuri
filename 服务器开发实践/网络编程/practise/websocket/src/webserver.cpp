#include "../include/webserver.h"
#include "response.h"
#include "request.h"
#include "type.h"
#include <memory>
#include <sstream>
#include <fstream>

namespace yuri {

WebServer::WebServer(const sock_t port, const std::string ip) :
  fd(-2078), addr({}) {
  init();
  if (ip == "any") {
    addr.setAddress(INADDR_ANY);
  } else {
    addr.setAddress(ip);
  }
  getMapping("/", [this](int client) {
    std::string file(readFile("../dist/index.html"));
    result(client, web::Status::OK, web::ContentType::html, file);
  });

  getMapping("/favicon.ico", [this](int client) {
    std::string file(readFile("../dist/favicon.ico"));
    result(client, web::Status::OK, web::ContentType::icon, file);
  });

  getMapping("/yuri.png", [this](int client) {
    std::string file(readFile("/home/yuri/Pictures/yuri/wallhaven-1pd1o9_3840x2160.png"));
    result(client, web::Status::OK, web::ContentType::picture, file);
  });
  addr.setPort(port);
}

WebServer::~WebServer() {
  if (fd != -2078) {
    ::close(fd);
  }

  // 结束僵尸线程并关闭连接释放资源
  for (auto iter = users.begin(); iter != users.end(); iter++) {
    if (threads[iter->first].joinable()) {
      threads[iter->first].join();
    }
    ::close(iter->first);
  }
}

bool WebServer::listen() {
  // 创建socket
  fd = ::socket(AF_INET, SOCK_STREAM, 0);
  if (fd <= 0) {
    error << "创建socket 失败!";
    error << strerror(errno);
    return false;
  }

  // 绑定本地ip 地址
  if (::bind(fd, addr.addr(), addr.size()) == -1) {
    error << "绑定地址失败!";
    error << strerror(errno);
    return false;
  }

  // 开启监听
  if (::listen(fd, 20) == -1) {
    error << "监听失败!";
    error << strerror(errno);
    return false;
  }
  info << fd << " 正在监听 ip -> " << addr.getAddress() << " " << addr.getPort();
  return true;
}

int WebServer::accept() {
  Sockaddr client_addr;
  int client = ::accept(fd, client_addr.addr(), addr.size_p());
  if (client <= 0) {
    error << "监听客户端失败!";
    error << strerror(errno);
    return -1;
  }

  users[client] = client_addr; // 添加进map
  info << "客户端 -> " << client << " 已经连接 ! ";
  users[client].setStatus(SocketState::客户端);
  client_addr.showInfo();
  // 创建新线程接受信息
  threads[client] = std::thread([this, client]() {
    this->recv(client);
  });
  return client;
}

// 向指定client 发送信息
bool WebServer::writeToClient(const int client, const std::string msg) {
  if (users.find(client) == users.end() || users[client].getStatus() == SocketState::未连接) {
    error << "没有该用户,或者该用户已经断开连接!";
    return false;
  }

  int ret = ::send(client, msg.c_str(), msg.size(), 0);
  if (ret <= 0) {
    error << "发送失败!";
    error << strerror(errno);
    return false;
  }
  return true;
}

int WebServer::recv_(const int client, char *buf, sock_t size) {
  int ret = ::recv(client, buf, size, 0);
  if (ret == 0) {
    info << std::format("{} 断开连接!", client);
    users[client].setStatus(SocketState::未连接);
    return 0;
  }
  if (ret < 0) {
    error << "读取报文出错!";
    error << strerror(errno);
    return 0;
  }

  return ret;
}

// 接受数据
void WebServer::recv(const int client) {
  while (true) {
    char buff[999999]{};
    if (recv_(client, buff, 1024) > 0) {
      using namespace yuri::web;
      std::shared_ptr<Request> request = std::make_shared<Request>(buff);
      info << request->showInfo() << "\n" << buff;
      if (request->fileType() == web::FileType::script || request->fileType() == web::FileType::style) {
        getMapping(request->path(), [this, request](int client) {
          std::string file(readFile("../dist" + request->path()));
          web::ContentType type = Response::getContentType(request->fileType());
          result(client, web::Status::OK, type, file);
        });
      }

      if (request->requestType() == RequestType::GET) {
        auto fun = get_func.find(request->path());
        if (fun != get_func.end()) {
          get_func[request->path()](client);
        } else {
          result(client, web::Status::NotFound, ContentType::text, "没找到捏!");
        }

      } else {
        auto fun = post_func.find(request->path());
        if (fun != post_func.end()) {
          post_func[request->path()](client);
        } else {
          result(client, web::Status::NotFound, ContentType::text, "没找到捏!");
        }
      }

    } else {
      return;
    }
  }
}

void WebServer::init() {

}

void WebServer::result(int client, web::Status status, web::ContentType type, std::string msg) {
  std::string response(web::Response::response(type, msg.length()));
  writeToClient(client, response);
  writeToClient(client, msg);
}

void WebServer::getMapping(std::string path, std::function<void(int client)> func) {
  get_func[path] = func;
}

std::string WebServer::readFile(const std::string &file_name) {
  std::ifstream file(file_name, std::ios::binary);
  if (!file) {
    error << "未找到文件 -> " << file_name;
    return "";
  }
  std::ostringstream buffer;
  buffer << file.rdbuf();
  file.close();
  return buffer.str();
}
} // namespace yuri
#include "../include/webserver.h"
#include "response.h"
#include "request.h"
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
    char buff[1024]{};
    static auto readFile = [](const std::string &file_name) ->std::string {
      std::ifstream file(file_name, std::ios::binary);
      if (!file) {
        error << "未找到文件 -> " << file_name;
        return "";
      }
      std::ostringstream buffer;
      buffer << file.rdbuf();
      file.close();
      return buffer.str();
    };
    if (recv_(client, buff, 1024) > 0) {
      using namespace yuri::web;
      std::shared_ptr<Request> request = std::make_shared<Request>(buff);
      info << request->showInfo();
      if (request->type() == Request::GET) {
        std::string file;
        if (request->path() == "/") {
          file = readFile("../dist/index.html");
        } else {
          file = readFile("../dist" + request->path());
        }
        std::string response = Response::response(Response::html, file.size());
        writeToClient(client, response);
        writeToClient(client, file);
      }
      
    } else {
      return;
    }
  }
}

void WebServer::init() {

}







} // namespace yuri
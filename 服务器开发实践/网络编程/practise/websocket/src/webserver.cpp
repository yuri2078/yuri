#include "../include/webserver.h"
#include "response.h"
#include "request.h"
#include "type.h"
#include <iterator>
#include <memory>
#include <sstream>
#include <fstream>

namespace yuri::web {

WebServer::WebServer(const sock_t port, const std::string ip) :
  fd(-2078), addr({}) {
  init();
  if (ip == "any") {
    addr.setAddress(INADDR_ANY);
  } else {
    addr.setAddress(ip);
  }
  getMapping("/", [this](int client,  std::shared_ptr<web::Request> request) {
    std::string file(readFile("../dist/index.html"));
    result(client, web::Status::OK, web::ContentType::html, file);
  });

  getMapping("/favicon.ico", [this](int client,  std::shared_ptr<web::Request> request) {
    std::string file(readFile("../dist/favicon.ico"));
    result(client, web::Status::OK, web::ContentType::icon, file);
  });

  getMapping("/yuri.png", [this](int client,  std::shared_ptr<web::Request> request) {
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
  // struct timeval timeout;
  // timeout.tv_sec = 5;
  // timeout.tv_usec = 0;
  // if (setsockopt(client, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
  //   perror("setsockopt");
  //   return 1;
  // }

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

void WebServer::handleRequest(int client, std::shared_ptr<web::Request> request) {
  auto getFun = [this](const std::string &type) {
    if(type == "GET") {
      return get_func;
    } else if (type == "POST") {
      return post_func;
    }
    return opt_func;
  };

  auto funcs = getFun(request->requestType());
  auto func = funcs.find(request->path());
  if (func != funcs.end()) {
    funcs[request->path()](client, request);
  } else {
    result(client, web::Status::NotFound, ContentType::text, "没找到捏!");
  }
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
    if (recv_(client, buff, 1024) > 0) {
      std::shared_ptr<Request> request = std::make_shared<Request>(buff);
      info << buff;
      if (request->fileType() == web::FileType::script || request->fileType() == web::FileType::style) {
        getMapping(request->path(), [this](int client, std::shared_ptr<web::Request> request) {
          std::string file(readFile("../dist" + request->path()));
          web::ContentType type = Response::getContentType(request->fileType());
          result(client, web::Status::OK, type, file);
        });
      }

      handleRequest(client, request);

    } else {
      return;
    }
  }
}

void WebServer::init() {
  postMapping("/file", [this](int client, std::shared_ptr<web::Request> request) {
    // info  << request->showInfo();
    int size = std::stoi(request->contentLength()), all = 0;
    std::vector<char> vec(size);
    while (all < size) {
      int ret = ::recv(client, vec.data() + all, size - all, 0);
      all += ret;
      info << "本次 -> " << ret << " 共 -> " << all;
    }

    std::string str(std::make_move_iterator(vec.begin()), std::make_move_iterator(vec.end()));
    info << "获取的文件长度 -> " << str.size();
    int begin = str.find("\r\n\r\n") + 4;
    int end = str.rfind("--" + request->boundary());
    std::string head = str.substr(0, str.find("\r\n\r\n"));
    int pos = head.find("filename=\"") + 10;
    std::string file_name = head.substr(pos ,head.rfind("\"") - pos);
    info << "file -> " << file_name;
    std::fstream file(file_name, std::ios::out | std::ios::binary);
    file.write(str.data() + begin, end - begin);
    file.close();
    result(client, Status::OK, ContentType::text, "0");
  });

  optMapping("/file", [this](int client, std::shared_ptr<web::Request> request) {
    info << request->showInfo();
    std::string str = "Access-Control-Allow-Origin: *\r\n "
                      "Access-Control-Allow-Methods: *\r\n"
                      "Access-Control-Allow-Headers: *\r\n";
    result(client, Status::OK, ContentType::text, str);
  });
}

void WebServer::result(int client, web::Status status, web::ContentType type, std::string msg) {
  std::string response(web::Response::response(type, msg.length()));
  writeToClient(client, response);
  if (!msg.empty()) {
    writeToClient(client, msg);
  }
}

void WebServer::getMapping(std::string path, std::function<void(int client,  std::shared_ptr<web::Request> request)> func) {
  get_func[path] = func;
}

void WebServer::postMapping(std::string path, std::function<void(int client,  std::shared_ptr<web::Request> request)> func) {
  post_func[path] = func;
}

void WebServer::optMapping(std::string path, std::function<void(int client,  std::shared_ptr<web::Request> request)> func) {
  opt_func[path] = func;
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
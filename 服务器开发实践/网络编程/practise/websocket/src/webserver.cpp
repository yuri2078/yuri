#include "../include/webserver.h"
#include "response.h"
#include "request.h"
#include "type.h"
#include <iterator>
#include <memory>
#include <sstream>
#include <fstream>
#include <string_view>

namespace yuri::web {

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
  int ret = 0;
  try {
    ret = ::send(client, msg.c_str(), msg.size(), 0);
  } catch (std::exception &e) {
    error << e.what();
    error << "发生异常!!!";
    ret = -1;
  }

  if (ret <= 0) {
    error << client << " -> " << strerror(errno);
    return false;
  }
  return true;
}

bool WebServer::writeToClient(const int client, std::string_view msg, unsigned long int size) {
  int ret = 0;
  try {
    ret = ::send(client, msg.data(), size, 0);
  } catch (std::exception &e) {
    error << e.what();
    error << "发生异常!!!";
    ret = -1;
  }
  if (ret <= 0) {
    error << client << " -> " << strerror(errno);
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
    std::string file(readFile("../dist/404.html"));
    result(client, web::Status::NotFound, ContentType::html, file);
  }
}

int WebServer::recv_(const int client, char *buf, sock_t size) {
  int ret = ::recv(client, buf, size, 0);
  if (ret == 0) {
    // info << std::format("{} 断开连接!", client);
    return 0;
  }
  if (ret < 0) {
    error << client << " -> " << strerror(errno);
    return -1;
  }
  return ret;
}

// 接受数据
void WebServer::recv(const int client) {
  while (true) {
    char buff[1024]{};
    if (recv_(client, buff, 1024) > 0) {
      std::shared_ptr<Request> request = std::make_shared<Request>(buff);
      if (!request->is_error.empty()) {
        result(client, Status::BadRequest, ContentType::text, "错误！");
        return;
      }
      info << buff;
      handleRequest(client, request);
    } else {
      return;
    }
  }
}

void WebServer::init() {
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
    result(client, web::Status::OK, web::ContentType::png, file);
  });
  auto addStaticFile = [this](const std::string &path, ContentType type) {
    getMapping(path, [this, path, type](int client, std::shared_ptr<web::Request> request) {
      std::string file(readFile("../dist" + request->path()));
      result(client, web::Status::OK, type, file);
    });
  };
  addStaticFile("/assets/index-05e92bac.js", ContentType::js);
  addStaticFile("/assets/index-4a224b10.js", ContentType::js);
  addStaticFile("/assets/index-662bc092.js", ContentType::js);
  addStaticFile("/assets/index-68236867.js", ContentType::js);
  addStaticFile("/assets/index-a8f88f24.js", ContentType::js);
  addStaticFile("/assets/index-bc1a93f6.css", ContentType::css);
  addStaticFile("/assets/index-d4dcadde.js", ContentType::js);
  addStaticFile("/assets/index-e5880139.js", ContentType::js);
  addStaticFile("/assets/index-eca29ec9.css", ContentType::css);
  
  postMapping("/file", [this](int client, std::shared_ptr<web::Request> request) {
    // info  << request->showInfo();/home/yuri/yuri/服务器开发实践/网络编程/practise/websocket/build/test.zip
    unsigned long int size = 0, all = 0;
    try {
      size = std::stoll(request->contentLength()), all = 0;
    } catch (std::exception &e) {
      error << e.what();
      result(client, Status::BadRequest, ContentType::text, "文件过大!");
      return;
    }

    std::stringstream sstr;
    info << "源文件大小 -> " << size;
    while (all < size) {
      char buff[1024]{};
      int ret = recv_(client, buff, 1023);
      // info << "本次获取 -> " << ret << " 共 -> " << all;
      if (ret <= 0) {
        result(client, Status::BadRequest, ContentType::text, "获取文件失败!");
        error << "获取失败!";
        return;
      };
      all += ret;
      sstr.write(buff, ret);
    }
    std::string str(sstr.str());
    unsigned long int begin = str.find("\r\n\r\n") + 4;
    unsigned long int end = str.rfind("--" + request->boundary());
    std::string head = str.substr(0, str.find("\r\n\r\n"));
    unsigned long int pos = head.find("filename=\"") + 10;
    std::string file_name = head.substr(pos ,head.rfind("\"") - pos);
    std::fstream file(file_name, std::ios::out | std::ios::binary);
    file.write(str.data() + begin, end - begin - 2);
    info << "file -> " << file_name << " " << end - begin - 2;
    file.close();
    result(client, Status::OK, ContentType::text, "发送成功!");
  });

  optMapping("/file", [this](int client, std::shared_ptr<web::Request> request) {
    std::string str = "Access-Control-Allow-Origin: *\r\n"
                      "Access-Control-Allow-Methods: *\r\n"
                      "Access-Control-Allow-Headers: *\r\n";
    result(client, Status::OK, ContentType::text, str);
  });

  getMapping("/download", [this](int client, std::shared_ptr<web::Request> request) {
    // info << request->showInfo();
    std::string file_name("/home/yuri/yuri/服务器开发实践/网络编程/practise/websocket/build/test.zip");
    std::ifstream file(file_name, std::ios::binary);
    if (!file || !file.is_open()) {
      result(client, Status::BadRequest, ContentType::text, "文件打开失败!");
      return;
    }
    file.seekg(0, std::ios::end); // 将文件指针移动到文件末尾
    unsigned long int size = file.tellg(); // 获取文件指针的位置，即文件大小
    file.close();
    std::string responseHeader = Response::response(file_name, size, ContentType::zip);
    writeToClient(client, responseHeader);
    if (!sendFile(client, file_name)) {
      // result(client, Status::BadRequest, ContentType::text, "文件传送失败!");
      error << "发生了错误!!";
    }
  });
}

void WebServer::result(int client, web::Status status, web::ContentType type, std::string msg) {
  std::string response(web::Response::response(type, msg.length()));
  writeToClient(client, response);
  if (!msg.empty()) {
    writeToClient(client, msg);
  }
}

bool WebServer::sendFile(int client, const std::string &file_name) {
  const int buffer_size = 65535;
  char buffer[buffer_size];
  std::ifstream file(file_name, std::ios::binary);
  // 逐块读取文件内容
  info << "开始发送!";
  while (!file.eof()) {
    
    file.read(buffer, buffer_size);
    unsigned long int ret = file.gcount(); // 获取实际读取的字节数
    if (!writeToClient(client, buffer, ret)) {
      file.close();
      return false;
    }
  }
  file.close();
  info << "发送成功!";
  return true;
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
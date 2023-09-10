#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstring>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>

const int PORT = 2078;                                           // 选择一个端口号
const std::string UPLOAD_DIR = "/home/yuri/yuri/服务器开发实践"; // 指定上传文件保存的目录

// 从socket中读取指定长度的数据
bool readFromSocket(int socket, char *buffer, int length) {
  int bytesRead = 0;
  std::cout << "length -> " << length << std::endl;
  std::vector<char> vec(length);
  while (bytesRead < length) {
    int result = recv(socket, vec.data() + bytesRead, length - bytesRead, 0);
    if (result <= 0) {
      return false;
    }
    std::cout << "本次读取 -> " << result << std::endl;
    bytesRead += result;
  }
  std::cout << "一共读取 -> " << bytesRead << std::endl;
  strcpy(buffer, vec.data());
  return true;
}

int main() {
  // 创建socket
  int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket == -1) {
    std::cerr << "无法创建socket" << std::endl;
    return 1;
  }

  // 准备服务器地址信息
  struct sockaddr_in serverAddr;
  serverAddr.sin_family = AF_INET;
  serverAddr.sin_port = htons(PORT);
  serverAddr.sin_addr.s_addr = INADDR_ANY;

  // 绑定socket到地址
  if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
    std::cerr << "绑定失败" << std::endl;
    close(serverSocket);
    return 1;
  }

  // 开始监听连接
  if (listen(serverSocket, 5) == -1) {
    std::cerr << "监听失败" << std::endl;
    close(serverSocket);
    return 1;
  }

  std::cout << "服务器正在监听端口 " << PORT << std::endl;

  while (true) {
    // 接受连接请求
    struct sockaddr_in clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    int clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &clientAddrLen);
    if (clientSocket == -1) {
      std::cerr << "接受连接失败" << std::endl;
      continue;
    }
    std::cout << "连接成功!\n";
    // 读取HTTP请求头
    char buffer[1024666];
    memset(buffer, 0, sizeof(buffer));
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
    if (bytesRead == -1) {
      std::cerr << "接收数据失败" << std::endl;
      close(clientSocket);
      continue;
    }
    std::string httpRequest(buffer);
    // std::cout << httpRequest << std::endl;

    if (httpRequest.find("OPTIONS") != std::string::npos) {
      // 处理OPTIONS请求，允许跨域请求
      std::string response = "HTTP/1.1 200 OK\r\n";
      response += "Access-Control-Allow-Origin: *\r\n";
      response += "Access-Control-Allow-Methods: POST, OPTIONS\r\n";
      response += "Access-Control-Allow-Headers: Content-Type\r\n";
      response += "Content-Length: 0\r\n\r\n";
      send(clientSocket, response.c_str(), response.length(), 0);
      std::cout << "发送校验请求\n";
      memset(buffer, 0, sizeof(buffer));
      ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer) - 1, 0);
      if (bytesRead == -1) {
        std::cerr << "接收数据失败" << std::endl;
        close(clientSocket);
        continue;
      }
      httpRequest = std::string(buffer);
      // std::cout << httpRequest << std::endl;
    }

    // 解析HTTP请求头，找到Content-Length字段
    size_t contentLengthStart = httpRequest.find("Content-Length: ");
    if (contentLengthStart == std::string::npos) {
      // 如果没有Content-Length字段，返回错误
      std::string response = "HTTP/1.1 400 Bad Request\r\n\r\n";
      send(clientSocket, response.c_str(), response.length(), 0);
      close(clientSocket);
      continue;
    }
    contentLengthStart += 16; // 移动到值的开始
    size_t contentLengthEnd = httpRequest.find("\r\n", contentLengthStart);
    int bodyLength = std::stoi(httpRequest.substr(contentLengthStart, contentLengthEnd - contentLengthStart));

    // 读取请求体
    std::string requestBody;
    if (!readFromSocket(clientSocket, buffer, bodyLength)) {
      std::cerr << "无法读取请求体" << std::endl;
      close(clientSocket);
      continue;
    }
    requestBody.assign(buffer, bodyLength);
    // std::cout << "body ---------------------->\n " << requestBody << std::endl;

    // 检查是否是OPTIONS请求
    if (httpRequest.find("POST /file") != std::string::npos) {
      // 提取文件名
      size_t filenameStart = requestBody.find("filename=\"") + 10;
      size_t filenameEnd = requestBody.find("\"", filenameStart);
      std::string filename = requestBody.substr(filenameStart, filenameEnd - filenameStart);

      // 保存文件到本地
      std::cout << "文件名 -> " << filename << "\n";
      std::string filePath = UPLOAD_DIR + "/" + filename;
      std::fstream outputFile(filePath, std::ios::out | std::ios::binary);
      if (!outputFile) {
        std::cerr << "无法保存文件: " << filePath << std::endl;
        close(clientSocket);
        continue;
      }

      outputFile.write(requestBody.c_str(), requestBody.length());
      outputFile.close();

      // 发送成功响应
      std::string response = "HTTP/1.1 200 OK\r\n\r\n";
      send(clientSocket, response.c_str(), response.length(), 0);
    } else {
      // 如果不是OPTIONS请求或文件上传请求，返回404错误
      std::string response = "HTTP/1.1 404 Not Found\r\n\r\n";
      send(clientSocket, response.c_str(), response.length(), 0);
    }

    // 关闭客户端socket
    close(clientSocket);
  }

  // 关闭服务器socket
  close(serverSocket);

  return 0;
}

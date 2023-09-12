#include "include/ftpclient.h"

int main() {
  yuri::web::FtpClient client("127.0.0.1", 2078);
  if (client.connect()) {
    std::cout << "请输入文件名: ";
    std::string file_name;
    std::cin >> file_name;
    if (client.sendFile(file_name)) {
      info << "写入成功!";
    }
  }
  return 0;
}
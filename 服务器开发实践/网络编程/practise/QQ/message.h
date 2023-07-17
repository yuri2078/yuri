#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>


enum MessageType{msg, login, config};
// 普通消息 登陆消息 日志消息
class Message {
public:
  
  Message(const std::string name) : type(MessageType::msg), name(name) {
    size_t = 78;
    std::cout << "sizeof this : " << sizeof *this
              << "\n sizeof type : " << sizeof type
              << "\nsizeof name : " << sizeof name
              << "\n sizeof msg : " << sizeof msg;
    std::endl(std::cout);
    
  }

  void setType(const MessageType &new_type) {
    this->type = new_type;
  }

  void setMsg(const std::string &str) {
    msg = std::move(str);
  }

  unsigned size() {
    return sizeof(*this);
  }

  char *getThis() {
    return reinterpret_cast<char *>(this);
  }

private:
  unsigned int size_t;
  MessageType type;
  std::string name;
  std::string msg;
};


#endif
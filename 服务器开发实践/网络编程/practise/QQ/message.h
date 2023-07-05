#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>


enum MessageType{msg, login, config};
// 普通消息 登陆消息 日志消息
class Message {
public:
  
  Message(const std::string name) : type(MessageType::msg), name(name) {
    
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
  MessageType type;
  std::string name;
  std::string msg;
};


#endif
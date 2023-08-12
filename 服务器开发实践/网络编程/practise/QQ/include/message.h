#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <iostream>

enum MessageType { msg,
                   login,
                   config };
// 普通消息 登陆消息 日志消息
class MessageHead {
public:
  MessageHead(const unsigned int size = 0, const MessageType &type = MessageType::msg) :
    type_(type), size_(size) , id_(0){
    msg_ = nullptr;
  }

  virtual ~MessageHead() {
    if (msg_) {
      delete [] msg_;
    }
  }

  unsigned size() const {
    return size_;
  }

  MessageType type() const {
    return type_;
  }

  unsigned int id() const {
    return id_;
  }

  void setId(unsigned int id) {
    id_ = id;
  }

  void setSize(unsigned int size) {
    size_ = size;
    msg_ = new char[size + 1]();
  }

  const char *headData() {
    return reinterpret_cast<char *>(this);
  }

  char *msgData() const {
    return msg_;
  }

  std::string msg() const {
    return std::string(msg_);
  }

  static std::string const getType(const MessageType &type) {
    switch (type) {
    case MessageType::msg:
      return "普通消息";
    case MessageType::login:
      return "登陆消息";
    case MessageType::config:
      return "配置消息";
    default:
      return "未知消息";
    }
  }

private:
  MessageType type_;
  unsigned int size_;
  unsigned int id_;
  char *msg_;
};

#endif

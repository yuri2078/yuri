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
  MessageHead(unsigned length, const MessageType &type = MessageType::msg) :
    type_(type), length_(length) {
      msg_ = nullptr;
  }

  unsigned length() const {
    return length_;
  }

  MessageType type() const {
    return type_;
  }

  unsigned *mutable_lenght() {
    return &length_;
  }

  MessageType *mutable_type() {
    return &type_;
  }

  const char *data() {
    return reinterpret_cast<char *>(this);
  }

  void setMsgSize(const unsigned size) {
    msg_ = new char[size];
  }

  char *msg() const {
    return msg_;
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
  unsigned int length_;
  char *msg_;
};

#endif

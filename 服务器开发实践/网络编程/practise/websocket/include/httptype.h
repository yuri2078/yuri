#ifndef HTTPTYPE
#define HTTPTYPE

#include <string>
#include <unordered_map>

namespace yuri {

enum RequestType {
  GET,
  POST
};

enum StatusType {
  OK
};

enum ContentType {
  html,
  icon,
  css,
  js,
  text
};

class Type {
public:
  static std::string getType(const RequestType type);
  static std::string getType(const StatusType type);
  static std::string getType(const ContentType type);

  static std::string cross;

private:
  static std::unordered_map<RequestType, std::string> request_type;
  static std::unordered_map<StatusType, std::string> status_type;
  static std::unordered_map<ContentType, std::string> content_type;

  
};

} // namespace yuri
#endif



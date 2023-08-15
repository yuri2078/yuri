#include "../include/httptype.h"

namespace yuri {

std::string Type::getType(const RequestType type) {
  return request_type[type];
}

std::string Type::getType(const StatusType type) {
  return status_type[type];
}

std::string Type::getType(const ContentType type) {
  return content_type[type];
}

std::unordered_map<RequestType, std::string> Type::request_type = {
  {RequestType::GET, "GET"},
  {RequestType::POST, "POST"}};

// 状态类型
std::unordered_map<StatusType, std::string> Type::status_type = {
  {StatusType::OK, std::string("HTTP/1.1 200 OK\r\n")}};

// 数据类型
std::unordered_map<ContentType, std::string> Type::content_type{
  {ContentType::html, "Content-Type: text/html\r\n"},
  {ContentType::text, "Content-Type: text/plain\r\n"},
  {ContentType::css, "Content-Type: text/css\r\n"},
  {ContentType::js, "Content-Type: application/javascript\r\n"},
  {ContentType::icon, "Content-Type: image/x-icon\r\n"}};

std::string Type::cross = "Access-Control-Allow-Origin: *\r\n"
          "Access-Control-Allow-Methods: GET, POST, OPTIONS\r\n"
          "Access-Control-Allow-Headers: Content-Type, Authorization\r\n"
          "Access-Control-Allow-Credentials: true\r\n";
} // namespace yuri

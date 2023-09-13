#include "../include/response.h"
#include "type.h"

namespace yuri::web {

std::string Response::response(const ContentType type, const unsigned int lenght, const Status status) {
  return getTypeString(status) + getTypeString(type) + getTypeString(lenght)
         + "Access-Control-Allow-Origin: *\r\n"
         + "Access-Control-Allow-Methods: GET, POST, OPTIONS\r\n"
         + "Access-Control-Allow-Headers: Content-Type, Authorization\r\n"
         + "Connection: close\r\n\r\n";
}

ContentType Response::getContentType(const FileType type) {
  switch (type) {
  case FileType::font:
    return ContentType::text;
  case FileType::script:
    return ContentType::js;
  case FileType::style:
    return ContentType::css;
  case FileType::image:
    return ContentType::icon;
  case FileType::document:
    return ContentType::html;
  default: return ContentType::text;
  }
}

std::string Response::getTypeString(const Status status) {
  switch (status) {
  case Status::OK:
    return "HTTP/1.1 200 OK\r\n";
  case Status::Created:
    return "HTTP/1.1 201 Created\r\n";
  case Status::Accepted:
    return "HTTP/1.1 202 Accepted\r\n";
  case Status::NoContent:
    return "HTTP/1.1 204 No Content\r\n";
  case Status::MovedPermanently:
    return "HTTP/1.1 301 Moved Permanently\r\n";
  case Status::Found:
    return "HTTP/1.1 302 Found\r\n";
  case Status::BadRequest:
    return "HTTP/1.1 400 Bad Request\r\n";
  case Status::Unauthorized:
    return "HTTP/1.1 401 Unauthorized\r\n";
  case Status::Forbidden:
    return "HTTP/1.1 403 Forbidden\r\n";
  case Status::NotFound:
    return "HTTP/1.1 404 Not Found\r\n";
  case Status::InternalServerError:
    return "HTTP/1.1 500 Internal Server Error\r\n";
  default:
    return "";
  }
}

std::string Response::getTypeString(const ContentType type) {
  switch (type) {
  case ContentType::html:
    return "Content-Type: text/html;charset=UTF-8\r\n";
  case ContentType::text:
    return "Content-Type: text/plain;charset=UTF-8\r\n";
  case ContentType::css:
    return "Content-Type: text/css;charset=UTF-8\r\n";
  case ContentType::js:
    return "Content-Type: application/javascript;charset=UTF-8\r\n";
  case ContentType::icon:
    return "Content-Type: image/x-icon;charset=UTF-8\r\n";
  case ContentType::picture:
    return "Content-Type: image/png;charset=UTF-8\r\n";
  default:
    return "";
  }
}

std::string Response::getTypeString(const unsigned length) {
  if (length == 0) {
    return "";
  }
  return "Content-Length: " + std::to_string(length) + "\r\n";
}

} // namespace yuri::web

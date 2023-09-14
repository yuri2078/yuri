#include "../include/response.h"
#include "type.h"
#include <format>

namespace yuri::web {

std::string Response::response(const ContentType type, const unsigned long int lenght, const Status status) {
  return getTypeString(status) + getTypeString(type) + getTypeString(lenght)
         + "Access-Control-Allow-Origin: *\r\n"
         + "Access-Control-Allow-Methods: GET, POST, OPTIONS\r\n"
         + "Access-Control-Allow-Headers: Content-Type, Authorization\r\n"
         + "Connection: close\r\n\r\n";
}

std::string Response::response(std::string_view file_name, const unsigned long int size, ContentType type) {
  return std::format("{}{}Content-Disposition: attachment; filename=\"{}\"\r\n{}\r\n",
    getTypeString(Status::OK),
    getTypeString(type),
    file_name,
    getTypeString(size));
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
  case ContentType::json:
    return "Content-Type: application/json;charset=UTF-8\r\n";
  case ContentType::xml:
    return "Content-Type: application/xml;charset=UTF-8\r\n";
  case ContentType::icon:
    return "Content-Type: image/x-icon\r\n";
  case ContentType::png:
    return "Content-Type: image/png\r\n";
  case ContentType::jpeg:
    return "Content-Type: image/jpeg\r\n";
  case ContentType::gif:
    return "Content-Type: image/gif\r\n";
  case ContentType::pdf:
    return "Content-Type: application/pdf\r\n";
  case ContentType::zip:
    return "Content-Type: application/zip\r\n";
  case ContentType::doc:
    return "Content-Type: application/msword\r\n";
  case ContentType::docx:
    return "Content-Type: application/vnd.openxmlformats-officedocument.wordprocessingml.document\r\n";
  case ContentType::md:
    return "Content-Type: text/markdown;charset=UTF-8\r\n";
  case ContentType::tar:
    return "Content-Type: application/x-tar\r\n";
  case ContentType::tar_gz:
    return "Content-Type: application/gzip\r\n";
  case ContentType::c:
    return "Content-Type: text/x-c;charset=UTF-8\r\n";
  case ContentType::stream:
    return "Content-Type: application/octet-stream\r\n";
  default:
    return "";
}

}

std::string Response::getTypeString(const unsigned long int length) {
  if (length == 0) {
    return "";
  }
  return "Content-Length: " + std::to_string(length) + "\r\n";
}

} // namespace yuri::web

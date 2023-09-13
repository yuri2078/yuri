#include "../include/request.h"
#include <exception>
#include <unordered_map>
#include <yuri.h>

namespace yuri::web {

Request::Request(const std::string &header) {
  host_ = getInfo(header, "Host");
  content_length = getInfo(header, "Content-Length");
  accept_ = getInfo(header, "Accept");
  sec_fetch_site = getInfo(header, "Sec-Fetch-Site");
  sec_fetch_dest = getInfo(header, "Sec-Fetch-Dest");
  referer_ = getInfo(header, "Referer");
  cookie_ = getInfo(header, "Cookie");
  boundary_ = getInfo(header, "boundary");
  access_control_request_methodod = getInfo(header, "Access-Control-Request-Method");
  type_ = getType(header);
  if (!boundary_.empty() && header.find(boundary_) != header.rfind(boundary_)) {
    is_error = "错误接收文件消息!";
  }
  // info << "消息体位置 -> " << header.find(header.find(boundary_) + 1);
}

std::string Request::showInfo() const {
  return
    "\n请求方式 -> " + type_ +
    "\n请求路径 -> " + path_ + 
    "\n请求地址 -> " + host_ + 
    "\n请求体长度 -> " + content_length + 
    "\n请求文件类型 -> " + accept_ + 
    "\n是否同源 -> " + sec_fetch_site + 
    "\n不同源请求类型 -> " + access_control_request_methodod +
    "\n请求资源类型 -> " + sec_fetch_dest + 
    "\n请求文件类型 -> " + std::to_string(file_type) +
    "\n引荐页url -> " + referer_ + 
    "\n用户cookie -> " + cookie_ + 
    "\n分割线 -> " + boundary_ +
    "\n请求体 -> " + body_ + "\n";
}

std::string Request::getType(const std::string &header) {
  std::string type;
  int start = 0;
  while (header[start] != ' ' && header[start]) {
    start++;
  }
  try {
    type = header.substr(0, start);
    start++;
    int end = start;
    while (header[end] != ' ' && header[end]) {
      end++;
    }
    path_ = header.substr(start, end - start);
    start = header.find_last_of("{");
    if (start < header.size()) {
      body_ = header.substr(start, header.size() - start);
    } else {
      body_ = "";
    }
  } catch (std::exception &e) {
    error << "61 : 发生异常 -> " << e.what();
    return "";
  }
  
  std::unordered_map<std::string, FileType> file_type = {
    {"script", FileType::script},
    {"style", FileType::style},
    {"image", FileType::image},
    {"font", FileType::font},
    {"media", FileType::media},
    {"connect", FileType::connect},
    {"worker", FileType::worker},
    {"document", FileType::document},
    {"manifest", FileType::manifest}};
  if (file_type.find(this->sec_fetch_dest) == file_type.end()) {
    this->file_type = FileType::unknow;
  } else {
    this->file_type = file_type[this->sec_fetch_dest];
  }
  
  return type;
}

std::string Request::getInfo(const std::string &header, const std::string &key) {
  int pos = header.find(key), size = header.size();
  if (pos == std::string::npos) {
    return "";
  }
  pos += key.size() + (key == "boundary" ? 1 : 2);
  int end = pos;
  while (end < size && header[end] != '\r' && header[end] != '\n') {
    end++;
  }
  try {
    return header.substr(pos, end - pos);
  } catch (std::exception &e) {
    error << "92 : 发生异常 -> " << e.what();
    return "";
  }
}

const std::string &Request::requestType() const {
  return type_;
}

FileType Request::fileType() const {
  return file_type;
}

const std::string &Request::AccessControlRequestMethod() const {
  return access_control_request_methodod;
}

const std::string &Request::path() const {
  return path_;
}

const std::string &Request::host() const {
  return host_;
}

const std::string &Request::contentLength() const {
  return content_length;
}

const std::string &Request::accept() const {
  return accept_;
}

const std::string &Request::secFetchSite() const {
  return sec_fetch_site;
}

const std::string &Request::secFetchDest() const {
  return sec_fetch_dest;
}

const std::string &Request::referer() const {
  return referer_;
}

const std::string &Request::cookie() const {
  return cookie_;
}

const std::string &Request::body() const {
  return body_;
}

const std::string &Request::boundary() const {
  return boundary_;
}

} // namespace yuri::web
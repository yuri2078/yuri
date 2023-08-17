#include "../include/request.h"

namespace yuri::web {

Request::Request(const std::string &header) {
  type_ = getType(header);
  host_ = getInfo(header, "Host");
  content_length = getInfo(header, "Content-Length");
  accept_ = getInfo(header, "Accept");
  sec_fetch_site = getInfo(header, "Sec-Fetch-Site");
  sec_fetch_dest = getInfo(header, "Sec-Fetch-Dest");
  referer_ = getInfo(header, "Referer");
  cookie_ = getInfo(header, "Cookie");
}

std::string Request::showInfo() const {
  return
    "\n请求方式 -> " + std::to_string(type_) +
    "\n请求路径 -> " + path_ + 
    "\n请求地址 -> " + host_ + 
    "\n请求体长度 -> " + content_length + 
    "\n请求文件类型 -> " + accept_ + 
    "\n是否同源 -> " + sec_fetch_site + 
    "\n请求资源类型 -> " + sec_fetch_dest + 
    "\n引荐页url -> " + referer_ + 
    "\n用户cookie -> " + cookie_ + 
    "\n请求体 -> " + body_ + "\n";
}

Request::Type Request::getType(const std::string &header) {
  std::string type;
  int start = 0;
  while (header[start] != ' ' && header[start]) {
    start++;
  }
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
  return type == "GET" ? Type::GET : Type::POST;
}

std::string Request::getInfo(const std::string &header, const std::string &key) {
  int pos = header.find(key), size = header.size();
  if (pos == std::string::npos) {
    return "";
  }
  pos += key.size() + 2;
  int end = pos;
  while (end < size && header[end] != '\r' && header[end] != '\n') {
    end++;
  }
  return header.substr(pos, end - pos);
}

Request::Type Request::type() const {
  return type_;
}

const std::string& Request::path() const {
  return path_;
}

const std::string& Request::host() const {
  return host_;
}

const std::string& Request::contentLength() const {
  return content_length;
}

const std::string& Request::accept() const {
  return accept_;
}

const std::string& Request::secFetchSite() const {
  return sec_fetch_site;
}

const std::string& Request::secFetchDest() const {
  return sec_fetch_dest;
}

const std::string& Request::referer() const {
  return referer_;
}

const std::string& Request::cookie() const {
  return cookie_;
}

const std::string& Request::body() const {
  return body_;
}




}
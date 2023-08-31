#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include "type.h"

namespace yuri::web {

class Request {
public:

  // 传入请求头字符串
  Request(const std::string &header);

  RequestType requestType() const;
  FileType fileType() const;
  const std::string &path() const;
  const std::string &host() const;
  const std::string &contentLength() const;
  const std::string &accept() const;
  const std::string &secFetchSite() const;
  const std::string &secFetchDest() const;
  const std::string &referer() const;
  const std::string &cookie() const;
  const std::string &body() const;

  std::string showInfo() const;

private:
  RequestType type_;          // 请求类型
  std::string path_;          // 请求路径
  std::string host_;          // 请求地址
  std::string content_length; // 请求体长度
  std::string accept_;        // 请求文件类型
  std::string sec_fetch_site; // 是否同源
  std::string sec_fetch_dest; // 请求资源类型
  std::string referer_;       // 引荐页url
  std::string cookie_;        // 用户cookie
  std::string body_;          // 请求体
  FileType file_type;         // 请求文件类型

  RequestType getType(const std::string &); // 通过字符串获取请求类型
  std::string getInfo(const std::string &, const std::string &);
  std::string getPath(const std::string &);
};

} // namespace yuri::web

#endif
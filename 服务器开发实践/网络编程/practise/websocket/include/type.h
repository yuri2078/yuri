#ifndef TYPE_H
#define TYPE_H

namespace yuri::web {

enum Status {
  OK = 200,
  Created = 201,
  Accepted = 202,
  NoContent = 204,
  MovedPermanently = 301,
  Found = 302,
  BadRequest = 400,
  Unauthorized = 401,
  Forbidden = 403,
  NotFound = 404,
  InternalServerError = 500
};

enum ContentType {
  html,
  icon,
  css,
  js,
  text,
  json,
  jpg,
  png,
  gif,
  zip,
  xml,
  jpeg,
  pdf,
  doc,
  docx,
  tar,
  gz,
  md,
  tar_gz,
  c,
  cpp,
  stream
};

enum RequestType {
  GET,
  POST
};

enum FileType {
  script,
  style,
  image,
  font,
  media,
  connect,
  worker,
  manifest,
  document,
  unknow
};

} // namespace yuri::web::type

#endif
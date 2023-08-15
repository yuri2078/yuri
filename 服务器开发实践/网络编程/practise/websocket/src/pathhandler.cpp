#include "../include/pathhandler.h"
#include "httptype.h"
#include "response.h"
#include "webserver.h"

namespace yuri {


PathHandler::PathHandler(WebServer *server, Response *response) :
  server(server), response(response) {
  
}

PathHandler::~PathHandler() {
}

void PathHandler::sendFile(const std::string &file_name, ContentType type) {
  std::string file = response->readFile(file_name);
  response->setContent(type, file.size());
  if (server->writeToClient(response->client(), response->httpHeader())) {
    server->writeToClient(response->client(), file);
  }
}


}

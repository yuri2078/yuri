#include <yuri.h>
#include "include/webserver.h"

int main(int argc, char *argv[])
{
  yuri::web::WebServer webserver(2078);
  if(webserver.listen()) {
    while (true) {
      try {
        webserver.accept();
      } catch (std::exception &e) {
        error << e.what();
      }
    }
  } else {
    return 1;
  }
  return 0;
}

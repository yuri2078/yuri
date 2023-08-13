#include <yuri.h>
#include "include/webserver.h"

int main(int argc, char *argv[])
{
  WebServer webserver(2078);
  if(webserver.listen()) {
    while(true) {
      webserver.accept();
    }
  } else {
    return 1;
  }
  return 0;
}

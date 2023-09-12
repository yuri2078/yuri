#include <yuri.h>
#include "include/ftpserver.h"

int main(int argc, char *argv[])
{
  yuri::web::FtpServer ftpserver(2078);
  if(ftpserver.listen()) {
    while(true) {
      ftpserver.accept();
    }
  } else {
    return 1;
  }
  return 0;
}

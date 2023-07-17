#include <iostream>
#include "message.h"

int main() {
  Message message("");
  char *s = message.getThis();
//   s[2] = 0;
  std::cout << (unsigned)(*s) << "\n";
  return 0;
}
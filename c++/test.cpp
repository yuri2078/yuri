#include <format>
#include <iostream>

int main() {
  std::string msg;
  char s[20]{"yuri"};
  msg.append(s);
  /* yuri */
  std::cout << msg << " " << msg.size() << "\n";
  return 0;
}
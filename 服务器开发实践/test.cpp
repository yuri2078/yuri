#include <iostream>
#include <string>

int main() {
  const char str[4] = {'y','u','r','i'};
  
  std::string msg(str);
  std::cout << msg.size();
  std::endl(std::cout);
  return 0;
}
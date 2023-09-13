#include <yuri.h>
#include <limits>

int main() {
  info << std::numeric_limits<long unsigned int>::max();
  info << std::numeric_limits<unsigned long int>::max();
  return 0;
}
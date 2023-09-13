#include <yuri.h>
#include <limits>

int main() {
  info << std::numeric_limits<long unsigned int>::max();
  info << std::numeric_limits<std::string::size_type>::max();

  return 0;
}
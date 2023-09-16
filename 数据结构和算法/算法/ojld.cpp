#include <iostream>

int gys(int x, int y) {
  int r = x % y;
  while (r) {
    x = y;
    y = r;
    r = x % y;
  }
  return y;
}

int main() {
  int x, y;
  std::cin >> x >> y;
  std::cout << gys(x, y) << std::endl;
  return 0;
}
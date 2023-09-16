#include <iostream>

int gys(int x, int y) {
  if (x * y == 0) {
    return x + y;
  }
  
  if (x == y) {
    return x;
  } else if (x > y) {
    return gys(x - y, y);
  }
  return gys(y - x, x);
}

int main() {
  int x, y;
  std::cin >> x >> y;
  std::cout << gys(x, y) << std::endl;
  return 0;
}
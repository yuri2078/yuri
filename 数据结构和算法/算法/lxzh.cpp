#include <iostream>

int gys(int x, int y) {
  if (x == 0) {
    return y;
  }
  
  int res = x;
  while (x % res || y % res) {
    res--;
  }
  return res;
}

int main() {
  int x, y;
  std::cin >> x >> y;
  std::cout << gys(x, y) << std::endl;
  return 0;
}
#include <chrono>
#include <iostream>

using namespace std;

int main() {
  auto sc = chrono::time_point_cast<chrono::milliseconds>(chrono::steady_clock::now());
  cout << (chrono::duration_cast<chrono::milliseconds> (sc.time_since_epoch())).count() << endl;
  return 0;
}
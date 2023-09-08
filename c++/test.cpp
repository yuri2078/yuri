#include <yuri.h>
#include <unordered_set>

int main() {
  std::string s("aabccd");
  std::unordered_multiset<char> set(s.begin(), s.end());
  auto iter = set.find('a');
  set.erase(iter);
  for (char c : set) {
    info << c;
  }
  
  return 0;
}
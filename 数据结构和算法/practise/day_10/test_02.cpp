#include <iostream>
#include <string>
#include <unordered_map>

int main(int argc, const char *argv[])
{
	std::string s;
	std::unordered_map<char, int> map;

	std::cin >> s;
	for (auto begin = s.begin(); begin != s.end(); begin++) {
		map[*begin]++;
		if (map[*begin] > 1) {
			begin = s.erase(begin) - 1;
        }
	}
	std::cout << s << std::endl;
	for (char ch : s) {
		if (map[ch] == 1) {
			std::cout << ch << " ";
        }
	}
	std::cout << std::endl;
    return 0;
}
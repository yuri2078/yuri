#include <iostream>
int main(int argc, char const* argv[])
{
	int set[16]{1};
	for (int i = 1; set[i] <= 10000000; i++) {
		set[i] = set[i - 1] * 3;
	}
	
	for (int i = 0; i < 15; i++) {
		std::cout << set[i] << "  ";
	}
	std::cout << std::endl;
	return 0;
}

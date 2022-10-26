#include <iostream>
#include <ostream>
#include <type_traits>

int main(int argc, const char *argv[])
{
	std::cout << std::is_same<char, char>::value << std::endl;
	return 0;
}
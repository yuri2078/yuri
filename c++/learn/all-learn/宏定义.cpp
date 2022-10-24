#include <iostream>
#include <ostream>
#include <string>
#define STR(s) #s //一个#把他变成字符串
#define ADD(a,b) a##b

int main(int argc, const char *argv[])
{
	std::string s = STR(yuri is yes);
	std::cout << s << std::endl;
	std::cout << ADD(4,4) << std::endl;
    return 0;
}
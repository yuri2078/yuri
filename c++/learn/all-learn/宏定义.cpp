// 如果没有定义就定义

#ifndef 头文件 // 如果没有定义
#define 头文件 // 那么就定义

#include <iostream>
#include <string>

#define MIN(x, y) (x > y ? y : x)
#define error(msg) \
	printf(msg);   \
	putchar(10);   \
	return 1;

int main(int argc, const char* argv[])
{
	int x = 6, y = 7;
	std::cout << MIN(x, y) << std::endl;
	error("yuri is yes");
#ifdef __GNUC__
	std::cout << "定义了GNUC";
#endif

#ifndef __GNUC__
	std::cout << "没有定义GNUC";

#endif
	return 0;
}

#undef 头文件 // 取消定义宏，一般宏作用直到文件尾部
#endif        // ifndef 与 ifdef 结尾
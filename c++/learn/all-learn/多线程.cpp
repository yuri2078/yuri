#include <cstdio>
#include <iostream>
#include <iterator>
#include <thread>


void test(int x, int y)
{
	for (int i = 0; i < 100; i++) {
        std::cout << "线程处理中 : " << i  << std::endl;
	}
	printf("\n");
}

int main(int argc, const char *argv[])
{
	std::thread th1(test, 5, 6);
	// 创建多线程对象，默认构造函数什么也不干
	// 传入函数名字则可以开启多线程，如果有参数，需要传入参数

	for (int i = 0; i < 100; i++) {
        std::cout << "(2)  线程处理中 : " << i << std::endl;
	}
	printf("\n");


	th1.join();
    return 0;
}
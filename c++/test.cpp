#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;
class Person
{
public:
	void test()
	{
		cout << "你好，世界！" << endl;
	}
};

int main()
{
	Person().test();
	// getchar();
	return 0;
}
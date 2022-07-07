#include <iostream>
#include <stdio.h>
using std::cout;
using std::endl;
class Person
{
public:
	void test()
	{
		cout << "hello world " << endl;
	}
};

int main()
{
	Person().test();
	return 0;
}
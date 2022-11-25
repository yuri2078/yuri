#include <iostream>
#include <utility>
#include "allocator.h"
using namespace std;

class Person
{
private:
public:
	int age;
	Person()
	{
		age = 6666;
		std::cout << "默认构造函数\n";
	}
	Person(int x)
	{
		age = x;
		std::cout << "默认构造函数(x)\n";
	}
	Person(Person &p)
	{
		age = p.age;
		std::cout << "拷贝构造函数\n";
	}

	Person(Person &&p)
	{
		age = p.age;
		std::cout << "移动构造函数\n";
	}
	~Person()
	{
		std::cout << "调用析构函数\n";
    };
};
template <int>
struct val {
	
};

int main()
{
	yuriSTL::allocator<Person> p;
    return 0;
}
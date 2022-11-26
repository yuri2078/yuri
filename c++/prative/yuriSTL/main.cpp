#include <iostream>
#include "allocator.h"
#include "base.h"
#include <vector>
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
		std::cout << "调用析构函数" << age << "  \n";
    };
};


int main()
{
	yuriSTL::size_type size =10;
	yuriSTL::allocator<Person> allo;
	Person* pp = allo.allocate(10);
	allo.construct(pp, 66);
	allo.construct(pp + 1, 67);
	allo.construct(pp + 2, 68);
	allo.construct(pp + 3, 69);
	allo.construct(pp + 4, 70);
	allo.construct(pp + 5, 71);
	allo.destroy(pp, size);

	yuriSTL::allocator<int> iallo;
	int* ppp = iallo.allocate();
	iallo.destroy(ppp,1);
    return 0;
}
#include "vector.h"
#include "list.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;
class Person
{

public:
	int age;
	string name;
	Person()
	{
		cout << "默认构造函数\n";
		age = 0;
		name = "default";
	}

	Person(int age)
	{
		cout << "默认构造函数\n";
		this->age = age;
		name = "default-age";
	}

	Person(string&& name, int age)
	{
		cout << "默认构造函数\n";
		this->age = age;
		this->name = name;
	}

	Person(const Person& p)
	{
		cout << "拷贝构造函数\n";
		this->age = p.age;
		this->name = p.name;
	}

	Person(Person&& p) noexcept
	{
		cout << "移动构造函数\n";
		this->age = p.age;
		this->name = p.name;
	}

	Person& operator=(const Person& p)
	{
		cout << "= 号构造函数\n";
		this->age = p.age;
		this->name = p.name;
		return *this;
	}

	~Person()
	{
		cout << this->name << " 被析构啦 "
		     << "age : " << this->age << endl;
	}

	
};

ostream& operator<<(ostream& cout, Person &p)
{
	cout << "age -> " << p.age << endl;
	return cout;
}

int main()
{
	yuriSTL::list<int> list;
	list.push_back(44);
	list.push_back(45);
	list.push_back(46);
	list.push_back(47);

	list.showAllValue();
	return 0;
}
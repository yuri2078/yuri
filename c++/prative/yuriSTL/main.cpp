#include "vector.h"
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

	Person(Person& p)
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

	Person& operator=(Person& p)
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

int main()
{
	Person p;
	yuriSTL::vector<Person> vec;
	vec.push_back(p);
	vec.push_back(p);
	vec.push_back(p);
	vec.push_back(p);
	vec.push_back(p);
	cout << "  ---- \n";
	vec.at(11);
	
	return 0;
}
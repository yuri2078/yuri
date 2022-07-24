#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Person
{
private:
	/* data */

public:
	int age;
	string name;

	Person(/* args */);
	~Person();
};

Person::Person(/* args */)
{
	this->age = 666;
	name = "牛鼻";
}

Person::~Person()
{

}



int main()
{
	Person **name;
	name = new Person *[10];
	for (int i = 0; i < 10;i++)
	{
		name[i] = new Person [10];
	}

	for (int i = 0; i < 10;i++)
	{
		for (int j = 0; j < 10;j++)
		{
			cout << name[i][j].age << " ";
		}
		std::cout << std::endl;
	}
	std::cout << "sizeof -- name " << sizeof(name[0][0]) << std::endl;
	return 0;
}
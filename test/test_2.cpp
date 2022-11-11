#include <iostream>
#include <memory>

using namespace std;

class Person
{
private:
    string name;

public:
	Person(string name)
	{
		this->name = name;
		cout << name << "类创建\n";
    }
	~Person()
	{
		cout << name << "类析构\n";
    }
};


int main()
{
	unique_ptr<Person> p;
	p = make_unique<Person>("1");
	cout << "666\n";
	p = make_unique<Person>("2");
	cout << "555\n";
    return 0;
}
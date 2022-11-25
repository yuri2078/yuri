#include "vector.h"

#include <iostream>
using namespace std;

class Person
{
private:
public:
	int age;
	Person()
	{
		age = 666;
		cout << "调用普通构造函数\n";
    };
    ~Person() = default;
};

int main()
{
	Person p;
	mystl::vector<Person> vec(5, p);
	vec[1].age = 6666;
	cout << vec[1].age << endl;
	cout << p.age << endl;
    return 0;
}
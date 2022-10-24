#include <iostream>
#include <memory>
#include <type_traits>
#include <utility>

class Person
{
private:
	/* data */
public:
	Person() = default;
	Person(const Person&& p); //移动构造函数
	~Person();
};

Person::~Person() { std::cout << "类析构\n"; }

Person::Person(const Person&& p)
{
	std::cout << "调用移动构造函数\n";
	//当那个值不再使用时可以调用移动构造函数
	//系统会直接把原来的值移动到新的地方，避免了拷贝的时间
	//复制完了一般不能再使用
}

void test_1(const int& x) { std::cout << "调用普通引用\n"; }

void test_1(const int&& x) { std::cout << "调用左值引用函数\n"; }

void test_2(const Person& p1)
{
	std::cout << "perons "
	          << "调用普通引用\n";
}

void test_2(const Person&& p2)
{
	std::cout << "perons "
	          << "调用左值引用函数\n";
}

int main(int argc, char const* argv[])
{
	int x = 666;
	Person p;
	Person pp = std::move(p);
	test_1(666);          //调用左值引用
	test_1(x);            //调用普通引用
	test_2(p);            //调用普通引用
	test_2(std::move(p)); //调用左值引用
	return 0;
}

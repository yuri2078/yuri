#include <iostream>
using namespace std;

struct val_false {
};

struct val_true {
};

template <class T>
struct value {
	typedef val_true __type;
};

template <>
struct value<int> {
	typedef val_false __type;
};


void fun(val_false)
{
	cout << "false\n";
}

void fun(val_true)
{
	cout << "treu\n";
}

int main()
{
	value<char>::__type v;
	fun(v);
	return 0;
}
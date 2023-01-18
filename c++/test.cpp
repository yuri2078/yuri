#include <iostream>
#include <memory>
using namespace std;
int main()
{
	int* p = nullptr;
	::operator delete(p);
	return 0;
}
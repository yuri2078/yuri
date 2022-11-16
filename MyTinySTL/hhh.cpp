#include "vector.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	mystl::vector<char> v;
	v.push_back('a');
	cout << v[0] << endl;
    return 0;
}
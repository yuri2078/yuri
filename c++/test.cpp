#include <algorithm>
#include <iostream>
#include <memory>
#include <type_traits>
#include <utility>
#include <vector>
using namespace std;

int main(int argc, char const* argv[])
{
	vector<int> vec;
	std::remove_reference<vector<int>>::type hh;
	allocator<int> alloc;
	return 0;
}

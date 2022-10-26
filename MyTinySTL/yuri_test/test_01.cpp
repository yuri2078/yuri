#include "../vector.h"
#include <iostream>

using yuri = int;

int main(int argc, const char *argv[])
{
	mystl::vector<int> v;
	v.push_back(5);

	for (yuri x : v) {
        std::cout << x << std::endl;
    }
    return 0;
}
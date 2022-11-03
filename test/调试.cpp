#include <iostream>
#include <vector>


using std::vector;


int main(int argc, const char *argv[])
{
	vector<int> v;
	for (int i = 0; i < 10; i++) {
        v.push_back(i);
    }
    return 0;
}
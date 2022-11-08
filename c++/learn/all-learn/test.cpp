#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
	unordered_set<int> set;
	set.insert(5);
	set.insert(6);
	for (auto s : set) {
        cout << s << "  ";
	}
	cout << endl;
    return 0;
}
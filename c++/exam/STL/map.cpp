#include <iostream>
#include <map>
#include <utility>

using std::cout;
using std::make_pair;
using std::multimap;


int main()
{
	multimap<int, int> map;
	map.insert(make_pair(6, 66));
	map.insert(make_pair(6,555));
	// cout << map.count(6) << "\n";
	// cout << map.find(6)->second << "\n";
	map.erase(map.find(6));
	for (auto begin = map.begin(); begin != map.end(); begin++) {
        cout << begin->second << "\n";
    }
	
	return 0;
}
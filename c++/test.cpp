#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	int x;
	
	while (1) {
		cin >> x;
		vector<int> vec;
		while (x) {
			vec.push_back(x % 2);
			x /= 2;
		}
		for (int i = vec.size() - 1; i >= 0; i--) {
			cout << vec[i];
		}
		cout << endl;
	}
	return 0;
}
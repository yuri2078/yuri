
#include <iostream>
#include <ctime>
#include <vector>
using namespace std;



int main()
{
	clock_t start, end;

	start = clock();
	vector<int> v(2);
	for (int i = 0; i < 1000000000; i++) {
		v.push_back(i);
	}

	end = clock();
	cout << start << endl;
	
	cout << end << endl;
	cout << (end - start) << "   ms\n";
	cout << (end - start) / CLOCKS_PER_SEC  << " s\n";
	cout << CLOCKS_PER_SEC << endl;
    return 0;
}
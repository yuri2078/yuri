
#include <iostream>
#include <ctime>
#include <ostream>
using namespace std;
int main()
{
	time_t start, stop;
	
	start = time(NULL);
	for (int i = 0; i < 1000000; i++) {
		
        cout << i;
	}
	cout << endl;
	stop = time(NULL);
	cout << stop - start << endl;
}
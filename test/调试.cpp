#include <iostream>
#include <yuri.h>
using namespace std;

void fun()
{
	int j = 0;
	long long int x = 2000000;
	for (int i = 2; i < x; i++) {
		for (j = 2; j <= i / 2; j++) {
			if (i % j == 0) {
				break;
			}
		}
		if (j > i / 2) {
			cout << i << " ";
		}
	}
	cout << endl;
}

int main()
{

	yuri::Yuri::used_time(fun);

	return 0;
}
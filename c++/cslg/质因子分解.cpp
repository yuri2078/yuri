#include <iostream>
#include <cmath>

typedef long long int lint;

using namespace std;

lint gys(lint a, lint b)
{
	while (a != b) {
		if (a - b > 0) {
			a -= b;
		} else {
			b -= a;
		}
	}
	return a;
}

void primeFactorization(lint num)
{
	if (num == 1) {
		cout << 1 << endl;
		return;
	}
	int up = (lint)sqrt(num) + 1;
	for (lint i = 2; i < up; ++i) {
		while (num % i == 0) {
			num /= i;
			cout << i << " ";
		}
	}
	//若最后剩余数不为1，则为最后一个质因数
	if (num != 1) {
		cout << num;
	}

	cout << endl;
}


int main()
{
	lint x = 0, y = 0;
	cin >> x >> y;
	primeFactorization(gys(x, y));
	return 0;
}

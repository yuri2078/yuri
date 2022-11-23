#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

#define MIN(x,y) x > y ? y : x

int main()
{
	int k, n;
	cin >> n >> k;
	vector<int> number(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &number[i]);
	}
	sort(number.begin(), number.end());
	if (k == n - 1) {
		cout << number[0] << endl;
		return 0;
    }
	int max_val = number[n - 1] - number[0];
	const int size = number.size() - 1;
	for (int i = 0; i <= k; i++) {
		for (int j = 0; j <= k - i; j++) {
			max_val = MIN(max_val, number[size - j] - number[i]);
		}
    }
	cout << max_val << endl;
	return 0;
}
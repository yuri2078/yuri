#include <iostream>
#include <map>
#include <vector>
#include <list>
using namespace std;

void fun(int x, list<long long int>& number)
{
	int t = 2;
	while (x && t <= x) {
		if (x % t == 0) {
			while (x % t == 0) {
				number.push_back(t);
				x /= t;
			}
		} else {
			t++;
		}
	}
	// cout << endl;
}

vector<int> intersect(list<long long int>& nums1, list<long long int>& nums2)
{
	vector<int> nums3;
	multimap<int, int> m_1;
	if (nums1.size() > nums2.size()) {
		return intersect(nums2,nums1);
	}
	for (int x: nums2) {
		m_1.insert(make_pair(x, 6));
	}
	for (int x: nums1) {
		if (m_1.find(x) != m_1.end()) {
			nums3.push_back(x);
			m_1.erase(m_1.find(x));
		}
	}

	return nums3;
}
int main()
{
	long long int x_1 , x_2;
	cin >> x_1 >> x_2;
	list<long long int> v_1, v_2;
	fun(x_1, v_1);
	fun(x_2, v_2);
	vector<int> num = intersect(v_1, v_2);
	for (int x: num) {
		cout << x << " ";
	}
	if (num.size() == 0) {
		cout << 1;
	}
	cout << endl;
	return 0;
}

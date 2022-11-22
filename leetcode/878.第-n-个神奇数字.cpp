/*
 * @lc app=leetcode.cn id=878 lang=cpp
 *
 * [878] 第 N 个神奇数字
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
public:
	int nthMagicalNumber(int n, int a, int b)
	{
		if (a > b) {
			return nthMagicalNumber(n, b, a);
        }
		long long mod = 1e9 + 7, num_a = 0, num_b = 0, ans = a;
		for (int i = 0; i < n; i++) {
			if (num_a + a <= num_b + b) {
				num_a += a;
				ans = num_a;
			} else {
				num_b += b;
				ans = num_b;
			}

			if (num_a == num_b) {
				i--;
			}
		}
		cout << num_a << "  " << num_b << "   \n";
		return ans % mod;
	}
};




int main()
{
    cout << Solution().nthMagicalNumber(217, 3400, 40000) << endl;
    return 0;
}
// @lc code=end


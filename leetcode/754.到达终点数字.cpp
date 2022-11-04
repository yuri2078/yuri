/*
 * @lc app=leetcode.cn id=754 lang=cpp
 *
 * [754] 到达终点数字
 */

// @lc code=start
#include <iostream>
using namespace std;

class Solution {
public:
	static int reachNumber(int target)
	{
		if (target < 0) {
			return reachNumber(-target);
		}

		int ans = 0;
		int k = 1;
		while (ans < target) {
			ans += k;
			k++;
		}
		
		if ((ans - target) % 2 == 0) {
			return k - 1;
		}

		return (ans + k - target) % 2 == 0 || (ans - k - target) % 2 == 0 ? k : k + 1;
    }
};




// int main(int argc, const char **argv)
// {
// 	cout << Solution::reachNumber(39) << endl;
//     return 0;
// }
// @lc code=end


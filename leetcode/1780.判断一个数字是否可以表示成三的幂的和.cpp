/*
 * @lc app=leetcode.cn id=1780 lang=cpp
 *
 * [1780] 判断一个数字是否可以表示成三的幂的和
 */

// @lc code=start
#include <iostream>
using namespace std;
class Solution {
public:
    bool checkPowersOfThree(int n) {
		int set[20]{1}, i;
		for (i = 1; set[i - 1] <= 10000000; i++) {
			set[i] = set[i - 1] * 3;
		}
		i = i - 2;
		while (i >= 0) {
			cout << set[i] << " ";
			if (set[i] <= n) {
				n -= set[i];
				// cout << set[i] << " ";
			}
			i--;
        }
		cout << endl;
		return n == 0;
    }
};

// @lc code=end


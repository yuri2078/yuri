/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 */

// @lc code=start

#include <cstdint>
#include <iostream>
class Solution
{
public:
	int divide(int dividend, int divisor)
	{
        if(divisor == 1){
            return dividend;
        }

		if (dividend == INT32_MIN && divisor == -1) {
			return INT32_MAX;
		}

        if(divisor == -1){
            return -dividend;
        }

		bool flag = false;
		if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
			flag = true;
		}

		if (dividend > 0) {
			dividend = -dividend;
		}

		if (divisor > 0) {
			divisor = -divisor;
		}

		if (dividend > divisor) {
			return 0;
		}

		int left = 1, right = INT32_MAX - 1, res = 0, k;
		while (left <= right) {
			res = (left >> 1) + (right >> 1);
			k = results(divisor, res, dividend);
			if (k == 2) {
				return flag ? res : - res;
			} else if (k == 0) {
				left = res + 1;
			} else {
				right = res - 1;
			}
		}
		return flag ? res : - res;
	}

	int results(int x, int y, int z)
	{
		int ans = 0, temp = x;
		while (y) {
			if (y & 1) {
				if (x < INT32_MIN - ans) {
					return 1;
				}
				ans += x;
			}
			y = y >> 1;
			if (y && x < INT32_MIN >> 1) {
				return 1;
			}

            if(x >= INT32_MIN >> 1){
                x = x + x;
            }
			
		}
		if (ans == z || ( ans > z && abs(ans - z) < abs(temp))) {
			return 2;
		}
		return ans < z;
	}
};

// @lc code=end

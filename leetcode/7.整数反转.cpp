/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include <cmath>
class Solution {
public:
    int reverse(int x) {
        long long int s = 0;
        while (x)
        {
            s = s * 10 + x % 10;
            x = x / 10;
        }

        return (int)s == s ? s : 0;

        return s;
    }
};
// @lc code=end


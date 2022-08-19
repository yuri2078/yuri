/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        string number = to_string(x);
        for (int i = 0; i < number.length() / 2; i++)
        {
            if (number[i] != number[number.length() - i - 1])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        long long sum = 0;
        int f = 1;
        for (long unsigned int i = 0; i < s.length(); i++)
        {
            if(isdigit(s[i]))
            {
                if(i > 1 && s[i - 1] == '-'){
                    f = -1;
                }
                while (isdigit(s[i]) && i < s.length())
                {
                    sum = sum * 10 + (s[i] - 48);
                    i++;
                }
            }
        }
        return (int)sum == sum ? sum * f: 2147483647;
    }
};
// @lc code=end


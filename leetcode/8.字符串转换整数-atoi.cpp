/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0, f = 1;
        long long int sum = 0;

        while (i < s.length() && ' ' == s[i]){
            i++;
        }

        if (i < s.length() && (s[i] == '-' || s[i] == '+'))
        {
            f = s[i] == '-' ? -1 : 1;
            i++;
        }
        while (i < s.length() && isdigit(s[i]))
        {
            sum = sum * 10 + (s[i++] - '0');
            if (sum > INT32_MAX || sum < INT32_MIN){
                return f == 1 ? INT32_MAX : INT32_MIN;
            }
        }
        return sum * f;
    }
};
// @lc code=end


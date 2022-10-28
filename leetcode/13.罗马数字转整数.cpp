/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <string>
#include <unordered_map>

using namespace std;
class Solution {
public:
	int romanToInt(string s)
	{
		const int size = s.size();
		int ans = 0;
		int getNum[26];
		getNum['I' - 'A'] = 1;
		getNum['V' - 'A'] = 5;
		getNum['X' - 'A'] = 10;
		getNum['L' - 'A'] = 50;
		getNum['C' - 'A'] = 100;
		getNum['D' - 'A'] = 500;
		getNum['M' - 'A'] = 1000;
		for (int i = 0; i < size; i++) {
			if (i < size - 1 && getNum[s[i] - 'A'] < getNum[s[i + 1] - 'A']) {
				ans = ans + getNum[s[i + 1] - 'A'] - getNum[s[i] - 'A'];
				i++;
			} else {
				ans += getNum[s[i] - 'A'];
            }
        }
		return ans;
	}

};
// @lc code=end


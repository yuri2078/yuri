/*
 * @lc app=leetcode.cn id=791 lang=cpp
 *
 * [791] 自定义字符串排序
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string customSortString(string order, string s) {
		int k = order.size();
		int rule[26]{};
		for (char ch : order) {
            rule[ch - 'a'] = k--;
		}
		sort(s.begin(), s.end(), [&](char& c1, char& c2) {
			return rule[c1 - 'a'] > rule[c2 - 'a'];
		});
		
		return s;
    }
};

// @lc code=end


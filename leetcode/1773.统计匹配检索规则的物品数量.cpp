/*
 * @lc app=leetcode.cn id=1773 lang=cpp
 *
 * [1773] 统计匹配检索规则的物品数量
 */

// @lc code=start
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
		int ans = 0, k;
		if (ruleKey == "type") {
            k = 0;
		} else if (ruleKey == "color") {
			k = 1;
		} else {
			k = 2;
		}

		const int size = items.size();
		for (int i = 0; i < size; i++) {
			if (items[i][k] == ruleValue) {
				ans++;
            }
		}
		return ans;
    }
};
// @lc code=end


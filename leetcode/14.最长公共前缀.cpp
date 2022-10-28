/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		const int size = strs.size();
		if (size == 1) {
			return strs[0];
		}
		int k = 0;
		while (strs[0][k] && strs[0][k] == strs[1][k]) {
            k++;
		}
		for (int i = 2; i < size && k; i++) {
			int j = 0;
			while (j < k && strs[i][j] && strs[0][j] == strs[i][j]) {
				j++;
			}
			k = min(k, j);
        }
		return strs[0].substr(0,k);
    }
};
// @lc code=end


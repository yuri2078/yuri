/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include <iostream>
#include <unordered_set>
#include <vector>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_set<int> set;
		for (int x : nums) {
			if (set.find(x) != set.end()) {
				return true;
			}
			set.insert(x);
		}
		
        return false;
    }
};
// @lc code=end


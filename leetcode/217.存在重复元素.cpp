/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
#include <iostream>
#include <utility>
#include <vector>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		map<int, int> m_1;
		for (int x : nums) {
			if (m_1.find(x) != m_1.end()) {
				return true;
			}
			m_1.insert(make_pair(x,6));
        }
		
        return false;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> nums3;
		multimap<int, int> m_1;
		vector<int>& little = nums1.size() < nums2.size() ? nums1 : nums2;
		vector<int>& big = nums1.size() >= nums2.size() ? nums1 : nums2;
		for (int x: big) {
			m_1.insert(make_pair(x, 6));
		}
		for (int x: little) {
			if (m_1.find(x) != m_1.end()) {
				nums3.push_back(x);
				m_1.erase(m_1.find(x));
			}
		}

		return nums3;
	}
};

// @lc code=end

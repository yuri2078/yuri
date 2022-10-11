/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <iostream>
#include <utility>
#include <vector>
#include <map>
using namespace std;
// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums3;
	    multimap<int,int> m_1;
		vector<int>& little = nums1.size() < nums2.size() ? nums1 : nums2;
		vector<int>& big = nums1.size() > nums2.size() ? nums1 : nums2;
		for (int x : big) {
            m_1.insert(make_pair(x,6));
		}
		for (int x : little) {
			if (m_1.find(x) != m_1.end() ) {
				m_1.find(x)->second = 0;
				nums3.push_back(x);
            }
        }
		return nums3;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int s[m + n];
		int p1 = 0, p2 = 0;
		while (p1 < m || p2 < n) {
			int temp = 0;
			if (p1 == m) {
				temp = nums2[p2++];
			}else if (p2 == n) {
				temp = nums1[p1++];
			}else if (nums1[p1] < nums2[p2]) {
				temp = nums1[p1++];
			}else {
				temp = nums2[p2++];
			}
			s[p1 + p2 - 1] = temp;
		}
		for (int i = 0; i < m + n; i++) {
			nums1[i] = s[i];
		}

	}
};

// @lc code=end

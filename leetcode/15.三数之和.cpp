/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> v;
		sort(nums.begin(), nums.end());
		for (int k = 0; k < nums.size() - 2; k++) {
			if (k > 0 && nums[k] == nums[k - 1]) {
				continue;
			}
			if (nums[k] > 0) {
				break;
            }
			int i = k + 1;
			int j = nums.size() - 1;
			while (i < j) {
				int sum = nums[k] + nums[i] + nums[j];
				if (sum > 0) {
					j--;
					while (i < j && nums[j] == nums[j + 1]) {
                        j--;
                    }
				} else if (sum < 0) {
					i++;
					while (i < j && nums[i] == nums[i - 1]) {
                        i++;
                    }
				} else {
					v.push_back({nums[k], nums[i], nums[j]});
					i++;
					j--;
					while (i < j && nums[j] == nums[j + 1]) {
                        j--;
					}
					while (i < j && nums[i] == nums[i - 1]) {
                        i++;
                    }
                }
            }
        }
		
		return v;
    }
};
// @lc code=end


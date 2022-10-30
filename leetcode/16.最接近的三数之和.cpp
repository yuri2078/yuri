/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <algorithm>
#include <cstdint>
#include <vector>

using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		int ans = target > 0 ? INT32_MAX - target : INT32_MAX + target;
		const int size = nums.size();
		sort(nums.begin(), nums.end());
		for (int i = 0; i < size - 2; i++) {
			if (i > 0 && nums[i] == nums[i - 1]) {
				continue;
			}
			int start = i + 1;
			int end = size - 1;
			while (start < end ) {
				int sum = nums[i] + nums[start] + nums[end];
				sum > target ? end-- : start++;
				if (abs(target - sum) < abs(target - ans)) {
					ans = sum;
                }
            }
        }
		
		return ans ;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	static vector<vector<int>> fourSum(vector<int>& nums, int target)
	{
		vector<vector<int>> ans;
		const int size = nums.size();
		if (size < 4) {
			return ans;
		}
		sort(nums.begin(), nums.end());
		for (int i = 0; i < size - 3; i++) {
			if (i != 0 && nums[i] == nums[i - 1]) {
				continue;
			}

	
			if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
				break;
			}

			for (int j = i + 1; j < size - 2; j++) {
				if (j != i + 1 && nums[j] == nums[j - 1]) {
					continue;
				}

				if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
					break;
                }

				for (int tail = size - 1; tail > j + 1; tail--) {
					if (tail != size - 1 && nums[tail] == nums[tail + 1]) {
						continue;
					}

					for (int k = tail - 1; k > j; k--) {
						if (k != tail - 1 && nums[k] == nums[k + 1]) {
							continue;
						}
						
						if ((long) nums[i] + nums[j] + nums[tail] + nums[k] == target) {
							ans.push_back({nums[i], nums[j], nums[k], nums[tail]});
						}
						
					}
				}
			}
		}
		return ans;
	}
};


// @lc code=end

/*
 * @lc app=leetcode.cn id=1752 lang=cpp
 *
 * [1752] 检查数组是否经排序和轮转得到
 */

// @lc code=start
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
	/*
	    我的垃圾代码。。 排序后，直接无脑for循环判断
	    bool check(vector<int>& nums) {
	        vector<int> nums_cp = nums;
	        sort(nums_cp.begin(), nums_cp.end());
	        const int size = nums.size();
	        for (int i = 0; i < size; i++) {
	            int j = 0;
	            while (j < size && nums[j] == nums_cp[(j + i) % size]) {
	                j++;
	            }
	            if (j == size) {
	                return true;
	            }
	        }

	        return false;
	    }
	*/
	// 大佬的解法 :
	// 既然是由一个非递减序列组成，那么 一定 nums[i] <= nums[j]  i < j < size
	// 既然本序列是由源序列环型移动得到的，那么他也一样满足这个条件，除了首尾交界的地方
	// 那么之用判断这个序列是不是满足至多有一个数大于后面的数的情况

	bool check(vector<int>& nums)
	{
		const int size = nums.size();
		int cur = 0;
        for (int i = 0; i < size; ++i) {
			if (nums[i] > nums[(i + 1) % size]) {
				cur++;
            }
        }
        return cur <= 1;
    }
    
};
// @lc code=end


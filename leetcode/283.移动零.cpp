/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    // 利用双指针先处理非0数据
    int res = 0, size = nums.size();
    for (int i = 0; i < size; i++) {
      if (nums[i]) {
        nums[res++] = nums[i];
      }
    }
    
    // 后面数据填充0
    for (int i = res; i < size; i++) {
      nums[i] = 0;
    }
  }
};
// @lc code=end

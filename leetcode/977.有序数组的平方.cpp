/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
// 137/137 cases passed (20 ms)
// Your runtime beats 93.31 % of cpp submissions
// Your memory usage beats 27.23 % of cpp submissions (25.3 MB)

#include <vector>
using namespace std;

class Solution {
public:
  // 利用双指针从两边开始逐渐向中间插入
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> res(nums.size());
    int left = 0, right = nums.size() - 1, k = nums.size() - 1;
    while (k != -1) {
      // 先去除负值
      int x = nums[left] < 0 ? -nums[left] : nums[left];
      int y = nums[right] < 0 ? -nums[right] : nums[right];
      // 插入较大的并且移动指针
      if (x < y) {
        res[k--] = y * y;
        right--;
      } else {
        res[k--] = x * x;
        left++;
      }
    }
    return res;
  }
};
// @lc code=end

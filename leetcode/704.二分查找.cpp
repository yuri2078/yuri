/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int start = 0, end = nums.size() - 1, h = start + ((end - start) >> 1);
    // 中间值通过 start + (end - start) / 2计算，防止溢出
    // start:起点 end:终点 h:中间点
    while (start <= end) {
      // 如果相等直接返回
      if (nums[h] == target) {
        return h;
      }
      // 如果中间大则更新起点
      // 如果中间小则更新终点
      if (nums[h] > target) {
        end = h - 1;
      } else {
        start = h + 1;
      }
      h = start + ((end - start) >> 1);
    }
    return -1;
  }
};
// @lc code=end

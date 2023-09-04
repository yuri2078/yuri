/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
// 21/21 cases passed (28 ms)
// Your runtime beats 83.3 % of cpp submissions
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  // 滑动窗口解法
  int minSubArrayLen(int target, vector<int> &nums) {
    int res = 555555; // 返回最小序列
    int size = nums.size(); // 数组长度
    int sum = 0;            // 窗口总和
    int j = 0;              // 窗口起点
    for (int i = 0; i < size; i++) {
      sum += nums[i]; // 将数据添加进窗口中
      // 当窗口的总和大于目标值时，我们就要将窗口起点向后移动
      while (sum >= target) {
        res = std::min(res, i - j + 1);
        sum -= nums[j++]; // 减掉最开始的起点
      }
    }
    return res == 555555 ? 0 : res; 
  }
};
// @lc code=end

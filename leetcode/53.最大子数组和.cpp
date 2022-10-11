/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    int max = nums[0], s = 0;
    for (int x : nums) {
      if (s + x > 0) {
        s += x;
        max = max > s ? max : s;
      } else {
        s = 0;
      }
      max = max > x ? max : x;
    }
    return max;
  }
};
// @lc code=end

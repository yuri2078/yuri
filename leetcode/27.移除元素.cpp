/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int res = 0, size = nums.size();
    for (int i = 0; i < size; i++) {
      if (nums[i] != val) {
        nums[res++] = nums[i];
      }
    }
    return res;
  }
};
// @lc code=end

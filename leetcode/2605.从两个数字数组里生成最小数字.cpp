/*
 * @lc app=leetcode.cn id=2605 lang=cpp
 *
 * [2605] 从两个数字数组里生成最小数字
 */

// @lc code=start

#include <vector>
#include <set>
using namespace std;

class Solution {
public:
  int minNumber(vector<int> &nums1, vector<int> &nums2) {
    set<int> num1;
    set<int> num2;
    int num[10]{};
    for (int x : nums1) {
      num1.insert(x);
      num[x]++;
    }

    for (int x : nums2) {
      num2.insert(x);
      num[x]++;
    }

    for (int i = 1; i < 10; i++) {
      if (num[i] == 2) {
        return i;
      }
    }
    
    if (*num1.begin() > *num2.begin()) {
      return *num2.begin() * 10 + *(num1.begin());
    }

    return *num1.begin() * 10 + *(num2.begin());
  }
};
// @lc code=end

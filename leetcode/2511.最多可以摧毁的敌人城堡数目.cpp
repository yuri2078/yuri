/*
 * @lc app=leetcode.cn id=2511 lang=cpp
 *
 * [2511] 最多可以摧毁的敌人城堡数目
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int captureForts(vector<int> &forts) {
    int res = 0, size = forts.size(), k = 0 , start = -2;
    for (int i = 0; i < size; i++) {
      if (forts[i] != 0) {
        if (start != forts[i]) {
          start = forts[i];
          if (res < k) {
            res = k;
          }
          k = 0;
        } else {
          k = 0;
        }
        continue;
      }
      if (start != -2) {
        k++;
      }
    }
    return res;
  }
};
// @lc code=end

/*
 * @lc app=leetcode.cn id=2032 lang=cpp
 *
 * [2032] 至少在两个数组中出现的值
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
  vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
    vector<int> res;
    unordered_set<int> set_1, set_2, set_3, set;
    for (int x : nums1) {
      set_1.insert(x);
      set.insert(x);
    }
    
    for (int x : nums2) {
      set_2.insert(x);
      set.insert(x);
    }
    
    for (int x : nums3) {
      set_3.insert(x);
      set.insert(x);
    }


    for (int x : set) {
      if (set_1.count(x) && set_2.count(x) || set_2.count(x) && set_3.count(x) || set_1.count(x) && set_3.count(x)) {
        res.push_back(x);
	  }
	}
    return res;
  }
};
// @lc code=end

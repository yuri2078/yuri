/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <map>
#include <utility>
#include <vector>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> m_1;
        vector<int> v_1;
        for (int i = 0; i < nums.size(); i++)
        {
            m_1.insert(make_pair(nums[i], i));
            if (m_1.find(target - nums[i]) != m_1.end() && m_1.at(target - nums[i]) != i)
            {
                v_1.push_back(m_1.at(target - nums[i]));
                v_1.push_back(i);
            }
            
        }
        return v_1;
    }
};
// @lc code=end


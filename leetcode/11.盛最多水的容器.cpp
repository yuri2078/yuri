/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <algorithm>
#include <iostream>
#include <type_traits>
#include <vector>
using namespace std;

// @lc code=start
// class Solution {
// public:
// 	int maxArea(vector<int>& height) {
// 		int max = 0;
// 		const int size = height.size();
// 		for (int i = 0; i < size - 1; i++) {
// 			if ((size - i) * height[i] < max) {
// 				continue;
//             }
// 			for (int j = i + 1; j < height.size(); j++) {
// 				if ((j - i) * height[i] < max) {
// 					continue;
//                 }
// 				int sum = (j - i) * min(height[i], height[j]);
// 				if (max < sum) {
// 					max = sum;
//                 }
//             }
//         }
//         return max;
//     }
// };
class Solution {
public:
	int maxArea(vector<int>& height) {
		const int size = height.size();
		int max = 0, i = 0, j = size - 1;
		while (i < j) {
			int sum = (j - i) * min(height[i], height[j]);
			if (sum > max) {
				max = sum;
			}
			if (height[i] < height[j]) {
				i++;
			} else {
				j--;
            }
        }
        return max;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=1769 lang=cpp
 *
 * [1769] 移动所有球到每个盒子所需的最小操作数
 */

// @lc code=start
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> minOperations(string boxes)
	{
		const int size = boxes.size();
		int len = 0;
		vector<int> res(size);
		vector<int> cur(size);
		
		for (int i = 0; i < size; i++) {
			if (boxes[i] == '1') {
				cur[len++] = i;
            }
		}
		for (int i = 0; i < size; i++) {
			int sum = 0;
			for (int j = 0; j < len; j++) {
				sum += abs(cur[j] - i);
            }
			res[i] = sum;
        }
		return res;
    }
};
// @lc code=end


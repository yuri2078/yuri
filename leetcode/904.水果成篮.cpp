/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    int res = 0; // 返回最多采摘的果树
    vector<int> fruit; // 可以采摘的种类
    int size = fruits.size(); // 果树的数量
    int j = 0;                // 窗口起点
    for (int i = 0; i < size; i++) {
      // 先添加两个不用种类的水果
      if (fruit.size() < 2 && (fruit.empty() || fruits[i] != fruit[0])) {
        fruit.emplace_back(fruits[i]);
        continue;
      }

      // 当出现第三者时重新开始存储
      if ((fruits[i] != fruit[0] && fruits[i] != fruit[1])) {
        res = std::max(res, i - j);
        // 清除数据并更改起点
        fruit.clear();
        fruit.emplace_back(fruits[i]);
        fruit.emplace_back(fruits[i - 1]);

        // 更改起点
        j = i - 1;
        while (j >= 0 && fruits[j] == fruits[i - 1]) {
          j--;
        }
        j++;
      }
    }
    res = std::max(res, size - j);
    return res == 0 ? fruits.size() : res;
  }
};
// @lc code=end

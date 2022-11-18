/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */

// @lc code=start
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode()
	    : val(0)
	    , left(nullptr)
	    , right(nullptr)
	{
	}
	TreeNode(int x)
	    : val(x)
	    , left(nullptr)
	    , right(nullptr)
	{
	}
	TreeNode(int x, TreeNode* left, TreeNode* right)
	    : val(x)
	    , left(left)
	    , right(right)
	{
	}
};

#include <queue>
#include <vector>

using namespace std;

class Solution
{
public:
	vector<double> averageOfLevels(TreeNode* root) 
	{
		vector<double> ans;
        if (!root) {
			return ans;
		}

		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			const int size = que.size();
			double sum = 0;
			for (int i = 0; i < size; i++) {
				TreeNode* t = que.front();
				
				que.pop();
				sum += t->val;
				
				if (t->left) {
					que.push(t->left);
				}
				
				if (t->right) {
					que.push(t->right);
                }
			}
			ans.push_back(sum / size);
        }

		return ans;
    }
};
// @lc code=end


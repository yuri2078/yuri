/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
	vector<int> rightSideView(TreeNode* root)
	{
		vector<int> ans;
        if (!root) {
			return ans;
		}

		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			const int size = que.size();
			vector<int> vec;
			for (int i = 0; i < size; i++) {
				TreeNode* t = que.front();
				que.pop();
				if (i == size - 1) {
					ans.push_back(t->val);
                }
				if (t->left) {
					que.push(t->left);
				}
				if (t->right) {
					que.push(t->right);
                }
			}
        }

		return ans;
    }
};
// @lc code=end

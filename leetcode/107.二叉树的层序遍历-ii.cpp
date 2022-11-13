/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 */

// @lc code=start
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

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
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> ans;
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
				vec.push_back(t->val);

				if (t->left) {
					que.push(t->left);
				}
				if (t->right) {
					que.push(t->right);
                }
			}
			ans.push_back(vec);
		}
		reverse(ans.begin(), ans.end());
        return ans;
	}

	
};
// @lc code=end


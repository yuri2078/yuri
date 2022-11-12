/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
#include <stack>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		stack<TreeNode*> sk;
		while (root || !sk.empty()) {
			if (root) {
				sk.push(root);
				root = root->left;
			} else {
				TreeNode* t = sk.top();
				sk.pop();
				ans.push_back(t->val);
				root = t->right;
            }
        }
		return ans;
    }
};
// @lc code=end


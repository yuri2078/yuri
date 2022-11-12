/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
#include <vector>
#include <stack>

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
    vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ans;
		if (!root) {
			return ans;
        }
		stack<TreeNode*> sk;
		sk.push(root);
		while (!sk.empty()) {
			TreeNode* t = sk.top();
			sk.pop();
			ans.push_back(t->val);
			if (t->right) {
				sk.push(t->right);
			}
			if (t->left) {
				sk.push(t->left);
            }
        }
		return ans;
    }
};
// @lc code=end


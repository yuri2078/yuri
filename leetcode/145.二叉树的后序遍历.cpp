/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start
#include <stack>
#include <vector>
#include <algorithm>

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
    vector<int> postorderTraversal(TreeNode* root) {
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
			if (t->left) {
				sk.push(t->left);
            }
			if (t->right) {
				sk.push(t->right);
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
    }
};
// @lc code=end


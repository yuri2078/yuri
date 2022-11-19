/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start

// Definition for a binary tree node.



#include <string>
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
	bool isSymmetric(TreeNode* root)
	{
		if (root == nullptr) {
			return true;
        }
		return result(root->left, root->right);
    }

	bool result(TreeNode* left, TreeNode* right)
	{
		if (left == nullptr && right) {
			return false;
		} else if (left && right == nullptr) {
			return false;
		} else if (left == nullptr && right == nullptr) {
			return true;
        } else if (left->val != right->val) {
			return false;
		}
		
		return result(left->left, right->right) && result(left->right, right->left);
    }
};
// @lc code=end


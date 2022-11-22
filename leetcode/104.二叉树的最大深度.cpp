/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start

// Definition for a binary tree node.
#include <queue>
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
    // int maxDepth(TreeNode* root) {
	// 	int ans = 0;
	// 	if (root == nullptr) {
	// 		return ans;
	// 	}
		
	// 	queue<TreeNode*> que;
	// 	que.push(root);
	// 	while (!que.empty()) {
	// 		const int size = que.size();
	// 		for (int i = 0; i < size; i++) {
	// 			TreeNode* node = que.front();
	// 			que.pop();
	// 			if (node->left) {
	// 				que.push(node->left);
	// 			}
	// 			if (node->right) {
	// 				que.push(node->right);
    //             }
	// 		}
	// 		ans++;
    //     }

	// 	return ans;
	// }

	int maxDepth(TreeNode* root)
	{
		int ans = 0;
		if (root == nullptr) {
			return 1;
		}
		if (root->right == nullptr && root->left == nullptr) {
			return 0;
		}

		return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
	}
};
// @lc code=end


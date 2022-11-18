/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 */

// @lc code=start
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
    int minDepth(TreeNode* root) {
		int ans = 0;
		if (root == nullptr) {
			return ans;
		}
		
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			const int size = que.size();
			ans++;
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();
				if (node->left) {
					que.push(node->left);
				}
				if (node->right) {
					que.push(node->right);
				}

				if (node->left == nullptr && node->right == nullptr) {
					return ans;
                }
            }
        }

		return ans;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
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
	vector<int> largestValues(TreeNode* root)
	{
		vector<int> ans;
        if (!root) {
			return ans;
		}
		queue<TreeNode*> que;
		que.push(root);
		while (!que.empty()) {
			const int size = que.size();
			int max_value = que.front()->val;
			for (int i = 0; i < size; i++) {
				TreeNode* node = que.front();
				que.pop();

                max_value = max_value > node->val ? max_value : node->val;
				
				if (node->left) {
					que.push(node->left);
				}
				if (node->right) {
					que.push(node->right);
                }
			}
			ans.push_back(max_value);
        }
		return ans;
    }
};
// @lc code=end


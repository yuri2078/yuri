/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

// @lc code=start
// Definition for a Node.
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
	vector<vector<int>> levelOrder(Node* root)
	{
		vector<vector<int>> ans;
		if (root == nullptr) {
			return ans;
        }
		
		queue<Node*> que;
		que.push(root);
		while (!que.empty()) {
			const int size = que.size();
			vector<int> vec;
			for (int i = 0; i < size; i++) {
				Node* node = que.front();
				que.pop();
				vec.push_back(node->val);
				for (Node *t : node->children) {
					que.push(t);
                }
			}
			ans.push_back(vec);
        }
		return ans;
    }
};
// @lc code=end


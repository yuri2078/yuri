/*
 * @lc app=leetcode.cn id=117 lang=cpp
 *
 * [117] 填充每个节点的下一个右侧节点指针 II
 */

// @lc code=start
// Definition for a Node.
#include <cstddef>
#include <queue>
#include <vector>

using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
		if (root == nullptr) {
			return nullptr;
		}

		queue<Node*> que;
		que.push(root);
		while (!que.empty()) {
			const int size = que.size();
			for (int i = 0; i < size; i++) {
				Node* node = que.front();
				que.pop();
				if (i < size - 1) {
					node->next = que.front();
				} else {
					node->next = nullptr;
				}

				if (node->left) {
					que.push(node->left);
				}

				if (node->right) {
					que.push(node->right);
                }
            }
        }
		return root;
    }
};

// @lc code=end


/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start

// Definition for singly-linked list.
#include <stack>
using std::stack;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k)
	{
		if (head == nullptr || k == 1) {
			return head;
        }
		stack<ListNode*> stack;
		ListNode *new_head = new ListNode(0, head), *node = head;
		int res = 0;
		bool flag = true;
		while (head) {
			if (res < k) {
				stack.push(head);
				head = head->next;
				res++;
			}
			if (res == k) {
				res = 0;
				if (flag) {
					node = stack.top();
					flag = false;
                }
				while (!stack.empty()) {
					ListNode* top = stack.top();
					stack.pop();
					new_head->next = top;
					new_head = top;
				}
				new_head->next = head;
			}
		}
		return node;
    }
};
// @lc code=end


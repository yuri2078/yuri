/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */

// @lc code=start

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}
		ListNode* res = head->next ? head->next : head;
		head = new ListNode(0, head);
		while (head->next && head->next->next) {
            ListNode* node = head->next->next;
            head->next->next = node->next;
            node->next = head->next;
			head->next = node;
			head = head->next->next;
        }
		return res;
    }
};
// @lc code=end


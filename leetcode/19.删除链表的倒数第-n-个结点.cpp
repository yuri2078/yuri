/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// @lc code=start

// Definition for singly-linked list.
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n)
	{
		if (head->next == nullptr && n == 1) {
			return nullptr;
        }
		int i = 0;
		vector<ListNode*> list(n + 1);
		ListNode* node = head;
		while (node) {
			list[i] = node;
			node = node->next;
			i = (i + 1) % (n + 1);
		}
		if (list[i] == nullptr) {
			return head->next;
        }
		list[i]->next = list[i]->next->next;
		return head;
    }
};
// @lc code=end


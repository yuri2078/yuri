/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
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
	ListNode* mergeKLists(vector<ListNode*>& lists)
	{
		const int size = lists.size();
		if (size == 0) {
			return nullptr;
		}
		
		ListNode* head = lists[0];
		for (int i = 1; i < size; i++) {
			head = mergeTwoLists(head, lists[i]);
        }
		return head;
	}

	// 无敌插入大法
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) {
            return l2;
        }
        if (l2 == nullptr) {
            return l1;
        }
		if (l1->val > l2->val) {
			return mergeTwoLists(l2, l1);
		}
		ListNode *head = l1, *tail = l1;
		l1 = l1->next;
		while (l2) {
			if (l1 == nullptr) {
				tail->next = l2;
				return head;
			}
			
			if (l2->val < l1->val) {
				ListNode* node = new ListNode(l2->val);
				tail->next = node;
				node->next = l1;
				l2 = l2->next;
				tail = node;
			} else {
				l1 = l1->next;
			    tail = tail->next;
            }
        }
		
        return head;
    }
};
// @lc code=end


/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */

// @lc code=start
//  Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
		if (list1 == nullptr) {
			return list2;
		} else if (list2 == nullptr) {
			return list1;
		}
		if (list1->val > list2->val) {
			return mergeTwoLists(list2, list1);
        }
		ListNode* head = new ListNode(list1->val);
		ListNode* node = head;
		list1 = list1->next;
		while (list1 || list2) {
			if (list1 && (list2 == nullptr || list1->val < list2->val)) {
				node->next = new ListNode(list1->val);
				list1 = list1->next;
				node = node->next;
			} else {
				node->next = new ListNode(list2->val);
				list2 = list2->next;
				node = node->next;
            }
        }
		return head;
    }
};
// @lc code=end


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* lt_tracker = new ListNode{0};
        ListNode* gte_tracker = new ListNode{0};
        
        ListNode* lt_head = lt_tracker;
        ListNode* gte_head = gte_tracker;
        
        while (head != nullptr) {
            if (head->val < x) {
                lt_tracker->next = new ListNode{head->val};
                lt_tracker = lt_tracker->next;
            } else {
                gte_tracker->next = new ListNode{head->val};
                gte_tracker = gte_tracker->next;
            }
            head = head->next;
        }
        
        gte_head = gte_head->next;
        lt_tracker->next = gte_head;
        return lt_head->next;
    }
};
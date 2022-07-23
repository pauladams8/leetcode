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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode** start = &head;
        for (int i = 1; i < left; i++)
            start = &(*start)->next;
        ListNode* node = *start;
        for (int i = left; i < right; i++) {
            ListNode* next = node->next;
            node->next = next->next;
            next->next = *start;
            *start = next;
        }
        return head;
    }
};
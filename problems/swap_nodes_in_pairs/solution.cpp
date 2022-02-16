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
    ListNode* swapPairs(ListNode* head) {
        ListNode *node = head, **pp = &head;
        while (node && node->next) {
            *pp = node->next;
            node->next = node->next->next;
            (*pp)->next = node;
            pp = &node->next;
            node = node->next;
        }
        return head;
    }
};
#include "list_node.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *first = head, *second = head->next, *third = second->next;
        head = second;
        second->next = first;
        first->next = third;
        for (ListNode* node = head->next; node && node->next && node->next->next; node = node->next->next) {
            first = node->next, second = first->next, third = second->next;
            node->next = second;
            second->next = first;
            first->next = third;
        }
        return head;
    }
};
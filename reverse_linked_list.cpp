#include "list_node.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* node = head;
        while (node && node->next) {
            ListNode* next = node->next;
            node->next = next->next;
            next->next = head;
            head = next;
        }
        return head;
    }
};

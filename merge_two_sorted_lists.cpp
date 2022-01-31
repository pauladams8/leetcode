#include "list_node.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head = nullptr, **pp = &head;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                *pp = list1;
                list1 = list1->next;
            } else {
                *pp = list2;
                list2 = list2->next;
            }
            pp = &(*pp)->next;
        }
        *pp = list1 ?: list2;
        return head;
    }
};

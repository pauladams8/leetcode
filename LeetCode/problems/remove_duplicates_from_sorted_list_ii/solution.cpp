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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *dummy = new ListNode(0, head), *node = dummy;
        while (node && node->next && node->next->next) {
            if (node->next->val == node->next->next->val) {
                int val = node->next->val;
                while (node->next && node->next->val == val)
                    node->next = node->next->next;
            } else {
                node = node->next;
            }
        }
        return dummy->next;
    }
};
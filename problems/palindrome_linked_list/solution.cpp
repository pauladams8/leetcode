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
    bool isPalindrome(ListNode* head) {
        ListNode *rev = nullptr;
        for (ListNode* node = head; node; node = node->next) {
            ListNode* copy = new ListNode(*node);
            copy->next = rev;
            rev = copy;
        }
        for (ListNode *a = head, *b = rev; a && b; a = a->next, b = b->next)
            if (a->val != b->val)
                return false;
        return true;
    }
};
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
        ListNode *slow = head, *fast = head, *rev = nullptr;
        while (fast && fast->next) {
            fast = fast->next->next;
            ListNode *next = slow->next;
            slow->next = rev;
            rev = slow;
            slow = next;
        }
        if (fast)
            slow = slow->next;
        while (slow) {
            if (rev->val != slow->val)
                return false;
            rev = rev->next;
            slow = slow->next;
        }
        return true;
    }
};
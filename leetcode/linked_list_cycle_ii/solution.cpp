/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow != fast)
                continue;
            ListNode *pre = head;
            while (pre != slow) {
                pre = pre->next;
                slow = slow->next;
            }
            return pre;
        }
        return 0;
    }
};